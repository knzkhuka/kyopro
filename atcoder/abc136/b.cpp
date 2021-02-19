int main(){
  int n;
  cin>>n;
  int ans = 0;
  for(int i=1;i<=n;++i){
    string x = to_string(i);
    int m = size(x);
    ans += m&1;
  }
  cout<<(ans)<<endl;
}