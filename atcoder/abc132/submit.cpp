#if _local
#define _GLIBCXX_DEBUG
#endif

#include<bits/stdc++.h>
using namespace std;

template<class T>std::istream&operator>>(std::istream&is,std::vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U>std::istream&operator>>(std::istream&is,std::pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T>std::ostream&operator<<(std::ostream&os,std::vector<T>const&v){for(auto const& vi:v)os<<vi<<" ";return os;}
template<class T,class U>std::ostream&operator<<(std::ostream&os,std::pair<T,U>const&p){os<<p.first<<","<<p.second;return os;}
template<class T>std::vector<T>vec(size_t a){return std::vector<T>(a);}
template<class T, class... Ts>auto vec(size_t a,Ts... ts){return std::vector<decltype(vec<T>(ts...))>(a,vec<T>(ts...));}
int64_t operator"" _i(unsigned long long x){return (int64_t)(x);}
struct fastio{fastio(){cin.tie(nullptr);ios_base::sync_with_stdio(false);std::cout<<std::fixed<<setprecision(10);}}oitsaf;
constexpr char newl='\n';
#define rep(i,n) for(int i=0;i<int(n);++i)
using pii = std::pair<int,int>;
constexpr int inf = 1<<28;
constexpr double PI = acos(-1);
template<class T>inline bool chmin(T &a,const T &b){if(a>b){a=b;return true;}return false;}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].emplace_back(v);
  }
  int s, t;
  cin >> s >> t;
  s--, t--;
  auto dist = vec<int>(3, n);
  for (auto &di : dist)
    for (auto &d : di)
      d = inf;
  dist[0][s] = 0;
  queue<pii> que;
  que.emplace(0, s);
  while (!que.empty()) {
    auto [k, v] = que.front();
    que.pop();
    int nk = (k + 1) % 3;
    for (auto nv : adj[v]) {
      if (nk > k) {
        if (chmin(dist[nk][nv], dist[k][v]))
          que.emplace(nk, nv);
      } else {
        if (chmin(dist[nk][nv], dist[k][v] + 1))
          que.emplace(nk, nv);
      }
    }
  }
  int ans = dist[0][t] == inf ? -1 : dist[0][t];
  cout << (ans) << endl;
}