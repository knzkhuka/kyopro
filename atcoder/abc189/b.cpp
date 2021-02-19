int main() {
  int n;
  long double x;
  cin >> n >> x;
  long double a = 0.0;
  int ans = -1;
  rep(i, n) {
    long double v, p;
    cin >> v >> p;
    a += v * p / 100.0;
    if (a > x) {
      ans = i + 1;
      break;
    }
  }
  cout << (ans) << endl;
}
