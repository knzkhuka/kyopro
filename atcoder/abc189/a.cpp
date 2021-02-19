int main() {
  char a, b, c;
  cin >> a >> b >> c;
  string ans = "Lost";
  if (a == b and b == c)
    ans = "Won";
  cout << (ans) << endl;
}
