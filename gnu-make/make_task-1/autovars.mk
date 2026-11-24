TARGET=app
all: $(TARGET) main.o src1.o

$(TARGET): main.c src1.c
	cc -o $@ -c $^ 

%.o: %.c
	cc -c $<

clean:
	@rm ./*.o
	@rm ./app
