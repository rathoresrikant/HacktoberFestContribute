//
// Created by timun on 30/10/2018.
//

float nextpi(int i, int max, float pi) {
    return i < max ?
            nextpi(i + 2, max, pi * (i * i) / (i * i - 1)) :
            pi;
}

float calcpi(int max) {
    return nextpi(2, max, 2);
}


void main(int *argc, char **argv) {
    if (!argv[1])
        printf("\nSyntax calcpi.exe <iterations>");
    else
        printf("\nPi using %s iterations is %f", argv[1], calcpi(atoi(argv[1])));
    printf("\n");
}