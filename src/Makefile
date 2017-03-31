CC=gcc
LN=ln
SF=-sf
CFLAGS=-lpthread -fPIC -Wall -g -c
LFLAGS=-g -shared -Wl,-soname,
LIBS=-L. -lmyio
LIBTARGET=libmyio.so
LIBTARGET0=$(LIBTARGET:.so=.so.0.0)
PWD=$$PWD

SRCS=pid1.c pid2.c
OBJS=$(SRCS:.c=.o)

.SUFFIXES:.c.o
.c.o:
	$(CC) $(CFLAGS) $(SRCS)


all: PID

PID: main.o $(LIBTARGET)
	$(CC) $(LFLAGS)$(LIBTARGET) -o $(LIBTARGET0) $(OBJS) -lc
	$(CC) -o $@ main.c $(LIBS)
	@echo $(PWD) >> /etc/ld.so.conf.d/my.conf
	$ ldconfig
	@echo done

$(LIBTARGET): $(OBJS)
	$(LN) $(SF) $(LIBTARGET0) $@

clean:
	rm -rf PID *.o $(LIBTARGET)
