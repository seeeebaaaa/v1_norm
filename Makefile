
CC = clang++
GEN_FLAGS = -std=c++20
SOURCES := $(shell find . -regex '.*[a-zA-Z0-9_/\-]\.cc*' )
EXEC_NAME = output
ASSET_PATH = ./assets/
ASSET_LIST := $(shell find $(ASSET_PATH) -regex '.*[a-zA-Z0-9_/\-]\.obj*' )

BREW_INCLUDE_PATH := -I/opt/homebrew/include
LIBPNG_INCLUDE := $(shell libpng-config --ldflags)

all: $(EXEC_NAME)

# this compiles all assets into c headers called obj_name.h; IGNORE FOR NOW
compiled_assets/: $(ASSET_LIST)
	mkdir compiled_assets; \
	for file in $(ASSET_LIST); do \
		file_name=$$(echo $$file | sed 's/.[a-zA-Z0-9_\/]*\///' | sed 's/.obj//'); \
		echo "reached"; \
		echo $$file_name; \
		xxd -i $$file > compiled_assets/obj_$$(echo $$file_name).h; \
	done

$(EXEC_NAME): $(SOURCES) compiled_assets/
	$(CC) $(GEN_FLAGS) $(BREW_INCLUDE_PATH) $(LIBPNG_INCLUDE) $(SOURCES) -Wall -o $(EXEC_NAME)

debug: $(SOURCES) compiled_assets/
	$(CC) $(GEN_FLAGS) $(BREW_INCLUDE_PATH) $(LIBPNG_INCLUDE) $(SOURCES) -g -o debug_$(EXEC_NAME)

# counts the number of lines in this project
lines: $(shell find . -regex '.*[a-zA-Z0-9\.\_\/\-]\.[c|h]*[c|h]')
	cat $(shell find . -regex '.*[a-zA-Z0-9\.\_\/\-]\.[c|h]*[c|h]') | wc -l

clean:
	rm -f $(EXEC_NAME)
	rm -f debug_$(EXEC_NAME)
	rm -fr $(EXEC_NAME).dSYM
	rm -fr debug_$(EXEC_NAME).dSYM