OBJS	:=	$(addsuffix	.o,	hash_table)

all:	$(OBJS)
	clang++	$(OBJS)	-g	htable.cpp	-o	prog1

%.o:	%.cpp
	clang++	-c	$<

clean:
	rm	-f	*.o	prog1
