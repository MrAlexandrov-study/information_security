all: first second third
	@echo "First task is complete"

# ------------------------------------------------------------------------------

FILE 					= file.txt
KEY_FILE 				= key.pem
PASSWORD 				= my_password
PUBLIC_KEY 				= pubkey.pem

first:
	@echo "1.1 Generating key, based on $(FILE), password: $(PASSWORD)"
	openssl genrsa -out $(KEY_FILE) -des3 -rand $(FILE) -passout pass:$(PASSWORD) 4096

	@echo "Generating public key, based on secret key"
	openssl rsa -in $(KEY_FILE) -out $(PUBLIC_KEY) -pubout -passin pass:$(PASSWORD)

# ------------------------------------------------------------------------------

FILE_TO_ENCRYPT			= file_to_encrypt.txt
ENCRYPTED_FILE			= encrypted_file.txt

second:
	@echo "1.2 Ecrypting file $(FILE_TO_ENCRYPT) to $(ENCRYPTED_FILE)"
	openssl des3 -in $(FILE_TO_ENCRYPT) -out $(ENCRYPTED_FILE) -pass pass:$(PASSWORD)

# ------------------------------------------------------------------------------

DECRYPTED_FILE			= decrypted_file.txt

third:
	@echo "1.3 Decrypting file $(ENCRYPTED_FILE) to $(DECRYPTED_FILE)"
	openssl des3 -d -in $(ENCRYPTED_FILE) -out $(DECRYPTED_FILE) -pass pass:$(PASSWORD)

# ------------------------------------------------------------------------------

clean:
	@rm -rf $(KEY_FILE) $(PUBLIC_KEY) $(ENCRYPTED_FILE) $(DECRYPTED_FILE)
