PROJECT_NAME = project_template

INPUT_FILE = input.txt
OUTPUT_FILE = output.txt

NPROCS ?= $(shell nproc)

BUILD_DIR = build

all: run

build:
	@echo "--------------------------------------------------------------------"
	@echo "==> Configuring the project_template..."
	@cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -B$(BUILD_DIR) -H.
	@echo "==> Building the project_template..."
	@cmake --build $(BUILD_DIR) -j $(NPROCS)

run: build
	@echo "==> Running ${PROJECT_NAME}"
	@${BUILD_DIR}/${PROJECT_NAME} > ${OUTPUT_FILE}

clean:
	@echo "==> Cleaning up..."
	@rm -rf $(BUILD_DIR)

rebuild: clean build

install:
	sudo apt-get update
	sudo apt-get install -y cmake clang ninja-build libssl-dev

.PHONY: all build clean rebuild install
