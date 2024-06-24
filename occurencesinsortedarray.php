<?php 
// PHP program to count occurrences 
// of an element 
  
// Returns number of times x  
// occurs in arr[0..n-1] 
function countOccurrences($arr, $n, $x) 
{ 
    $res = 0; 
    for ($i = 0; $i < $n; $i++) 
        if ($x == $arr[$i]) 
        $res++; 
    return $res; 
} 
  
    // Driver code 
    $arr = array(1, 2, 2, 2, 2, 3, 4, 7 ,8 ,8,9); 
    $n = count($arr); 
    $x = 2; 
    echo countOccurrences($arr,$n, $x); 
      
// This code is contributed by HARI 
?> 