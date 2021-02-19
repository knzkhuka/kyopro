int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  cin >> p;
  auto a = p;
  sort(begin(a), end(a));
  bool valid = false;
  rep(i, n) rep(j, n) {
    swap(p[i], p[j]);
    if (a == p)
      valid = true;
    swap(p[i], p[j]);
  }
  cout << (valid ? "YES" : "NO") << endl;
}