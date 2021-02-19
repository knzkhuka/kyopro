#include<bits/stdc++.h>
using namespace std;

struct fastio{fastio(){cin.tie(nullptr);ios_base::sync_with_stdio(false);std::cout<<std::fixed<<setprecision(10);}}oitsaf;
#define rep(i,n) for(int i=0;i<int(n);++i)
template<class T>std::istream&operator>>(std::istream&is,std::vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T>std::ostream&operator<<(std::ostream&os,std::vector<T>const&v){for(auto const& vi:v)os<<vi<<" ";return os;}
template<class T>inline bool chmin(T &a,const T &b){if(a>b){a=b;return true;}return false;}

int main() {
  const int n = 4, m = 4;
  vector<string> s(n);
  cin >> s;
  vector<double> dp(1 << (n * m), -1);
  dp[0] = 0;
  int S = 0;
  auto encode = [&](int i, int j) { return i * m + j; };
  rep(i, n) rep(j, m) if (s[i][j] == '#') S |= 1 << encode(i, j);
  constexpr int dx[] = {1, 0, -1, 0, 0};
  constexpr int dy[] = {0, 1, 0, -1, 0};
  auto solve = [&](auto &solve, const int S) -> double {
    if (dp[S] != -1)
      dp[S];
    dp[S] = 1e10;
    cout << bitset<16>(S) << endl;
    rep(y, n) rep(x, m) {
      double target = 0.0;
      double sum = 0.0;
      rep(i, 5) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny == -1 || nx == -1 || ny == n || nx == m)
          continue;
        if (S & (1 << encode(ny, nx))) {
          target += 1.0;
          sum += solve(solve, S ^ (1 << encode(ny, nx)));
        }
      }
      chmin(dp[S], (5.0 + sum) / target);
    }
    return dp[S];
  };
  cout << solve(solve, S) << endl;
}
