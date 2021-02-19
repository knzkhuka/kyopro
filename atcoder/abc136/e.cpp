int main() {
  int n;
  i64 k;
  cin >> n >> k;
  vector<i64> a(n);
  cin >> a;
  assert(!(n == 2 && k == 3));
  i64 sum = accumulate(begin(a), end(a), 0_i);
  auto div = divisor(sum);
  auto chk = [&](i64 x) {
    vector<i64> r(n);
    rep(i, n) r[i] = a[i] % x;
    sort(begin(r), end(r));
    vector<i64> sum(n + 1);
    rep(i, n) sum[i + 1] = sum[i] + r[i];
    i64 cnt = INF;
    rep(i, n + 1) {
      i64 ushi = (n - i) * x - (sum[n] - sum[i]);
      i64 tapu = sum[i];
      if (ushi == tapu)
        chmin(cnt, ushi);
    }
    return cnt <= k;
  };
  reverse(begin(div), end(div));
  for (auto x : div) {
    if (chk(x)) {
      cout << (x) << endl;
      return 0;
    }
  }
}