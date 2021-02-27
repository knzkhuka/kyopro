int main() {
  i64 n, k;
  cin >> n >> k;
  i64 ai = n;
  auto g1 = [](i64 x) {
    string s = to_string(x);
    sort(rbegin(s), rend(s));
    return stoll(s);
  };
  auto g2 = [](i64 x) {
    string s = to_string(x);
    sort(begin(s), end(s));
    return stoll(s);
  };
  auto f = [&](i64 x) { return g1(x) - g2(x); };
  rep(i, k) { ai = f(ai); }
  cout << ai << endl;
}
