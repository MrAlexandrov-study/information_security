all: first
	@echo "Second task is complete!"

FILE 					= file.txt
PASSWORD 				= my_password
PRIVATE_KEY 			= private_key.pem
PUBLIC_KEY 				= public_key.pem
FILE_TO_SIGN			= file_to_sign.txt
HASH_FILE				= hash_file.txt
SIGNATURE				= file_to_sign.sig
SERTIFICATE				= sertificate.csr
SELF_SIGNED_CERT		= self_signed_cert.csr

first:
	@echo "--------------------------------------------------------------------"
	@echo "2. Signing file"

	@echo "...................................................................."
	@echo "Generating private key"
	@openssl genrsa \
	-out $(PRIVATE_KEY) \
	-des3 \
	-rand $(FILE) \
	-passout pass:$(PASSWORD) \
	4096

	@echo "...................................................................."
	@echo "Generating public key"
	@openssl rsa \
	-in $(PRIVATE_KEY) \
	-out $(PUBLIC_KEY) \
	-pubout \
	-passin pass:$(PASSWORD)

	@echo "...................................................................."
	@echo "Counting hash"
	@openssl dgst \
	-sha256 \
	-out $(HASH_FILE) \
	$(FILE_TO_SIGN)

	@echo "...................................................................."
	@echo "Creating signature"
	@openssl dgst \
	-sha256 \
	-sign $(PRIVATE_KEY) \
	-out $(SIGNATURE) \
	-passin pass:$(PASSWORD) \
	$(FILE_TO_SIGN)

	@echo "...................................................................."
	@echo "Verifying signature"
	@openssl dgst \
	-sha256 \
	-verify $(PUBLIC_KEY) \
	-signature $(SIGNATURE) \
	-passin pass:$(PASSWORD) \
	$(FILE_TO_SIGN)

	@echo "...................................................................."
	@echo "Generating CSR"
	@openssl req \
	-new \
	-key $(PRIVATE_KEY) \
	-out $(SERTIFICATE) \
	-passin pass:$(PASSWORD) \
	-subj "/C=RU/ST=MO/L=Moscow/O=BMSTU/OU=RK6/CN=Certificate"

	@echo "...................................................................."
	@echo "Generating self-signed certificate"
	@openssl x509 \
	-req \
	-in $(SERTIFICATE) \
	-signkey $(PRIVATE_KEY) \
	-out $(SELF_SIGNED_CERT) \
	-days 1 \
	-passin pass:$(PASSWORD)

clean:
	@rm -rf $(PRIVATE_KEY) $(PUBLIC_KEY) $(HASH_FILE) $(SIGNATURE) $(SERTIFICATE) $(SELF_SIGNED_CERT)
