# Cross References:
# f0: N,	 
# s3: Sum
#####################################################################
		.data
prompt:		.asciiz	"\n\n Please Input a value for N =  "
floatPrompt:	.asciiz "\n You Entered A FLOAT. Your number will be truncated."
floatValue:     .asciiz "\n The float value entered: "
intValue:	.asciiz "\n The truncated integer used: "
floatOneConst:	.float 0.9999999 # This value allows for '1 - 1.xxxxxxx' to be entered
result:		.asciiz	"\n The sum of the integers from 1 to N is "
bye:		.asciiz	"\n  **** Adios Amigo - Have a good day ****"
		.globl	main
		.text
main:		
		#Ask user for value (float value)
		li	$v0, 4		# system call code for Print String
		la	$a0, prompt 	# load address of prompt into $a0
		syscall			# print the prompt message

		#Read the value and stored in ***$f0***
		li	$v0, 6		# system call code for Read Float
		syscall			# reads the value of N into $f0

		
		#Terminate if N <=0
		l.s	$f30, floatOneConst #load const into $f30
		c.le.s	1, $f0, $f30	#if user input less than 1
		bc1t	1, end	#goto end
		li	$v0, 0	# clear register $v0 to zero
		

getExp:
		#Move from float reg to temp reg
		mfc1 $t0, $f0
		
		#Get the exponent
		srl $t1, $t0, 23
		add $t2, $t1, -127

removeExp:
		#Remove the first 9 bits (exp part)
		sll $t3, $t0, 9
		srl $t3, $t3, 9
		
		#Add implied bit
		addi $t3, $t3, 8388608

getInt:
		#Gets the integer porition as the first bits 
		rol $t5, $t3, $t2
		rol $t5, $t5, 9
		
		#Removes the fractional portion
		li $s0, 31 # 31 SINCE the implied bit takes up one of the bits
		sub $s0, $s0, $t2 #$s0 contains 31 - EXP
		
		sllv $t5, $t5, $s0
		srlv $t5, $t5, $s0
		
		move $s2, $t5 #**** $s2 contains integer portion
		
		
getFrac:	
		#Gets fractional portion
		sllv $t4, $t3, $t2
		sll $t4, $t4, 9
		
		move $s1, $t4 # **** $s1 determines if value entered is float or int (int if $s1 == 0)
		beqz $s1, loop #If value entered is an int, skip the truncation prompt

printFloatEntered:


		#Alert user that value entered is float
		li	$v0, 4 
		la	$a0, floatPrompt
		syscall
		
		#Alert user the float value
		li $v0, 4
		la $a0, floatValue
		syscall
		
		li $v0, 2
		mov.s $f12, $f0
		syscall
		
		#Alert user the truncated int
		li $v0, 4
		la $a0, intValue
		syscall
		
		li $v0, 1
		move $a0, $s2
		syscall
	
loop:		
		add	$s3, $s3, $t5		# sum of integers in register $s2 ($t5 also contains same value)
		addi	$t5, $t5, -1		# summing integers in reverse order
		bnez	$t5,  loop		# branch to loop if $v0 is != zero		
		li	$v0, 4		# system call code for Print String
		la	$a0, result	# load address of message into $a0
		syscall			# print the string
	
		li	$v0, 1		# system call code for Print Integer
		move	$a0,  $s3	# move value to be printed to $a0 
		syscall			# print sum of integers
		li $s3, 0
		b 	main		# branch to main
		

end:		li	$v0, 4		# system call code for Print String
		la	$a0, bye	# load address of msg. into $a0
		syscall			# print the string

		li	$v0, 10		# terminate program run and
		syscall			# return control to  system
