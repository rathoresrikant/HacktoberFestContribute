function Get-FibonacciSequence
{
 param([int]$top)
  for($a = $b = 1; $a -lt $max)
   {
    $a
    $a,$b = ($a + $a),$a
   }
}
