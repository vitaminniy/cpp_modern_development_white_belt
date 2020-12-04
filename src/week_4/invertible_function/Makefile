all: clean build

BUILD_DIR=build

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)

.PHONY: build
build:
	if [ ! -d $(BUILD_DIR) ]; then mkdir -p $(BUILD_DIR); fi
	cd $(BUILD_DIR) && cmake ../ && $(MAKE)

.PHONY: run
run: build
	cd $(BUILD_DIR) && ./invertible_function
