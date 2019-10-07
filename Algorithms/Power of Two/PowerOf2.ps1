function Test-PowerOf2([int]$n) {
    $i = $n
    if($i -lt 1) {
        Write-Output "$n is NOT a Power of 2" 
    }
    elseif($i -eq 1) {
        Write-Output "$n is a Power of 2"
    }
    else {
        while($i -gt 1) {

            if($i % 2 -eq 0) {
                $i = $i / 2
                if ($i -eq 1) {
                    Write-Output "$n is a Power of 2"
                }
            }
            else {
                Write-Output "$n is NOT a Power of 2"
                Break
            }

        }
    }
}

$num = Read-Host 'Enter a number to test if it is a power of 2'
Test-PowerOf2 $num