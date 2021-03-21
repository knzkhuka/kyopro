int main() {
  i64 n;
  cin >> n;
  i64 ans = 0;
  ans += max(0_i, n - 999_i);
  ans += max(0_i, n - 999999_i);
  ans += max(0_i, n - 999999999_i);
  ans += max(0_i, n - 999999999999_i);
  ans += max(0_i, n - 999999999999999_i);
  cout << (ans) << endl;
}
