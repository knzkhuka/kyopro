int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int ans = min(b, a * n);
  cout << (ans) << endl;
}