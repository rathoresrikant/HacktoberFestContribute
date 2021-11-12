//we declared our string first

let string = "hacktoberfest";

//then we created a stack while is simply an abstract array.
let stringStack = string.split('');

// we are going to store our reverse string in the below variable.
let reverseString='';

// we're going to loop through our stack until it's empty and use the pop() operation to pull off the top of the stack. In this way we're going to    
// visit every letter in the reverse order and then simply concat each one of them in every iteration.
while(stringStack.length > 0){ 
    reverseString+=stringStack.pop();
}
console.log('Reverse of the string is: ', reverseString);
