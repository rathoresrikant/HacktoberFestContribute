//Generate a list of prime numbers < n using the sieve of eratosthenes
fn primes(n : u64) -> Vec<u64> {
    let mut sieve : Vec<bool>  = Vec::with_capacity(n as usize);

    //Initialize sieve to all true.
    for _ in 0..n { sieve.push(true); }

    //Small values mess up the loop below, handle them separately
    let small_primes = vec![2, 3, 5, 7];
    if n <= 10 {
        return small_primes.into_iter().filter(|&x| x <= n).collect();
    }

    let limit = n / 2;
    let mut step = 2;
    for step in 2..limit {
        if sieve[step as usize] {
            let mut i = step * 2;
            while i < n {
                sieve[i as usize] = false;
                i += step;
            }
        }
    }

    let mut result : Vec<u64> = Vec::with_capacity(limit as usize);
    for i in 2..n {
        if sieve[i as usize] {
            result.push(i);
        }
    }
    result
}
