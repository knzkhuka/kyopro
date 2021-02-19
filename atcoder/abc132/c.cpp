int main() {
  int n;
  cin >> n;
  vector<i64> a(n);
  cin >> a;
  sort(begin(a),end(a));
  int mid = n/2;
  if(n&1){
    bool ans = a[mid]!=a[mid-1] and a[mid]!=a[mid+1];
    cout<<(ans)<<endl;
  }else{
    bool ans = a[mid]!=a[mid-1];
    cout<<(ans?a[mid]-a[mid-1]:0)<<endl;
  }
}