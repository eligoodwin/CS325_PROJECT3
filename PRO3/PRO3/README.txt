CS 325: Project 3, Group 29
Eli Goodwin
Benjamin Tate
Carlos La Hoz Daniels

GENERAL INFO: 
This program is intended to solve the Travelling Salesman Problem as well 
as possible, and as quickly as possible. It does so by using the Christofides 
approximation algorithm, which guarantees a resulting tour length of no
more than 50% greater than the optimal tour, and the 2-opt algorithm, which
is designed to take a valid tour that has already been found and try to 
improve it by finding a shorter tour. A time limit can also be set to ensure
that 2-opt doesn't cause the the program to run too long. It can also run
using the nearest neighbor algorithm, but doing so will result in longer
tours

COMPILING: 
To compile, navigate to the directory that contains the Makefile, and run
	make clean
and then
	make main 

HOW TO RUN:
The general format for the run command is as follows:
	./main [input_file] [alg_options]
where input_file is the name of the file that contains the graph of cities, 
and alg_options is a number from 1 to 3 that determines what algorith(s) will
be used. If alg_options=1, nearest neighbor will be used, if alg_options=2,
Christofides will be used along with 2-opt, and if alg_options=3, only 
Christofides will be used. In any other case, only nearest neighbor will be
used. If you wish to guarantee that run time will not exceed 3 minutes, use 
option 2 for alg_options. This is the option we used for the competition instances and the scores documented in our report.
