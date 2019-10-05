
function Get-BinomialCoefficient($n,$k) {
    
    if($k -le $n -and 0 -lt $k) {

        $numerator = $denominator = 1
        0..($k-1) | foreach{

            $numerator *= ($n-$_)
            $denominator *= ($_ + 1)
        
        }

        $result = $numerator/$denominator
        return [int]$result

    } 
    else {
        $result = 1
        return [int]$result
    }

}

function Get-CatalanNumber($n) {
    
    $top = 2 * $n
    $bot = $n
    [int]$bc = Get-BinomialCoefficient -n $top -k $bot
    $cn = $bc/($n+1)
    Write-Output $cn

}

[int]$n = Read-Host 'Enter the nth term for which Catalan number is to be found'
Get-CatalanNumber $n