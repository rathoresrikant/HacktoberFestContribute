armstrong=function(){
  print("Enter two numbers(intervals): ");
  low=as.integer(readline(prompt="Enter a number"));
  high=as.integer(readline(prompt="Enter a number"));
  print("The armstrong numbers between high and low");
  
  for(i = low + 1; i < high; ++i)
  {
    temp2 = i;
    temp1 = i;
    while (temp1 != 0)
    {
      temp1 /= 10;
      ++n;
    }
    
    // result contains sum of nth power of its digits
    while (temp2 != 0)
    {
      remainder = temp2 % 10;
      result += pow(remainder, n);
      temp2 /= 10;
    }
    
    // checks if number i is equal to the sum of nth power of its digits
    if (result == i) {
      printf("%d ", i);
    }
    n = 0;
    result = 0;
    
  }
  return 0;
}
