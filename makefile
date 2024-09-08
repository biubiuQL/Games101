

.PHONY:clear build run

#项目名字
ProjectName:=Games101
run:
	@make build
	@echo -------------------------------------------------------------------------------
	@./build/${ProjectName}.exe

clear:
	@if exist build del /q build\*

build:
	@if not exist build mkdir build
	@if exist build del /q build\*
	@cmake . -B build -G "MinGW Makefiles" -DProjectName=${ProjectName}
	@cmake --build build

