.PHONY: clean build-dev build run run-dev

clean:
	rm -rf debug/
	rm -rf build/

build-dev:
	mkdir -p debug
	cd debug \
	&& cmake -DCMAKE_BUILD_TYPE=Debug .. \
	&& make

build:
	mkdir -p build
	cd build \
	&& cmake -DCMAKE_BUILD_TYPE=Release .. \
	&& make

run:
	@build/game

run-dev:
	@debug/game

.PHONY: dev
dev: build-dev run-dev

.PHONY: format
format:
	clang-format -i src/*
