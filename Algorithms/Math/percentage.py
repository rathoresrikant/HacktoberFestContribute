while True:
    try:
        num = float(input("Enter a number: "))
        break
    except ValueError:
        print("Oops!  That was no valid number.  Try again...")
print("{:.3%}".format(num))