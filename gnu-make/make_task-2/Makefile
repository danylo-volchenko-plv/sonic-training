TARGET=app

all: $(TARGET)

$(TARGET): main.o src1.o src2.o src3.o
	cc -o $(TARGET) $^

%.o: %.c
	cc -c $<

others:
	$(MAKE) -f make1.mk
	$(MAKE) -f make2.mk
	$(MAKE) -f make3.mk

include make1.mk make2.mk make3.mk

othersinc: all

clean:
	rm -f ./*.o ./app
