#Tax Calc in Python

print(f"""
Welcome to taxCalc
Please note that tax rate is at 6.25%
""")

name = input('Enter Name: ')
allowance = int(input('Enter Allowance(In Naira): '))

calc = 6.25 % allowance

print(f"""
Hello {name},
You are to pay a tax of {calc} in naira.
Thanks.
""")