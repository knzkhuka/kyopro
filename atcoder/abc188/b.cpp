int main() {
  int n;
  cin >> n;
  vector<i64> a(n), b(n);
  cin >> a >> b;
  i64 ip = 0;
  rep(i, n) ip += a[i] * b[i];
  cout << (ip == 0 ? "Yes" : "No") << endl;
}
