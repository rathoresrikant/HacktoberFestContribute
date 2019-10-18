function catalan(num) {
  if (num < 2) return 1;
  const res = new Array(num + 1).fill(0);
  res[0] = res[1] = 1;
  for (let i = 2; i <= num; i++) {
    for (let j = 0; j < i; j++) {
      res[i] = res[i] + res[j] * res[i - j - 1];
    }
  }
  return res[num];
}
