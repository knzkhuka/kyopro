int main() {
  double sx, sy, gx, gy;
  cin >> sx >> sy >> gx >> gy;
  gy = -gy;
  double dx = gx - sx;
  double dy = gy - sy;
  double d = dy / dx;
  double ans = sx - sy / d;
  cout << (ans) << endl;
}