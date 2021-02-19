#include<bits/stdc++.h>
using namespace std;

struct fastio{fastio(){cin.tie(nullptr);ios_base::sync_with_stdio(false);std::cout<<std::fixed<<setprecision(10);}}oitsaf;
#define rep(i,n) for(int i=0;i<int(n);++i)
using pii = std::pair<int,int>;
constexpr int inf = 1<<28;
constexpr char newl = '\n';
constexpr double PI = acos(-1);
template<class T>std::istream&operator>>(std::istream&is,std::vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T>std::ostream&operator<<(std::ostream&os,std::vector<T>const&v){for(auto const& vi:v)os<<vi<<" ";return os;}
template<class T,class U>std::istream&operator>>(std::istream&is,std::pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T,class U>std::ostream&operator<<(std::ostream&os,std::pair<T,U>const&p){os<<p.first<<" "<<p.second;return os;}
template<class T>inline bool chmin(T &a,const T &b){if(a>b){a=b;return true;}return false;}

int main() {
  int n, m;
  cin >> n >> m;
  vector mat(n, vector<int>(n, inf));
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    chmin(mat[a][b], c);
  }
  vector<vector<pii>> adj(n);
  rep(i, n) rep(j, n) if (mat[i][j] != inf) adj[i].emplace_back(j, mat[i][j]);
  rep(i, n) {
    priority_queue<pii, vector<pii>, greater<>> que;
    vector<int> dist(n, inf);
    for (auto [to, cost] : adj[i]) {
      que.emplace(cost, to);
      dist[to] = cost;
    }
    while (!que.empty()) {
      auto [c, v] = que.top();
      que.pop();
      for (auto [to, cost] : adj[v]) {
        if (chmin(dist[to], c + cost))
          que.emplace(c + cost, to);
      }
    }
    cout << (dist[i] == inf ? -1 : dist[i]) << newl;
  }
}
