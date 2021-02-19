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
