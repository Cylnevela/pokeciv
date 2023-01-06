

HEADERS:=$(shell find src -type f -name '*.h')

all: | clean extern configure build

clean:
	@rm -rf bin build

distclean: clean
	@rm -rf bin

configure:
	@mkdir -p build 
	@cd build && cmake ..

build: bin/client 

bin/client:
	@make -s -j4 -C build client

bin/server:
	@make -s -j4 -C build server

test:
	docker build -t plt-initial -f docker/plt-initial .
	./docker/validate.sh plt-test
	./docker/run_docker_bash.sh plt-test

.PHONY: configure build clean extern test 
