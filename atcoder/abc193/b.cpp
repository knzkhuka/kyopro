int main() {
  int n;
  cin >> n;
  using t3 = tuple<int, int, int>;
  vector<t3> data(n);
  rep(i, n) {
    int a, p, x;
    cin >> a >> p >> x;
    data[i] = {p, a, x};
  }
  sort(begin(data), end(data));

  for (auto [p, a, x] : data) {
    if (a < x) {
      cout << (p) << endl;
      return 0;
    }
  }
  cout << (-1) << endl;
}
