#include<bits/stdc++.h>
using namespace std;

struct fastio{fastio(){cin.tie(nullptr);ios_base::sync_with_stdio(false);std::cout<<std::fixed<<setprecision(10);}}oitsaf;
#define rep(i,n) for(int i=0;i<int(n);++i)
using i64 = int64_t;
constexpr int64_t INF = 1ll<<60;
template<class T>std::istream&operator>>(std::istream&is,std::vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T>std::ostream&operator<<(std::ostream&os,std::vector<T>const&v){for(auto const& vi:v)os<<vi<<" ";return os;}
int64_t operator"" _i(unsigned long long x) { return (int64_t)(x); }
template<class T>inline bool chmin(T &a,const T &b){if(a>b){a=b;return true;}return false;}

int main() {
  int n, m, p;
  cin >> n >> m >> p;
  vector<tuple<int, int, i64>> edges(m);
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--, c -= p;
    edges[i] = {a, b, -c};
  }
  vector<i64> dist(n, INF);
  vector<int> tapu(n);
  dist[0] = 0;
  tapu[0] = 1;
  rep(i, n) for (auto const &[u, v, w] : edges) {
    chmin(dist[v], dist[u] + w);
    tapu[v] |= tapu[u];
  }
  vector<int> neglop(n);
  rep(i, n) for (auto const &[u, v, w] : edges) {
    neglop[v] |= chmin(dist[v], dist[u] + w);
    neglop[v] |= neglop[u] & tapu[u];
  }
  i64 ans = (neglop[n - 1] ? -1 : max(0_i, -dist[n - 1]));
  cout << (ans) << endl;
}
