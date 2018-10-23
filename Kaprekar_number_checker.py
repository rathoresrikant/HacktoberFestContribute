def is_equal(a, b):

    #tests equality

    if a == b:

        return True

    else:

        return False



def is_kaprekar(num):



    square = num**2

    square = str(square)

    length = len(square)



    if length % 2 == 0:  #if the length is even

        first_part = int(square[0 : length//2])

        sec_part = int(square[length//2 : ])



    else:  #if the length is odd

        first_part = int(square[0 : ((length - 1)//2)])

        sec_part = int(square[(length - 1)//2 : ])

    #Always takes the shorter for first_part and longer for sec_part

    total = first_part + sec_part

    return is_equal(num, total)



def main():



    num = int(input('Enter the Number you want to check : '))

    print(is_kaprekar(num))



main()
