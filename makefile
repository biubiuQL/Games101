

.PHONY: all clean

clean:
	@rm -rf build

cmake_build:
	@make clean
	@mkdir 
	mkdir build && cd build && cmake .. && make

run:
	./main.exe