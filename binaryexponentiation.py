# Problem:- finding the large exponents of a number--> a^b

class Solution:
	def binaryexpo(self,a:int,b:int)->int:  
		res=1
		while b>0:
			if b&1:
				res=res*a
			a=a*a
			b>>=1
		return res
		  # X raised to power n
		
