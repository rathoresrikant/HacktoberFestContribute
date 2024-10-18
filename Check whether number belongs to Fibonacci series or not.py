import math

def is_perfect_square(x):
    s = int(math.sqrt(x))
    return s * s == x

def is_fibonacci(n):
    return is_perfect_square(5 * n * n + 4) or is_perfect_square(5 * n * n - 4)

if __name__ == "__main__":
    number = int(input("Enter a number: "))
    if is_fibonacci(number):
        print(f"{number} belongs to the Fibonacci series.")
    else:
        print(f"{number} does not belong to the Fibonacci series.")
