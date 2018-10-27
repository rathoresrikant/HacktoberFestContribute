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
	l = list(filter(( lambda x: x != '0'), array))
	l += ['0'] * (len(array) - len(l))
	return l

if __name__ == '__main__':
	if len(sys.argv) == 1:
		example = [ str(random.randint(0,1)) for i in range(0,25) ]
		before = ' '.join(example)
		after = ' '.join(move_zeroes(example))
		message = "Before: \n {0} \n \nAfter: \n {1} \n"
		print(message.format(before,after))
	else:
		print(' '.join(move_zeroes( sys.argv[1:len(sys.argv)] )))
