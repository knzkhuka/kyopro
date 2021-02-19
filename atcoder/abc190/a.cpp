int main() {
  int a, b, c;
  cin >> a >> b >> c;
  string x = "Takahashi";
  string y = "Aoki";
  if (c) {
    swap(x, y);
    swap(a, b);
  }
  cout << (a > b ? x : y) << endl;
}
