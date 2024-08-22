CC=g++

CFLAGS=-c -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wmissing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -D_DEBUG -D_EJUDGE_CLIENT_SIDE -D_EJC

LDFLAGS=

SRC_DIR=src
SOURCES=$(patsubst $(SRC_DIR)/%, %, $(wildcard $(SRC_DIR)/*.cpp))

OBJ_DIR=objects
OBJECTS=$(SOURCES:%.cpp=$(OBJ_DIR)/%.o)

HEADERS_DIR=include
HEADERS=$(wildcard $(HEADERS_DIR)/*.h)

EXECUTABLE=quad.exe

all: $(OBJ_DIR) info $(EXECUTABLE)
	$(info Done)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	@$(CC) -I$(HEADERS_DIR) $(CFLAGS) $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

info:
	$(info Compiling...)


clean:
	rm -rf $(OBJ_DIR)/*.o $(EXECUTABLE)
