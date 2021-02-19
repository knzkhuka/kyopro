#include<bits/stdc++.h>
using namespace std;

struct fastio{fastio(){cin.tie(nullptr);ios_base::sync_with_stdio(false);std::cout<<std::fixed<<setprecision(10);}}oitsaf;
#define rep(i,n) for(int i=0;i<int(n);++i)
constexpr int inf = 1<<28;
constexpr char newl = '\n';
template<class T>std::istream&operator>>(std::istream&is,std::vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T>std::ostream&operator<<(std::ostream&os,std::vector<T>const&v){for(auto const& vi:v)os<<vi<<" ";return os;}
#if _local
struct debug_structure{template<class T>debug_structure&operator<<(const T&elm){std::cerr<<elm<<std::flush;return*this;}}dout;
#else
struct debug_structure{template<class T>debug_structure&operator<<(const T&elm){return*this;}}dout;
#endif
template<class T>inline bool chmin(T &a,const T &b){if(a>b){a=b;return true;}return false;}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> adj(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    adj[a] |= 1 << b;
    adj[b] |= 1 << a;
  }
  vector<int> dp(1 << n, inf);
  rep(S, 1 << n) {
    bool kn = true;
    rep(i, n) if ((S >> i) & 1) kn &= ((adj[i] | 1 << i) & S) == S;
    if (kn)
      dp[S] = 1;
  }
  rep(S, 1 << n) {
    for (int T = S;; T = (T - 1) & S) {
      if (T == 0)
        break;
      chmin(dp[S], dp[S ^ T] + dp[T]);
    }
  }
  cout << (dp.back()) << endl;
  rep(i, 1 << n) dout << i << ":" << bitset<10>(i) << ":" << dp[i] << newl;
}