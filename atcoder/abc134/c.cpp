int main() {
  int n;
  cin >> n;
  vector<i64> a(n);
  cin >> a;
  i64 mx_f = -1, mx_s = -1;
  rep(i, n) {
    if (a[i] >= mx_f) {
      mx_s = mx_f;
      mx_f = a[i];
    } else {
      chmax(mx_s, a[i]);
    }
  }
  rep(i, n) {
    if (a[i] == mx_f)
      cout << mx_s << newl;
    else
      cout << mx_f << newl;
  }
}