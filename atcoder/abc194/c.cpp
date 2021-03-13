int main() {
  int n;
  cin >> n;
  vector<i64> a(n);
  cin >> a;
  i64 ans = 0;
  i64 sum = 0;
  i64 sum2 = 0;
  rep(i, n) {
    ans += i * a[i] * a[i];
    ans += -2 * a[i] * sum;
    ans += sum2;
    sum += a[i];
    sum2 += a[i] * a[i];
  }
  cout << (ans) << endl;
}
