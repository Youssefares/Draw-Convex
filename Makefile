#
# Makefile
#
# ConvexHull
# Term 3 Project
#

# compiler
CC = clang

# flags
CFLAGS = -ggdb3 -O0 -Qunused-arguments -std=c99 -Wall -Werror -lcs -lm

# name for .exe file
EXE = drawConvex

# includes <>
LIBS = -lcs -lm

# sources
SRCS = drawConvex.c quicksort.c GrahamScan.c

# includes ""
HDRS = quicksort.h GrahamScan.h

# automatically generated list of object files
OBJS = $(SRCS:.c=.o)


# default target
$(EXE): $(OBJS) $(HDRS) Makefile
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

# dependencies 
$(OBJS): $(HDRS) Makefile

# housekeeping
clean:
	rm -f core $(EXE) *.o
