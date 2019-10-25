def piglatin(s):
    return s[1:]+s[0]+"ay"

def tribWord(n): 
    Sn_1 = "1"
    Sn_2 = "12"
    Sn_3 = "1213"
    for i in range(3, n+1): 
        tmp = Sn_3 
        Sn_3 += (Sn_2 + Sn_1) 
        Sn_1 = Sn_2 
        Sn_2 = tmp  
    return Sn_3 