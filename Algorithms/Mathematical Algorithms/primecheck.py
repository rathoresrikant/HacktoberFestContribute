def primeCheck(number):
    prime = True
    for i in range(2, int(number**(0.5)+2), 2):
        if i != 2:
            i = i - 1
        if number % i == 0:
            prime = False
            break
    return prime

def main():
    num = int(input("Enter the number to be tested: "))
    print(primeCheck(num))
if __name__ == '__main__':
	main()
