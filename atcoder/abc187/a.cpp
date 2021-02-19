int main() {
  int a, b;
  cin >> a >> b;
  auto f = [](int x) {
    int res = 0;
    while (x) {
      res += x % 10;
      x /= 10;
    }
    return res;
  };
  a = f(a);
  b = f(b);
  cout << (max(a, b)) << endl;
}
