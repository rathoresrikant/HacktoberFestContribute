def print_binary_representation(num):
    binary_representation = bin(num)  
    print("Binary representation (with prefix):", binary_representation)
    print("Binary representation (without prefix):", binary_representation[2:])  


if __name__ == "__main__":
    number = int(input("Enter an integer: "))
    print_binary_representation(number)
