

.PHONY:clear build run

#项目名字
ProjectName:=Games101
run:
	@make build
	@echo -------------------------------------------------------------------------------
	@./build/${ProjectName}.exe

clear:
	@if exist build rmdir /s /q build

build:
	@if exist build rmdir /s /q build
	@if not exist build mkdir build
	@cmake . -B build -G "MinGW Makefiles" -DProjectName=${ProjectName}
	@cmake --build build

