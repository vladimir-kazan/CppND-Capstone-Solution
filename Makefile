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
	@cd $@ && cmake -DCMAKE_BUILD_TYPE=Debug ..

format:
	clang-format -i src/*

.PHONY: clean release run build-dev dev format
