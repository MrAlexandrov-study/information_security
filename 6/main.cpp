#include <iostream>
#include <numeric>

namespace {

// Функция для нахождения модульного обратного, основанная на расширенном алгоритме Евклида
int InverseMod(int e, int phi) {
    int x0 = 0;
    int x1 = 1;
    int phi0 = phi;
    int temp = 0;

    while (e > 1) {
        int div = e / phi;
        temp = phi;
        phi = e % phi;
        e = temp;
        temp = x0;
        x0 = x1 - div * x0;
        x1 = temp;
    }

    if (x1 < 0) {
        x1 += phi0;
    }

    return x1;
}

// Функция для возведения в степень по модулю
int PowerMod(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

}  // namespace

int main() {
    // Используем небольшие простые числа для наглядности
    constexpr int p = 61; // Простое число
    constexpr int q = 53; // Простое число

    constexpr int n = p * q; // Модуль
    constexpr int phi = (p - 1) * (q - 1);

    constexpr int e = 17; // Публичная экспонента, которая взаимно проста с phi и меньше phi

    // Проверяем, чтобы e и phi были взаимно простыми
    static_assert(std::gcd(e, phi) == 1);

    // Находим приватную экспоненту (d)
    int d = InverseMod(e, phi);

    // Выводим открытый и закрытый ключи
    std::cout << "Public Key: (" << e << ", " << n << ")\n";
    std::cout << "Private Key: (" << d << ", " << n << ")\n";

    // Шифрование и дешифрование
    int message = 42; // Это наше исходное сообщение
    int encrypted = PowerMod(message, e, n);
    int decrypted = PowerMod(encrypted, d, n);

    // Результаты
    std::cout << "Original Message: " << message << "\n";
    std::cout << "Encrypted Message: " << encrypted << "\n";
    std::cout << "Decrypted Message: " << decrypted << "\n";

    return 0;
}
