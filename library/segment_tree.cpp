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
