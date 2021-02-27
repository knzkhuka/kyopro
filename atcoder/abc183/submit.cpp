#include<bits/stdc++.h>
using namespace std;

struct fastio{fastio(){cin.tie(nullptr);ios_base::sync_with_stdio(false);std::cout<<std::fixed<<setprecision(10);}}oitsaf;

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