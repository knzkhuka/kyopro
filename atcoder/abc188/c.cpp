int main() {
  int n;
  cin >> n;
  vector<int> a(1 << (n - 1)), b(1 << (n - 1));
  cin >> a >> b;
  auto amax = max_element(begin(a), end(a));
  auto bmax = max_element(begin(b), end(b));
  int ans = -1;
  if (*amax > *bmax) {
    ans = bmax - begin(b) + 1 + (1 << (n - 1));
  } else {
    ans = amax - begin(a) + 1;
  }
  cout << (ans) << endl;
}
