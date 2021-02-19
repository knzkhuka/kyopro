#include<bits/stdc++.h>
using namespace std;

struct fastio{fastio(){cin.tie(nullptr);ios_base::sync_with_stdio(false);std::cout<<std::fixed<<setprecision(10);}}oitsaf;
#define rep(i,n) for(int i=0;i<int(n);++i)
template<class T>std::istream&operator>>(std::istream&is,std::vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T>std::ostream&operator<<(std::ostream&os,std::vector<T>const&v){for(auto const& vi:v)os<<vi<<" ";return os;}
template<class T>
struct union_find{
  size_t n;std::vector<int> par;size_t group;std::vector<T> data;
  union_find(){}
  union_find(size_t _n):n(_n),group(_n){par.resize(n,-1);data.resize(n);}
  union_find(size_t _n,std::vector<T> v):n(_n),group(_n),data(v){par.resize(n,-1);}
  void reset (size_t _n){n = _n;group = n;par.clear();par.resize(n,-1);}
  int root (int k){if(par[k]<0)return k;return par[k]=root(par[k]);}
  int size (int k){k=root(k);return -par[k];}
  bool unite (int a,int b){
    a=root(a);b=root(b);if(a==b)return false;
    if(size(a)<size(b))std::swap(a,b);group--;
    par[a]+=par[b];data[a]+=data[b];par[b]=a;return true;
  }
  bool same (int a,int b){return root(a) == root(b);}
  T &operator[] (int k){return data[root(k)];}
  bool operator() (int a,int b){return unite(a,b);}
};

int main() {
  int n;
  cin >> n;
  const int v = 4e5 + 1;
  vector<vector<int>> adj(v);
  union_find<int> uni(v);
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    uni.unite(a, b);
    adj[a].emplace_back(b);
    adj[b].emplace_back(a);
  }
  vector<bool> seen(v);
  vector<int> root_v(v, -1);
  auto iscycle = [&](auto &&self, int cur, int prv, int root) -> bool {
    if (seen[cur])
      return true;
    seen[cur] = true;
    root_v[cur] = root;
    bool flag = false;
    for (auto to : adj[cur]) {
      if (to == prv)
        continue;
      flag |= self(self, to, cur, root);
    }
    return flag;
  };
  int ans = 0;
  rep(i, v) if (!seen[i] and size(adj[i])) {
    if (!iscycle(iscycle, i, -1, i)) {
      ans += uni.size(i) - 1;
    } else
      ans += uni.size(i);
  }
  cout << (ans) << endl;
}