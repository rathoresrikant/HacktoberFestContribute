function minDistance(s1, s2) {
    const m = s1.length;
    const n = s2.length;

    if (m === 0) return n;
    if (n === 0) return m;

    let prev = Array(n + 1).fill(0);
    let curr = Array(n + 1).fill(0);

    for (let j = 0; j <= n; j++) {
        prev[j] = j;
    }

    for (let i = 1; i <= m; i++) {
        curr[0] = i;
        for (let j = 1; j <= n; j++) {
            if (s1[i - 1] === s2[j - 1]) {
                curr[j] = prev[j - 1];
            } else {
                curr[j] = Math.min(
                    prev[j] + 1,
                    curr[j - 1] + 1,
                    prev[j - 1] + 1
                );
            }
        }
        [prev, curr] = [curr, prev];
    }

    return prev[n];
}

let s1 = "horse";
let s2 = "ros";
console.log(minDistance(s1, s2)); // Output: 3
