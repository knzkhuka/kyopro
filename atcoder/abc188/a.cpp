int main() {
  int x, y;
  cin >> x >> y;
  cout << (min(x, y) + 3 > max(x, y) ? "Yes" : "No") << endl;
}