#((A and B) or (A and C))

#this is a very specific function that prints the truth table of the above statement

def printTruthTable():
 #here, we print the header line, with variables divided by 'tabs' - \t
 print('A' + '\t' + 'B' + '\t' + 'C' + '\t' + '(A and B) or (A and C)')

 #the loop assigns all True and False value combinations to the three variables
 for A in True, False:
  for B in True, False:
    for C in True, False:
      #the print statement is a huge string, concatenating the truth value of all variables and the statement
       print(str(A) + '\t' + str(B) + '\t' + str(C) + '\t' + str((A and B) or (A and C))),
       
printTruthTable()
