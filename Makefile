all:
	@if not exist build mkdir build
	gcc src/main.c include/vector.c -Iinclude -o build/main.exe

run:
	@build/main.exe

clean:
	@if exist build\main.exe del /f build\main.exe