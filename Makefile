BUILD_DIR = build

clean:
	rm -rf ${BUILD_DIR}
.PHONY: clean

build: clean
	mkdir ${BUILD_DIR}
	cd ${BUILD_DIR} && cmake ..
	cd ${BUILD_DIR} && make
.PHONY: build
