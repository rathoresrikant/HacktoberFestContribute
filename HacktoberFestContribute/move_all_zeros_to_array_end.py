#   Contribution from Santanu Bhattacharjee
# My GitHub account - https://github.com/santanu94

def move_zero_to_end(array = [5,0,2,0,3,0,4]):
    array.sort(key= lambda x: True if x == 0 else False, reverse= False)
    return array

print(move_zero_to_end([0,0,0,2,6,22,5,34,76,'a','tgf',65,0,'c']))