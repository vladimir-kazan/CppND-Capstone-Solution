DEBUG_DEST = debug
RELEASE_DEST = build

clean:
	rm -rf debug/
	rm -rf build/

run:
	@$(RELEASE_DEST)/game

release: $(RELEASE_DEST)
	@cd $(RELEASE_DEST) && make

$(RELEASE_DEST):
	@mkdir -p $@
	@cd $@ && cmake -DCMAKE_BUILD_TYPE=Release ..

dev: build-dev
	@$(DEBUG_DEST)/game

build-dev: | $(DEBUG_DEST)
	@cd $(DEBUG_DEST) && make

$(DEBUG_DEST):
	@mkdir -p $@
	@cd $@ && cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=/Users/vku/bin/vcpkg/scripts/buildsystems/vcpkg.cmake ..

# LLVM, Google, Chromium, Mozilla, WebKit
format:
	clang-format --style=Chromium -i src/*.h src/*.cpp

.PHONY: clean release run build-dev dev format
