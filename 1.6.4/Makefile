PROG = main
CC = gcc
CFLAGS = -Wall -ggdb3 -O0 -std=c99
LDFLAGS = -lm
OBJS = main.o


$(PROG) : $(OBJS) 
	$(CC) $(LDFLAGS) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJS) $(PROG)
