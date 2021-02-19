int main() {
  double w, h, x, y;
  cin >> w >> h >> x >> y;
  double area = w * h / 2.0;
  bool ans = w / 2.0 == x and h / 2.0 == y;
  cout << area << " " << ans << endl;
}