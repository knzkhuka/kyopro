int main() {
  int a, b;
  cin >> a >> b;
  a += b;
  int ans = 4;
  if (a >= 15 and b >= 8)
    ans = 1;
  else if (a >= 10 and b >= 3)
    ans = 2;
  else if (a >= 3)
    ans = 3;
  cout << (ans) << endl;
}
