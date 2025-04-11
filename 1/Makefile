all: first second third
	@echo "First task is complete"

# ------------------------------------------------------------------------------

FILE 					= file.txt
PRIVATE_KEY 			= private_key.pem
PASSWORD 				= my_password
PUBLIC_KEY 				= public_key.pem

first:
	@echo "1.1 Generating key, based on $(FILE), password: $(PASSWORD)"
	openssl genrsa \
	-out $(PRIVATE_KEY) \
	-des3 \
	-rand $(FILE) \
	-passout pass:$(PASSWORD) \
	4096

	@echo "Generating public key, based on secret key"
	openssl rsa \
	-in $(PRIVATE_KEY) \
	-out $(PUBLIC_KEY) \
	-pubout \
	-passin pass:$(PASSWORD)

# ------------------------------------------------------------------------------

FILE_TO_ENCRYPT_DES3	= file_to_encrypt_des3.txt
ENCRYPTED_FILE_DES3		= encrypted_file_des3.txt

FILE_TO_ENCRYPT_RSA		= file_to_encrypt_rsa.txt
ENCRYPTED_FILE_RSA		= encrypted_file_rsa.txt

second:
	@echo "1.2 Ecrypting file $(FILE_TO_ENCRYPT_DES3) to $(ENCRYPTED_FILE_DES3)"
	openssl des3 \
	-in $(FILE_TO_ENCRYPT_DES3) \
	-out $(ENCRYPTED_FILE_DES3) \
	-pass pass:$(PASSWORD)

	@echo "Encrypting file $(FILE_TO_ENCRYPT_RSA) to $(ENCRYPTED_FILE_RSA)"
	openssl rsautl \
	-in $(FILE_TO_ENCRYPT_RSA) \
	-out $(ENCRYPTED_FILE_RSA) \
	-inkey $(PUBLIC_KEY) \
	-pubin -encrypt

# ------------------------------------------------------------------------------

DECRYPTED_FILE_DES3		= decrypted_file_des3.txt
DECRYPTED_FILE_RSA		= decrypted_file_rsa.txt

third:
	@echo "1.3 Decrypting file $(ENCRYPTED_FILE_DES3) to $(DECRYPTED_FILE_DES3)"
	openssl des3 -d \
	-in $(ENCRYPTED_FILE_DES3) \
	-out $(DECRYPTED_FILE_DES3) \
	-pass pass:$(PASSWORD)

	@echo "Decrypting file $(ENCRYPTED_FILE_RSA) to $(DECRYPTED_FILE_RSA)"
	openssl rsautl \
	-in $(ENCRYPTED_FILE_RSA) \
	-out $(DECRYPTED_FILE_RSA) \
	-inkey $(PRIVATE_KEY) \
	-passin pass:$(PASSWORD) \
	-decrypt

# ------------------------------------------------------------------------------

clean:
	@rm -rf $(PRIVATE_KEY) $(PUBLIC_KEY) \
	$(ENCRYPTED_FILE_DES3) $(DECRYPTED_FILE_DES3) \
	$(ENCRYPTED_FILE_RSA) $(DECRYPTED_FILE_RSA)
