(((Read-Host "Enter String 1").ToCharArray() | Sort-Object) -join '') -eq ((((Read-Host "Enter String 2").ToCharArray() | Sort-Object) -join ''))
