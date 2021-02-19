int main() {
  i64 n, m;
  cin >> n >> m;
  i64 ans = mpow(10, n, m * m) / m;
  cout << (ans) << endl;
}