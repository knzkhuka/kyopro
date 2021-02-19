#include<bits/stdc++.h>
using namespace std;

struct fastio{fastio(){cin.tie(nullptr);ios_base::sync_with_stdio(false);std::cout<<std::fixed<<setprecision(10);}}oitsaf;
#define rep(i,n) for(int i=0;i<int(n);++i)
using i64 = int64_t;
using pii = std::pair<int,int>;
constexpr char newl = '\n';
constexpr double PI = acos(-1);
template<class T>std::istream&operator>>(std::istream&is,std::vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T>std::ostream&operator<<(std::ostream&os,std::vector<T>const&v){for(auto const& vi:v)os<<vi<<" ";return os;}
template<class T,class U>std::istream&operator>>(std::istream&is,std::pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T,class U>std::ostream&operator<<(std::ostream&os,std::pair<T,U>const&p){os<<p.first<<" "<<p.second;return os;}
int64_t operator"" _i(unsigned long long x) { return (int64_t)(x); }
template<class T,class F>
struct segment_tree{
  std::vector<T> data;int n;F f;T identity;segment_tree(){}
  segment_tree(int sz,T ide,F _f):f(_f),identity(ide){n=1;while(n<sz)n<<=1;data.resize(2*n,identity);}
  segment_tree(std::vector<T> const& v,T ide,F _f):f(_f),identity(ide){int sz=v.size();n=1;while(n<sz)n<<=1;data.resize(2*n,identity);for(int i=0;i<sz;++i)data[i+n]=v[i];for(int i=n-1;i>0;--i)data[i]=f(data[i<<1|0],data[i<<1|1]);}
  void set(int i,T x){i+=n;data[i]=x;while(i,i>>=1)data[i]=f(data[i<<1|0],data[i<<1|1]);}
  T fold(int l,int r)const{l=(l<0?n:l+n),r=(r<n?r+n:n<<1);T fold_l=identity,fold_r=identity;while(l<r){if(l&1)fold_l=f(fold_l,data[l++]);if(r&1)fold_r=f(data[--r],fold_r);l>>=1,r>>=1;}return f(fold_l,fold_r);}
  T fold()const{return data[1];}
  T operator[](int i)const{return data[i+n];}
  template<class Cond>int bserch(int l,Cond& cond){l+=n;T x=identity;do{while(!l&1)l>>=1;if(cond(f(x,data[l]))){while(l<n){l<<=1;if(!cond(f(x,data[l])))x=f(x,data[l++]);}return l-n;}x=f(x,data[l++]);}while((l&-l)!=l);return -1;}
};
template<class T,class F>auto make_segtree(int n,T ide,F f){return segment_tree<T,F>(n,ide,f);}
template<class T,class F>auto make_segtree(std::vector<T>const& v,T ide,F f){return segment_tree<T,F>(v,ide,f);}

struct euler_tour {
  int r;
  int n;
  vector<vector<int>> adj;
  vector<int> dep;
  vector<int> tour;
  vector<int> Lid, Rid;
  euler_tour() {}
  euler_tour(vector<vector<int>> const &adjacent_list, int root = 0) {
    init(adjacent_list, root);
  }
  void init(vector<vector<int>> const &adjacent_list, int root = 0) {
    adj = adjacent_list;
    r = root;
    n = adjacent_list.size();
    dep.reserve(2 * n - 1);
    tour.reserve(2 * n - 1);
    Lid.resize(n);
    Rid.resize(n);
    int k = 0;
    dfs(r, -1, 0, k);
  }
  void dfs(int cur, int prv, int depth, int &idx) {
    Lid[cur] = idx++;
    dep.emplace_back(depth);
    tour.emplace_back(cur);
    for (auto const &nxt : adj[cur]) {
      if (nxt == prv)
        continue;
      dfs(nxt, cur, depth + 1, idx);
      dep.emplace_back(depth);
      tour.emplace_back(cur);
    }
    Rid[cur] = idx++;
  }
  void dump() {
    cout << " Lid : " << endl;
    for (auto x : Lid) {
      cout << x << " ";
    }
    cout << endl;
    cout << " Rid : " << endl;
    for (auto x : Rid) {
      cout << x << " ";
    }
    cout << endl;
    cout << "tour : " << endl;
    for (auto x : tour) {
      cout << x << " ";
    }
    cout << endl;
    cout << " dep : " << endl;
    for (auto x : dep) {
      cout << x << " ";
    }
    cout << endl;
  }
};

template <class T, class U, class F, class G, class H>
struct lazy_segment_tree {
  std::vector<T> data;
  std::vector<U> lazy;
  int n, height;
  F merge;
  G mapping;
  H composition;
  T ti;
  U ui;
  lazy_segment_tree() {}
  lazy_segment_tree(std::vector<T> const &v, T ide1, U ide2, F f, G g, H h)
      : ti(ide1), ui(ide2), merge(f), mapping(g), composition(h) {
    int sz = std::size(v);
    n = 1, height = 0;
    while (n < sz)
      n <<= 1, height++;
    data.resize(n << 1, ti);
    lazy.resize(n << 1, ui);
    for (int i = 0; i < sz; ++i)
      data[i + n] = v[i];
    for (int i = n; i-- > 0;)
      data[i] = merge(data[i << 1 | 0], data[i << 1 | 1]);
  }
  inline T reflect(int k) {
    return lazy[k] == ui ? data[k] : mapping(data[k], lazy[k]);
  }
  inline void evaluate(int k) {
    if (lazy[k] == ui)
      return;
    if (k < n) {
      lazy[k << 1 | 0] = composition(lazy[k << 1 | 0], lazy[k]);
      lazy[k << 1 | 1] = composition(lazy[k << 1 | 1], lazy[k]);
    }
    data[k] = reflect(k);
    lazy[k] = ui;
  }
  inline void propagate(int k) {
    for (int i = height; i >= 0; --i)
      evaluate(k >> i);
  }
  inline void recalc(int k) {
    while (k >>= 1)
      data[k] = merge(reflect(k << 1 | 0), reflect(k << 1 | 1));
  }
  void update(int a, int b, U v) {
    a += n;
    b += n;
    propagate(a);
    propagate(b - 1);
    for (int l = a, r = b; l < r; l >>= 1, r >>= 1) {
      if (l & 1)
        lazy[l] = composition(lazy[l], v), l++;
      if (r & 1)
        --r, lazy[r] = composition(lazy[r], v);
    }
    recalc(a);
    recalc(b - 1);
  }
  T fold(int a, int b) {
    a += n;
    b += n;
    propagate(a), propagate(b - 1);
    T lef_v(ti), rig_v(ti);
    for (int l = a, r = b; l < r; l >>= 1, r >>= 1) {
      if (l & 1)
        lef_v = merge(lef_v, reflect(l)), l++;
      if (r & 1)
        --r, rig_v = merge(reflect(r), rig_v);
    }
    return merge(lef_v, rig_v);
  }
  T fold() { return data[1]; }
  T fold_all() { return data[1]; }
  T operator[](int k) {
    k += n;
    propagate(k);
    return data[k];
  }
};
template <class T, class U, class F, class G, class H>
auto make_lseg(std::vector<T> v, T ide1, U ide2, F f, G g, H h) {
  return lazy_segment_tree<T, U, F, G, H>(v, ide1, ide2, f, g, h);
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  vector<pii> edges(n);
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    edges[i] = {a, b};
    adj[a].emplace_back(b);
    adj[b].emplace_back(a);
  }
  euler_tour tree(adj);
  auto merge = [](auto a, auto b) { return a; };
  auto mapping = [](auto a, auto b) { return a + b; };
  auto composition = [](auto a, auto b) { return a + b; };
  vector<i64> tmp(3 * n + 3);
  auto seg = make_lseg<i64>(tmp, 0_i, 0_i, merge, mapping, composition);
  int q;
  cin >> q;
  while (q--) {
    int t, e, x;
    cin >> t >> e >> x;
    e--;
    auto [a, b] = edges[e];
    if (t == 2)
      swap(a, b);
    if (tree.Lid[a] < tree.Lid[b]) {
      // 子側にあるb_l ~ b_r以外のすべての点に加算
      int l = tree.Lid[b];
      int r = tree.Rid[b];
      seg.update(0, l, x);
      seg.update(r + 1, 2 * n + 1, x);
    } else {
      // 親側にあるbを使えないのでa_l ~ a_rまで
      int l = tree.Lid[a];
      int r = tree.Rid[a];
      seg.update(l, r + 1, x);
    }
  }
  rep(i, n) {
    int l = tree.Lid[i];
    i64 ans = seg[l];
    cout << ans << newl;
  }
}
