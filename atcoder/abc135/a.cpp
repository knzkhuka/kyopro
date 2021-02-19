int main() {
  int a, b;
  cin >> a >> b;
  int k = (a + b) / 2;
  string ans = "IMPOSSIBLE";
  if (abs(a - k) == abs(b - k))
    ans = to_string(k);
  cout << (ans) << endl;
}
