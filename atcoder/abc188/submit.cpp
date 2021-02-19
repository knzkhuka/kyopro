#include<bits/stdc++.h>
using namespace std;

struct fastio{fastio(){cin.tie(nullptr);ios_base::sync_with_stdio(false);std::cout<<std::fixed<<setprecision(10);}}oitsaf;
using i64 = int64_t;

int main() {
  i64 x, y;
  cin >> x >> y;
  assert(x + y != 12);
  map<i64, i64> mp;
  auto solve = [&](auto &&solve, i64 a) -> i64 {
    if (mp.count(a))
      return mp[a];
    if (a == 1)
      return mp[a] = abs(x - a);
    if (a & 1) {
      i64 b = abs(x - a);
      i64 c = solve(solve, (a + 1) / 2) + 2;
      i64 d = solve(solve, (a - 1) / 2) + 2;
      return mp[a] = min({b, c, d});
    } else {
      i64 b = abs(x - a);
      i64 c = solve(solve, a / 2) + 1;
      return mp[a] = min(b, c);
    }
  };
  cout << (solve(solve, y)) << endl;
}