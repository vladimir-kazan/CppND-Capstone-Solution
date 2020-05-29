DEBUG_DEST := debug
RELEASE_DEST := build
CMAKE_TOOLCHAIN_FILE := ${VCPKG}/scripts/buildsystems/vcpkg.cmake
$(info Using toolchain file: ${CMAKE_TOOLCHAIN_FILE})

clean:
	rm -rf debug/
	rm -rf build/

run:
	@$(RELEASE_DEST)/game

release: | $(RELEASE_DEST)
	@cd $(RELEASE_DEST) && make

$(RELEASE_DEST):
	@mkdir -p $@
	@cd $@ && cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE} ..

dev: build-dev
	@$(DEBUG_DEST)/game

build-dev: | $(DEBUG_DEST)
	@cd $(DEBUG_DEST) && make

$(DEBUG_DEST):
	@mkdir -p $@
	@cd $@ && cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE} ..

# LLVM, Google, Chromium, Mozilla, WebKit
format:
	find src -name '*[.cpp]' -type f -o -name '*[.h]' -type f | xargs clang-format --style=Chromium --verbose -i

.PHONY: clean release run build-dev dev format ${DEBUG_DEST} ${RELEASE_DEST}
