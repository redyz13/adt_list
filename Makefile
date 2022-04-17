CC=gcc 
CFLAGS=-Wall -g -Iinclude
BIN=main.o list.o item.o node.o

SRC_PATH=src
INCLUDE_PATH=include
BIN_PATH=bin

all: main.out 

main.out: $(BIN)
	$(CC) $(CFLAGS) -o $@ $(BIN_PATH)/*.o

main.o: $(SRC_PATH)/main.c $(INCLUDE_PATH)/list.h
	$(CC) $(CFLAGS) -c $< -o $(BIN_PATH)/$@

node.o: $(SRC_PATH)/node.c $(INCLUDE_PATH)/node.h
	$(CC) $(CFLAGS) -c $< -o $(BIN_PATH)/$@

list.o: $(SRC_PATH)/list.c $(INCLUDE_PATH)/list.h $(INCLUDE_PATH)/node.h
	$(CC) $(CFLAGS) -c $< -o $(BIN_PATH)/$@

item.o: $(SRC_PATH)/item.c $(INCLUDE_PATH)/item.h
	$(CC) $(CFLAGS) -c $< -o $(BIN_PATH)/$@

clean: 
	rm $(BIN_PATH)/*.o *.out
