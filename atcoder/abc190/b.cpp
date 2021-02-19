int main() {
  i64 n, s, d;
  cin >> n >> s >> d;
  bool ok = false;
  rep(i, n) {
    i64 x, y;
    cin >> x >> y;
    if (x >= s)
      continue;
    if (y <= d)
      continue;
    ok = true;
  }
  cout << (ok ? "Yes" : "No") << endl;
}
