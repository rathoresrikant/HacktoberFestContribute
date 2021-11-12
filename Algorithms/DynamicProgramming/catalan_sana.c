int catalan(int n) {
  int numerator = 1;
  for (int i = n + 1; i <= 2 * n; i++)
    numerator *= i;
  int denominator = 1;
  for (int i = 1; i <= n; i++)
    denominator *= i;
  return (numerator / denominator) / (n + 1);
}
