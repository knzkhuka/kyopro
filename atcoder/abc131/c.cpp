int main() {
  i64 a, b, c, d;
  cin >> a >> b >> c >> d;
  auto f = [&](i64 x) -> i64 {
    i64 ushi = x / c;
    i64 tapu = x / d;
    i64 nich = x / lcm(c, d);
    return x - ushi - tapu + nich;
  };
  i64 ans = f(b) - f(a - 1);
  cout << (ans) << endl;
}