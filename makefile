all: compile run

compile: driver2.cpp tetromino.h tetromino.cpp tetris.cpp tetris.h
	@echo "-------------------------------------------"
	@echo "Compiling.."
	@g++ driver2.cpp  tetromino.cpp tetris.cpp -o main
	@g++ driver1.cpp  tetromino.cpp tetris.cpp -o test

run:
	@echo "-------------------------------------------"
	@echo "Running the tests.."
	@echo "============================================================="
	./test
	./main
	
	@echo "============================================================="
	@echo "Completed tests.."
