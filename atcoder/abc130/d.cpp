int main() {
  i64 n, k;
  cin >> n >> k;
  vector<i64> a(n);
  cin >> a;
  int r = 0;
  i64 sum = 0;
  i64 ans = 0;
  rep(l, n) {
    while (r < n and sum + a[r] < k)
      sum += a[r++];
    ans += n - r;
    sum -= a[l];
  }
  cout<<(ans)<<endl;
}