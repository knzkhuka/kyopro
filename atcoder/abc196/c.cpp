int main() {
  i64 n;
  cin >> n;
  i64 ans = 0;
  for (i64 x = 1;; ++x) {
    string sx = to_string(x);
    string s = sx + sx;
    i64 xx = stoll(s);
    if (xx > n)
      break;
    ans++;
  }
  cout << (ans) << endl;
}