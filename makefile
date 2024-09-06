

.PHONY:clear cmake_build run

#项目名字
ProjectName:=main
run:
	@make cmake_build
	@echo -------------------------------------------------------------------------------
	@./build/${ProjectName}.exe

clear:
	@if exist build del /q build\*

cmake_build:
	@if not exist build mkdir build
	@if exist build del /q build\*
	@cmake . -B build -G "MinGW Makefiles" -DProjectName=${ProjectName}
	@cmake --build build

