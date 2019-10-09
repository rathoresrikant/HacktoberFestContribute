# An array with INT or STRING or FLOAT can be passed to the function.
function quicksort($array) {
    $less, $equal, $greater = @(), @(), @()
    if( $array.Count -gt 1 ) { 
        $pivot = $array[0]
        foreach( $x in $array) {
            if($x -lt $pivot) { $less += @($x) }
            elseif ($x -eq $pivot) { $equal += @($x)}
            else { $greater += @($x) }
        }    
        $array = (@(quicksort $less) + @($equal) + @(quicksort $greater))
    }
    $array
}
