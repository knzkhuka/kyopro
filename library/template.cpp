#if _local
#define _GLIBCXX_DEBUG
#endif

#pragma GCC target ("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>

using i32=int32_t;using i64=int64_t;using i128=__int128_t;using pii=std::pair<i64,i64>;
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define repr(i,n) for(int i=(int)n;i-->0;)
constexpr i32 inf{1<<28};constexpr i64 INF{1ll<<60};
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}return 0;}
constexpr i128 sqrt(i128 c){i128 x=1;while(!(x*x<=c&&c<=(x+1)*(x+1)))x=(c/x+x)/2;return x;}

template<class T>std::istream&operator>>(std::istream&is,std::vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U>std::istream&operator>>(std::istream&is,std::pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T>std::ostream&operator<<(std::ostream&os,std::vector<T>const&v){for(auto const& vi:v)os<<vi<<" ";return os;}
template<class T,class U>std::ostream&operator<<(std::ostream&os,std::pair<T,U>const&p){os<<p.first<<" "<<p.second;return os;}
std::istream&operator>>(std::istream&is,__int128_t&val){std::string s;is>>s;val=0;bool neg=s[0]=='-';for(int i=neg;i<s.size();++i)(val*=10)+=s[i]-'0';if(neg)val=-val;return is;}
std::ostream&operator<<(std::ostream&os,__int128_t val){std::ostream::sentry s(os);if(s){__uint128_t tmp=val<0?-val:val;char buf[128];char*d=std::end(buf);do{--d;*d="0123456789"[tmp%10];tmp/=10;}while(tmp!=0);if(val<0){--d;*d='-';}int len=std::end(buf)-d;if(os.rdbuf()->sputn(d, len)!=len)os.setstate(std::ios_base::badbit);}return os;}
template<class T>std::vector<T>vec(size_t a){return std::vector<T>(a);}
template<class T, class... Ts>auto vec(size_t a,Ts... ts){return std::vector<decltype(vec<T>(ts...))>(a,vec<T>(ts...));}

#if _local
struct debug_structure{template<class T>debug_structure&operator<<(const T&elm){std::cerr<<elm<<std::flush;return*this;}}dout;
#else
struct debug_structure{template<class T>debug_structure&operator<<(const T&elm){return*this;}}dout;
#endif

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
auto RMQ(int n=2e5){return make_segtree<int64_t>(n,-(1ll<<60),[](auto a,auto b){return a>b?a:b;});}auto rmq(int n=2e5){return make_segtree<int64_t>(n,1ll<<60,[](auto a,auto b){return a<b?a:b;});}auto rsq(int n=2e5){return make_segtree<int64_t>(n,0,[](auto a,auto b){return a+b;});}
auto RMQ(int n,int64_t v){return make_segtree<int64_t>(n,v,[](auto a,auto b){return a>b?a:b;});}auto rmq(int n,int64_t v){return make_segtree<int64_t>(n,v,[](auto a,auto b){return a<b?a:b;});}auto rsq(int n,int64_t v){return make_segtree<int64_t>(n,v,[](auto a,auto b){return a+b;});}

struct union_find{
  size_t n;std::vector<int> par;size_t group;union_find(){}
  union_find(size_t _n):n(_n),group(_n){par.resize(n,-1);}
  void reset (size_t _n){n = _n;group = n;par.clear();par.resize(n,-1);}
  int root (int k){if(par[k]<0)return k;return par[k]=root(par[k]);}
  int size (int k){k=root(k);return -par[k];}
  bool unite (int a,int b){a=root(a);b=root(b);if(a==b)return false;if(size(a)<size(b))std::swap(a,b);group--;par[a]+=par[b];par[b]=a;return true;}
  bool same (int a,int b){return root(a) == root(b);}
  int operator[] (int k){return size(k);}
  bool operator() (int a,int b){return unite(a,b);}
};

template<int64_t MOD>
struct modint{
  int64_t val;modint():val(0){}modint(int64_t v):val(v<0?(MOD-(-v)%MOD)%MOD:v%MOD){}operator int64_t(){return val;}
  constexpr modint &operator += (modint other){this->val+=other.val;if(this->val>=MOD)this->val-=MOD;return *this;}
  constexpr modint &operator -= (modint other){this->val-=other.val;if(this->val<0)this->val+=MOD;return *this;}
  constexpr modint &operator *= (modint other){this->val*=other.val;if(this->val>=MOD)this->val%=MOD;return *this;}
  constexpr modint &operator /= (modint other){this->val*=other.inverse();if(this->val>=MOD)this->val%=MOD;return *this;}
  constexpr modint operator + (modint other)const{return modint(val)+=other;}
  constexpr modint operator - (modint other)const{return modint(val)-=other;}
  constexpr modint operator * (modint other)const{return modint(val)*=other;}
  constexpr modint operator / (modint other)const{return modint(val)/=other;}
  template<class T>constexpr modint operator + (T other)const{return modint(val)+=(modint)other;}
  template<class T>constexpr modint operator - (T other)const{return modint(val)-=(modint)other;}
  template<class T>constexpr modint operator * (T other)const{return modint(val)*=(modint)other;}
  template<class T>constexpr modint operator / (T other)const{return modint(val)/=(modint)other;}
  template<class T>constexpr modint mpow(T _n)const{int64_t n=_n;modint res(1),base(val);while(n){if(n&1)res*=base;base*=base;n>>=1;}return res;}
  template<class T,class U>constexpr static modint mpow(T t,U u){return modint(t).mpow(u);}
  constexpr modint inverse()const{return mpow(val,MOD-2);}
  friend std::ostream&operator<<(std::ostream&os,modint mo){return os<<mo.val;}
  friend std::istream&operator>>(std::istream&is,modint&mo){return is>>mo.val;}
};
constexpr int64_t MOD = 1000000007;
//constexpr int64_t MOD = 998244353;
using mint = modint<MOD>;

int64_t operator"" _i(unsigned long long x){return (int64_t)(x);}
mint operator"" _m(unsigned long long x){return mint(x);}

using namespace std;

signed main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  constexpr char newl = '\n';

  

}