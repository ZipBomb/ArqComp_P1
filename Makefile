CC = gcc -Wall -O0 -msse3
MAIN = test

SRCS = main.c rutinas_clock.c

DEPS = rutinas_clock.h 

OBJS = $(SRCS:.c=.o)

$(MAIN): $(OBJS)
	rm -f $(MAIN)
	rm -rf objects/
	$(CC) -o $(MAIN) $(OBJS)
	mkdir objects/
	mv *.o objects/

%.o: %.c $(DEPS)
	$(CC) -c $< 

clean:
	rm -f $(MAIN)
	rm -rf objects/
