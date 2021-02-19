std::vector<mint> __combination_factrial,__combination_inverse,__combination_factorial_inverse;
template<class T,class U>mint comb(T n,U k){
  assert(n>=k);assert(n>=0 and k>=0);
  while(__combination_factrial.size()<2*(n+1)){
    if(__combination_factrial.size()==0)__combination_factrial={1,1},__combination_inverse={0,1},__combination_factorial_inverse={1,1};
    else __combination_factrial.emplace_back(__combination_factrial.back()*__combination_factrial.size()),__combination_inverse.emplace_back(MOD-__combination_inverse[MOD%__combination_inverse.size()]*(MOD/__combination_inverse.size())),__combination_factorial_inverse.emplace_back(__combination_factorial_inverse.back()*__combination_inverse.back());
  }
  return __combination_factrial[n]*__combination_factorial_inverse[k]*__combination_factorial_inverse[n-k];
}
