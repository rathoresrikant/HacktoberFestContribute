param(
    [Parameter(Mandatory=$true)]
    [ValidateNotNullOrEmpty()]
    [string]$String1,

    [Parameter(Mandatory=$true)]
    [ValidateNotNullOrEmpty()]
    [string]$String2
)
$String1 = $String1 -replace '[^a-zA-Z]', ''
$String2 = $String2 -replace '[^a-zA-Z]', ''

$CommonLetters = @()

foreach($l1 in $String1.ToCharArray())
{    
    foreach($l2 in $String2.ToCharArray())
    {
        if ($l1 -eq $l2)
        {
            $CommonLetters += $l1
            break
        }
    }
}

$CommonLetters | Sort-Object -Unique
