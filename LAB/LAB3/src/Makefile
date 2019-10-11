CC = g++
CFLAGS = -std=c++11
SRC = selection.cpp insertionSort.cpp selectionSort.cpp  bubbleSort.cpp mergeSort.cpp  quickSort.cpp main.cpp basic_operations.cpp 
NAME = main
.PHONY: clean
all: $(NAME)

$(NAME):$(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	$(RM) *.o  $(NAME)
