int main() {
  int a, b, c;
  cin >> a >> b >> c;
  c -= a - b;
  cout << max(0, c) << endl;
}