

.PHONY: all clean cmake_build run

ifeq ($(OS),Windows_NT)
    rm = rmdir /S /Q build
else
    rm = rm -rf
endif

run:
	@make cmake_build
#	./main.exe

cmake_build:
	@${rm} build
	@echo 1
	@mkdir build
	@echo 2
#	@cmake . -B build -G "MinGW Makefiles"
#	@cmake --build build

