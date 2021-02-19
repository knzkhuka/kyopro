int main() {
  int n;
  cin >> n;
  vector<i64> a(n);
  cin >> a;
  vector<i64> ans(n);
  rep(i, n) ans[0] += a[i] * (i & 1 ? -1 : 1);
  for (int i = 1; i < n; ++i)
    ans[i] = a[i - 1] * 2 - ans[i - 1];
  cout << (ans) << endl;
}