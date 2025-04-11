all: first
	@echo "All tasks are complete"

first:
	@cd 1 && make all

clean:
	@cd 1 && make clean && cd ..
