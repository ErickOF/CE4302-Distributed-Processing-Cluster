.PONY: build run all

BUILD_DIR=bin
WEB_SERVER_DIR=web_server
APP=web_server

build:
	@if [ ! -d ${BUILD_DIR} ]; then \
		mkdir ${BUILD_DIR}; \
	fi
	@gcc -o ${BUILD_DIR}/${APP} ${WEB_SERVER_DIR}/${APP}.c

run:
	@./${BUILD_DIR}/${APP}

all:
	@make build
	@make run
