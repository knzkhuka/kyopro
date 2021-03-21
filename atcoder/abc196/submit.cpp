#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
using namespace std;

struct fastio{fastio(){cin.tie(nullptr);ios_base::sync_with_stdio(false);std::cout<<std::fixed<<setprecision(10);}}oitsaf;
#define rep(i,n) for(int i=0;i<int(n);++i)
using i64 = int64_t;
constexpr char newl = '\n';
template<class T>std::istream&operator>>(std::istream&is,std::vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T>std::ostream&operator<<(std::ostream&os,std::vector<T>const&v){for(auto const& vi:v)os<<vi<<" ";return os;}
template<class T>inline bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>inline bool chmin(T &a,const T &b){if(a>b){a=b;return true;}return false;}

int main() {
  int n;
  cin >> n;
  vector<i64> a(n), t(n);
  rep(i, n) cin >> a[i] >> t[i];
  int q;
  cin >> q;
  vector<i64> x(q);
  cin >> x;

  i64 add = 0;
  i64 low = -1e10;
  i64 high = 1e10;
  rep(i, n) {
    if (t[i] == 1)
      add += a[i];
    if (t[i] == 2) {
      chmax(low, a[i] - add);
      chmax(high, a[i] - add);
    }
    if (t[i] == 3) {
      chmin(high, a[i] - add);
      chmin(low, a[i] - add);
    }
  }
  for (auto xi : x) {
    i64 ans = xi;
    if (xi < low)
      ans = low;
    else if (high < xi)
      ans = high;
    cout << ans + add << newl;
  }
}
