CXX := clang++

CXXFLAGS := -std=c++17 -Wall -Wextra

# Add linker flags here in case of external libraries
CXXFLAGS_EXTRA_COMPILE := `./external/wxWidgets-3.2.4/macbuild/wx-config --cxxflags`
CXXFLAGS_EXTRA_LINK := `./external/wxWidgets-3.2.4/macbuild/wx-config --libs`

APP_NAME := $(notdir $(shell pwd))

BUILD_DIR := ./build

BIN_DIR := ./bin

INCLUDE_DIR := -Iinclude

# SOURCE_FILES := $(shell find . -name "*.cpp")
SOURCE_FILES := $(wildcard *.cpp) $(notdir $(wildcard **/*.cpp))


OBJECT_FILES := $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(notdir $(SOURCE_FILES)))

DEPENDENCY_FILES := $(OBJECT_FILES:.o=.d)


.PHONY: clean all source object

vpath %.cpp ./include

all: $(BIN_DIR)/$(APP_NAME)
	@$(BIN_DIR)/./$(APP_NAME)

$(BIN_DIR)/$(APP_NAME): $(OBJECT_FILES)
	@$(CXX) $(CXXFLAGS) -o $@ $^ $(CXXFLAGS_EXTRA_LINK)

$(OBJECT_FILES): $(BUILD_DIR)/%.o : %.cpp | $(BIN_DIR) $(BUILD_DIR)
	@$(CXX) $(CXXFLAGS) $(CXXFLAGS_EXTRA_COMPILE) -c $< -MMD -o $@


# just to check if correct files are selected
source:
	@echo $(SOURCE_FILES)

# just to check if object files are being generated in the correct location
object:
	@echo $(OBJECT_FILES)
# check final executable name
name:
	@echo $(APP_NAME)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)


-include $(DEPENDENCY_FILES)

clean:
	rm -rf ./build ./bin