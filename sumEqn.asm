INCLUDE C:\Irvine\Irvine32.inc
INCLUDELIB C:\Irvine\Irvine32.lib
INCLUDELIB C:\Irvine\User32.lib
INCLUDELIB C:\Irvine\Kernel32.lib
.data
;;
.code
main PROC
    call ReadDec
    mov ebx,eax
    inc ebx
    mul ebx
    mov ebx, 2h
    div ebx
    call WriteDec
    mov al, 0Ah
    call WriteChar
    call WaitMsg
    exit
main ENDP
END main