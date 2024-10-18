#!/usr/bin/env python3

"""
movezero.py
Move all zeroes to the end of an array.
Usage example:
	
	chmod +x movezero.py
	./movezero.py 0 2 0 4 0 6 0 8
	
	Call ./movezero.py without arguments to run a default example.
"""

import random
import sys

def move_zeroes(array):
  """
  Move all zeroes to the end of the array while preserving the order of non-zero elements.

  Args:
      array: A list of numbers or strings.

  Returns:
      A new list with zeroes at the end.
  """
  write_index = 0
  for num in array:
    if num != 0:
      array[write_index] = num
      write_index += 1
  # Fill the remaining positions with zeroes
  array[write_index:] = [0] * (len(array) - write_index)
  return array

if __name__ == '__main__':
  if len(sys.argv) == 1:
    example = [str(random.randint(0, 1)) for i in range(0, 25)]
    before = ' '.join(example)
    after = ' '.join(move_zeroes(example))
    message = "Before: \n {0} \n \nAfter: \n {1} \n"
    print(message.format(before, after))
  else:
    try:
      # Convert arguments to integers before processing
      int_array = [int(x) for x in sys.argv[1:len(sys.argv)]]
      print(' '.join(move_zeroes(int_array)))
    except ValueError:
      print("Error: Please enter only numbers as arguments.")
