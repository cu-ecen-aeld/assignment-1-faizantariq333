CROSS_COMPILE ?=  


objects := writer.o
exe := writer

ifdef CROSS_COMPILE
	CC := $(CROSS_COMPILE)gcc
else
	CC := gcc
endif

all : clean writer

$(exe) : $(objects)
	$(CC) -o writer writer.o

writer.o : writer.c 
	$(CC) -c writer.c

clean : 
	rm $(exe) || true
	rm $(objects) || true
