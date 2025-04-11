all: first
	@echo "Third task is complete"

FILE_TO_COUNT_HASH		= file_to_count_hash.txt

first:
	@echo "3. Countng hash of file $(FILE_TO_COUNT_HASH)"
	@openssl md5 -c $(FILE_TO_COUNT_HASH)
	@openssl sha1 $(FILE_TO_COUNT_HASH)

clean:
	@/bin/true
