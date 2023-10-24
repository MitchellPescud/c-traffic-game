CC = gcc
CFLAGS = -Wall -pedantic -ansi -Werror
OBJ = main.o gameboard.o freeMemory.o obstacleMovement.o playerMovement.o printBoard.o terminal.o linkedList.o
EXEC = traffic

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : main.c gameboard.h freeMemory.h obstacleMovement.h playerMovement.h printBoard.h terminal.h linkedList.h
	$(CC) -c main.c $(CFLAGS)

gameboard.o : gameboard.c gameboard.h
	$(CC) -c gameboard.c $(CFLAGS)

freeMemory.o : freeMemory.c freeMemory.h
	$(CC)  -c freeMemory.c $(CFLAGS)

obstacleMovement.o : obstacleMovement.c obstacleMovement.h
	$(CC) -c obstacleMovement.c $(CFLAGS)

playerMovement.o : playerMovement.c playerMovement.h
	$(CC) -c playerMovement.c $(CFLAGS)

printBoard.o : printBoard.c printBoard.h
	$(CC) -c printBoard.c $(CFLAGS)

terminal.o : terminal.c terminal.h
	$(CC) -c terminal.c $(CFLAGS)

linkedList.o : linkedList.c linkedList.h
	$(CC) -c linkedList.c $(CFLAGS)

clean:
	rm -f $(EXEC) $(OBJ)
	