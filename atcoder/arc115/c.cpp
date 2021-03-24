int main() {
  int n;
  cin >> n;
  vector<int> a(n + 1, 1);
  for (int i = n; i > 1; --i) {
    auto div = divisor(i);
    for (auto d : div)
      if (d != i)
        a[d] = a[i] + 1;
  }
  rep(i, n) cout << a[i + 1] << " ";
  cout << endl;
}
