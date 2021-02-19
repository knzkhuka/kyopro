int main() {
  i64 n;
  cin >> n;
  int ans = 0;
  auto f = [](i64 x) { return x * (x + 1) / 2; };
  for (i64 len = 1;; ++len) {
    if (f(len) > n) break;
    i64 m = n % len;
    if (len & 1) {
      if (m == 0)
        ans++;
    } else {
      if (len / 2 == m)
        ans++;
    }
  }
  cout << (ans * 2) << endl;
}
