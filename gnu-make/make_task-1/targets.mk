all: app main.o src1.o

app: main.c src1.c
	cc -o app main.c src1.c

main.o: main.c
	cc -c main.c

src1.o: src1.c
	cc -c src1.c

clean:
	@rm ./*.o
	@rm ./app
