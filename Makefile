BUILD_DIR   = bin/
CC          = g++
CFLAGS      = -Wall -Werror -Iinclude -Ilib -o2 -std=c++17
SO_CFLAGS   = -fPIC
LDFLAGS     = -shared
LIB         = libet
STATIC      = $(BUILD_DIR)$(LIB).a
SHARED_LIB  = $(BUILD_DIR)$(LIB).so
SRC         = $(wildcard src/**/*.cpp)
OBJ         = $(SRC:.cpp=.o)
TEST_CFLAGS = -static -Lbin/ -let
TEST_EXEC   = $(LIB)_tests
TEST_SRC    = $(wildcard test/*.cpp)
TEST_OBJ    = $(TEST_SRC:.cpp=.o)

.PHONY: all
all: $(STATIC) $(SHARED_LIB)

$(SHARED_LIB): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $(addprefix $(BUILD_DIR), $(notdir $^))

$(STATIC): $(OBJ)
	$(AR) $(ARFLAGS) $@ $(addprefix $(BUILD_DIR), $(notdir $^))

%.o: %.cpp build
	$(CC) $(CFLAGS) $(SO_CFLAGS) -c -o $(BUILD_DIR)$(notdir $@) $<

build:
	mkdir -p $(BUILD_DIR)

test: $(STATIC) $(TEST_OBJ)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)$(TEST_EXEC) \
	$(addprefix $(BUILD_DIR), $(notdir $(TEST_OBJ))) $(TEST_CFLAGS)

docs:
	@doxygen docs/doxygen.config

.PHONY: clean
clean:
	rm -fr $(BUILD_DIR)*