
# Ruby function to get the factorial of an integer
def factorial(number)
  return 1 if number <= 1
  number * factorial(number - 1)
end

# How to run:
# $ ruby factorial.rb
puts "Factorial of an Integer"
puts "Enter an integer: "
number = gets.chomp
puts "The factorial of the Integer #{number} is: #{factorial(number.to_i)}"
