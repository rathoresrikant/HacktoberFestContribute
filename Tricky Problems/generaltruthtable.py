# A python function that prints a formal logic truth table for any user inputted statement.
# Collecting input from user - it must be formatted properly, or the function returns an error.
print('Please, use different capital letters for atomic sentences and don\'t forget to use brackets properly.')
print('Also, use the python logical notation - the words and, or, not.')
conclusionInput = input('Input your desired sentence in the formal logic form: ')

# Creating a list containing all capital letters, so that we can check which ones the user chose to use.
alphabet = list(map(chr, range(65, 91)))
# Creating a custom list containing the letters representing the chosen atomic sentences.
# The copy list can be looped for the letters even when the original list is transformed for truth value.
characterList = []
characterListCopy = []
for char in conclusionInput:
 if char in alphabet:
 if char not in characterList:
 characterList.append(char)
 characterListCopy.append(char)
 # Creating a global variable for each of the letters. It will be useful later when we use its truth value.
 exec('%s = False' % char)
 
# As lists start from zero, to know the index of the last letter in our list, we use the following statement.
n = len(characterList) - 1

# Printing the header line.
print('')
for char in characterList:
 print(char, end = '\t')
print(conclusionInput)

# The function itself.
def printTruthTable(conclusion, n):

 # We will need a different approach to odd and even numbers. This is the easiest way I know to do it.
 i = 2

 # Recursion to loop through a variable amount of atomic sentences.
 if n >= 0:
  for characterList[n] in True, False:

   # The check for odd / even loop, to be able to set the global variable properly.
   if i%2 == 0:

    # Setting the global variable, so that our exec(conclusion) can read it.
    exec('%s = True' % characterListCopy[n], globals())
    i -= 1
    printTruthTable(conclusion, n - 1)
    
   else:
    # Setting the global variable, so that our exec(conclusion) can read it.
    exec('%s = False' % characterListCopy[n], globals())
    i += 1
    printTruthTable(conclusion, n -1)
    
 # Printing each row of the table.
 else:

  # Looping through the local variables.
  for char in characterList:
   print(char, end = '\t')

  # Evaluating the conclusion using the global variables.
  exec(conclusion)
  
conclusionString = 'print(' + conclusionInput + ')'

printTruthTable(conclusionString, n)
