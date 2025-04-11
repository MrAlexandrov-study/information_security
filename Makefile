all: first second third
	@echo "All tasks are complete"

first:
	@echo "====================================================================="
	@cd 1 && make all

second:
	@echo "====================================================================="
	@cd 2 && make all

third:
	@echo "====================================================================="
	@cd 3 && make all

clean:
	@cd 1 && make clean
	@cd 2 && make clean
	@cd 3 && make clean
