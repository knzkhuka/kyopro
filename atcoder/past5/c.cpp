int main() {
  int n;
  cin >> n;
  if (n == 0) {
    cout << 0 << endl;
    return 0;
  }
  const int base = 36;
  vector<int> ans;
  while (n) {
    ans.emplace_back(n % base);
    n /= base;
  }
  reverse(begin(ans), end(ans));
  for (auto x : ans) {
    if (x < 10)
      cout << x;
    else
      cout << (char)('A' + (x - 10));
  }
  cout << endl;
}
