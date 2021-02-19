int main() {
  int n, m;
  cin >> n >> m;
  vector<mint> a(n + 1, 1);
  rep(i, m) {
    int x;
    cin >> x;
    a[x] = 0;
  }
  for (int i = 2; i <= n; ++i) {
    if (a[i] == 0)
      continue;
    a[i] = a[i - 1] + a[i - 2];
  }
  dout<<a<<newl;
  cout << (a[n]) << endl;
}