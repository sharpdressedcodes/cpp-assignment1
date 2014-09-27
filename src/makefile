#
# This is a simple makefile for the complex data type example
# When you learn more about make and makefiles you will discover
# that it is possible to write considerably more 'concise' makefiles.
#
# A fully annotated version of the makefile can be found in
# 'makefile.annotated'
#

all: main.o complex.o
	g++ -o complex-main main.o complex.o
main.o: main.cpp complex.h
	g++ -Wall -ansi -pedantic -c main.cpp
complex.o: complex.cpp complex.h
	g++ -Wall -ansi -pedantic -c complex.cpp

#
# The End
# 
