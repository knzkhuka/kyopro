int main() {
  i64 n;
  cin >> n;
  i64 cnt = 0;
  set<i64> S;
  for (i128 a = 2;; ++a) {
    if (a * a > n)
      break;
    i128 p = a;
    for (i128 b = 2;; ++b) {
      p *= a;
      if (p > n)
        break;
      cnt++;
      S.emplace(p);
    }
  }
  i64 ans = n - size(S);
  cout << (ans) << endl;
}
