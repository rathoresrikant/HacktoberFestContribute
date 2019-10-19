class Solution:
    def isPalindrome(self, x: int) -> bool:
        rev=0
        num=x
        while(x!=0):
            rev=rev*10+x%10
            x=int(x/10)
        if(rev==num):
            return True
        else:
            return False
        
