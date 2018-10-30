void main(int *argc, char **argv) {
    if (!argv[1]) {
        printf("Usage : byte2binary.exe <hex>");
        return;
    }
    unsigned short index = -1;
    char nextchar = 0;
    while (argv[1][++index] != '\0') {
        nextchar = ((argv[1][index]) - 48);
        nextchar -= nextchar > 9 ? 7 : 0;
        if (nextchar > 0xF) return;
        printf(
                "%c%c%c%c",
                (nextchar >> 3) & 1 ? '1' : '0',
                (nextchar >> 2) & 1 ? '1' : '0',
                (nextchar >> 1) & 1 ? '1' : '0',
                (nextchar >> 0) & 1 ? '1' : '0'
        );
    }
}