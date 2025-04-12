all: first second third fifth sixth
	@echo "All tasks are complete!!!"

first:
	@echo "===================================================================="
	@cd 1 && make all

second:
	@echo "===================================================================="
	@cd 2 && make all

third:
	@echo "===================================================================="
	@cd 3 && make all

fifth:
	@echo "===================================================================="
	@cd 5 && make all

sixth:
	@echo "===================================================================="
	@cd 6 && make all

install:
	sudo apt-get update
	sudo apt-get install -y cmake clang ninja-build libssl-dev

clean:
	@cd 1 && make clean
	@cd 2 && make clean
	@cd 3 && make clean
	@cd 5 && make clean
	@cd 6 && make clean

.PHONY:
	all first second third fifth sixth install clean
