
<?php
// code to  print the binary representation of an integer 
function bin($n) 
{ 
    /* step 1 */
    if ($n > 1) 
        bin($n/2); 
  
    /* step 2 */
    echo ($n % 2); 
} 
  
// Driver code 
bin(7); 
echo ("\n"); 
bin(4); 
  
 
?> 