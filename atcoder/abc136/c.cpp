int main() {
  int n;
  cin >> n;
  vector<i64> a(n);
  cin >> a;
  a[0]--;
  for (int i = 1; i < n; ++i) {
    if (a[i] > a[i - 1])
      a[i]--;
  }
  bool ans = true;
  rep(i, n - 1) ans &= a[i] <= a[i + 1];
  cout << (ans ? "Yes" : "No") << endl;
}