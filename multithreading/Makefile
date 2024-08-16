# Directories
SRC_DIR := src
INCLUDE_DIR := include
BUILD_DIR := build

# compiler flags
CC := g++
CFLAGS := -I$(INCLUDE_DIR) -Wall -Wextra

#source files
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)

#object files
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))

#Output executable
TARGET := multithreading

#Default target
all: $(TARGET)

#Rule to link and create the executables
$(TARGET): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $@

#Rule to compile each .cpp file into an object file

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

#create the build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# clean build directories

clean:
	rm -rf $(BUILD_DIR) $(TARGET)





