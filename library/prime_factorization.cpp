std::vector<std::pair<int64_t,int64_t>> prime_factorization(int64_t n){
  std::vector<std::pair<int64_t,int64_t>> factor;
  for(int64_t p=2;p*p<=n;++p){
    if(n%p!=0)continue;int64_t num=0;while(n%p==0)num++,n/=p;
    factor.emplace_back(p,num);if(n==1)return factor;
  }
  if(n!=1)factor.emplace_back(n,1);return factor;
}
