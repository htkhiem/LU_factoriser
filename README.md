# Matrix LU Factoriser

A small program that factorises a given matrix into a product of upper-triangular and lower-triangular matrices (A = L x U), using either Doolittle's or Crout's method.
This program is mainly written to test my matrix algorithms, which might be packed into a separate library and posted on its own repo in the near future.
## Input format

This program reads from a text (.txt) file, placed in the same location as the executable file, for ease of input. The file can be freely named (the program will ask for the file name upon startup). The file must be formatted as follows:

    \<size> \<method>
    elem1,1 elem1,2 ... elem1,size
    elem2,1 elem2,2 ... elem2,size
    ...
    elemsize,1 elemsize,2 ... elemsize,size

 - **size:** a number, specifying the (square) matrix's size.
 - **method:** a character that specifies which method to use, which can be either `d` (Doolittle) or `c` (Crout).
 - **elemx,x:** elements of the input matrix, separated by spaces. Each row is written in its own line.
 ### Example input file:
A 3x3 matrix, with Doolittle's method chosen.

     3 d
    2 -3 5
    3 -4 7
    4 -3 9
Running the program with the above example will result in the following console output:

    A = L x U
    A =
    2 -3 5
    3 -4 7
    4 -3 9
    
    L =
    1 0 0
    1.5 1 0
    2 0.75 1
    
    U =
    2 -3 5
    0 -4 7
    0 0 -6.25
The program first repeats the input, then prints the two factorised products.
