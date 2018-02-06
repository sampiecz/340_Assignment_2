#
# PROGRAM: Assign 2   
# PROGRAMMER: Samuel Piecz 
# LOGON ID: Z1732715 
# DATE DUE: 02/5/18 
#
# Compiler variables
CCFLAGS = -ansi -Wall -std=c++11

# Rule to link object code files to create executable file
assignment2: assignment2.o
	g++ $(CCFLAGS) -o assignment2 assignment2.o

# Rule to compile source code file to object code
assignment2.o: assignment2.cc
	g++ $(CCFLAGS) -c assignment2.cc

# Pseudo-target to remove object code and executable files
clean:
	-rm -f *.o assignment2
