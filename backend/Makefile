# Makefile for Monthly Budget Tracker

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I./src
TARGET = budget_tracker
SRC_DIR = src
BUILD_DIR = build
DATA_DIR = ../data

# Source files
SOURCES = $(SRC_DIR)/main.cpp
HEADERS = $(SRC_DIR)/User.h $(SRC_DIR)/Income.h $(SRC_DIR)/Expense.h $(SRC_DIR)/Budget.h $(SRC_DIR)/FileHandler.h

# Default target
all: setup $(TARGET)

# Create necessary directories
setup:
	@if not exist "$(BUILD_DIR)" mkdir "$(BUILD_DIR)"
	@if not exist "$(DATA_DIR)" mkdir "$(DATA_DIR)"

# Build the executable
$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(BUILD_DIR)/$(TARGET).exe

# Run the program
run: $(TARGET)
	@cd $(BUILD_DIR) && $(TARGET).exe

# Clean build files
clean:
	@if exist "$(BUILD_DIR)" rmdir /s /q "$(BUILD_DIR)"
	@echo Cleaned build directory

# Rebuild
rebuild: clean all

.PHONY: all setup run clean rebuild
