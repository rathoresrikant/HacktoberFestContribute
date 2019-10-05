// a recursive algorithm for fibonacci sequence in javascript

function fibonacci(n){
    if (n <= 1) {
        return 1;
    }

    return fibonacci(n - 1) + fibonacci (n - 2);
}