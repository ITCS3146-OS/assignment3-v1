main.o: main.c
	gcc -c main.c
app: main.o
	gcc main.o -o app
launch: app
	./app