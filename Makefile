CC=gcc 
CFLAGS=-Wall -g
FILES=main.o list.o item.o node.o

all: main.out 

main.out: $(FILES)
	$(CC) $(CFLAGS) -o $@ $^

# @ : nome della regola 
# ^ : prende tutto ciò che è alla prima riga dopo la regola

main.o: main.c list.h
	$(CC) $(CFLAGS) -c $<

node.o: node.c node.h
	$(CC) $(CFLAGS) -c $<

list.o: list.c list.h node.h
	$(CC) $(CFLAGS) -c $<

# < : prende solo la prim occorrenza dopo i due punti 
# della regola 

item.o: item.c item.h
	$(CC) $(CFLAGS) -c $<

clean: 
	rm *.o *.out
