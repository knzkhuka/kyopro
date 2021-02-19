int main() {
  int n, k;
  cin >> n >> k;
  // mod = 1000000007
  for (int i = 1; i <= k; ++i) {
    mint ans = comb(k - 1, i - 1);
    int r = n - k - i + 1;
    int n = i + 1;
    if (r < 0 or n + r - 1 < 0)
      ans = 0;
    else
      ans *= comb(n + r - 1, r);
    cout << ans << newl;
  }
}