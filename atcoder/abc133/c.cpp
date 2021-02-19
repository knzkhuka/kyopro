int main() {
  i64 l, r;
  cin >> l >> r;
  i64 ans = inf;
  if (r - l > 2020)
    ans = 0;
  else {
    for (i64 i = l; i <= r; ++i) {
      for (i64 j = i + 1; j <= r; ++j) {
        chmin(ans, i * j % 2019);
      }
    }
  }
  cout << (ans) << endl;
}