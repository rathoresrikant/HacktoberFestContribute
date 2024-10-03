# BST
Implementation of a Binary Search Tree in java with some interesting methods: nth element, position of an element, ABB median, check if it is full, and a String by level visit string.
## Prerequisites
If you do not have java installed on your computer, type the command in the terminal `` `sudo apt-get install openjdk-7-jdk```.
To check if you already have it, just type `` `java -version```
## How to compile
```: ~ / <path> $ javac * .java```
## How to run
```: ~ / <path> $ java Principal```
## Tree Construction
To build the tree, save the file "arvore.txt" a sequence of integers separated only by 01 (one) space. The file already has an example, just overwrite it with the desired values.
## Sequence of Operations
In the file "operacoes.txt" type the operations you want to perform, line by line. If it has any arguments, type it right after the command with 01 (one) space.
### Example
IMPRIMA

MEDIANA

ENESIMO 10
### Operations Guide
- ENESIMO N: Returns the nth element (counting from 1) of the path in order (symmetrical order) of ABB.
- POSICAO N: Returns the position occupied by element x in a path in symmetrical order in ABB (counting from 1).
- MEDIANA: Returns the element containing the ABB median. If ABB has an even number of elements, return the smallest of the two median elements.
- CHEIA: returns true if ABB is a full and false binary tree, otherwise.
- IMPRIMA: Returns a String containing the ABB visitation sequence by level.
- REMOVA N: Removes element N from ABB, if it is not doing nothing.
- INSIRA N: Inserts the N element into ABB, if it is already done, does nothing.