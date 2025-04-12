#include <iostream>
#include <openssl/bn.h>

class TBigNumber {
public:
    TBigNumber() : bn_(BN_new()) {
        if (!bn_) throw std::runtime_error("Failed to create BIGNUM");
    }

    ~TBigNumber() {
        if (bn_) {
            BN_free(bn_);
        }
    }

    BIGNUM* get() const {
        return bn_;
    }

    operator BIGNUM*() const {
        return bn_;
    }

private:
    BIGNUM* bn_;
};

class TBN_CTX {
public:
    TBN_CTX() : ctx_(BN_CTX_new()) {
        if (!ctx_) throw std::runtime_error("Failed to create BN");
    }

    ~TBN_CTX() {
        if (ctx_) {
            BN_CTX_free(ctx_);
        }
    }

    BN_CTX* get() const {
        return ctx_;
    }

    operator BN_CTX*() const {
        return ctx_;
    }

private:
    BN_CTX* ctx_;
};

int main() {
    try {
        TBigNumber p;
        TBigNumber g;
        TBigNumber a;
        TBigNumber b;
        TBigNumber A;
        TBigNumber B;
        TBigNumber shared_key_A;
        TBigNumber shared_key_B;

        TBN_CTX ctx;

        // Определяем простое число p и основание g
        BN_set_word(p, 9001);  // Например, 9001
        BN_set_word(g, 5);   // Например, 5

        // Генерируем приватные ключи a и b
        BN_rand(a, 256, -1, 0);  // Приватные ключи a и b могут быть случайными числами
        BN_rand(b, 256, -1, 0);

        // Вычисляем открытые ключи A = g^a mod p и B = g^b mod p
        BN_mod_exp(A, g, a, p, ctx);
        BN_mod_exp(B, g, b, p, ctx);

        // Вычисляем общий секретный ключ (shared secret)
        // Сторона A будет вычислять (B^a mod p)
        BN_mod_exp(shared_key_A, B, a, p, ctx);
        // Сторона B будет вычислять (A^b mod p)
        BN_mod_exp(shared_key_B, A, b, p, ctx);

        // Выводим общий секретный ключ для проверки
        std::cout << "Shared key (computed by A): " << BN_bn2dec(shared_key_A.get()) << "\n";
        std::cout << "Shared key (computed by B): " << BN_bn2dec(shared_key_B.get()) << "\n";
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
        return 1;
    }
    return 0;
}
