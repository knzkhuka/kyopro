int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  int ans = 0;
  for (int i = 1; i + 1 < n; ++i) {
    vector<int> x(3);
    x[0] = a[i - 1];
    x[1] = a[i];
    x[2] = a[i + 1];
    sort(begin(x), end(x));
    ans += a[i] == x[1];
  }
  cout << (ans) << endl;
}