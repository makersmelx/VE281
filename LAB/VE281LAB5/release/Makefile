CC = g++
CFLAGS = -O3 -std=c++11
SRC = main.cpp graph.cpp interface.cpp
NAME = main
.PHONY: clean
all: $(NAME)

$(NAME):$(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	$(RM) *.o  $(NAME)
