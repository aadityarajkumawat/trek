CFLAGS = -O
CC = g++
trek: main.o fs.o path.o utils.o init.o
	$(CC) $(CFLAGS) -o trek main.o fs.o path.o utils.o init.o
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp
fs.o: fs.cpp
	$(CC) $(CFLAGS) -c fs.cpp
path.o: path.cpp
	$(CC) $(CFLAGS) -c path.cpp
utils.o: utils.cpp
	$(CC) $(CFLAGS) -c utils.cpp
init.o: init.cpp
	$(CC) $(CFLAGS) -c init.cpp
clean:
	rm -f core *.o
