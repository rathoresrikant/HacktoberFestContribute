
function factorial(n) {
    if (n === 0 || n === 1) return 1;
    let fact = 1;
    for (let i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}


function catalanNumber(n) {
    
    return factorial(2 * n) / (factorial(n + 1) * factorial(n));
}


let n = 5;
console.log(`The ${n}th Catalan number is:`, catalanNumber(n));
