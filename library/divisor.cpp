std::vector<int64_t> divisor(int64_t n){
  std::vector<int64_t> div;
  for(int64_t p=1;p*p<=n;++p){if(n%p==0){div.push_back(p);if(p*p!=n)div.push_back(n/p);}}
  std::sort(div.begin(),div.end());return div;
};
