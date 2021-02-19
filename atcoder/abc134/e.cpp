int main() {
  int n;
  cin >> n;
  vector<i64> a(n);
  cin >> a;
  multiset<i64> st;
  rep(i, n) {
    auto itr = st.lower_bound(a[i]);
    if (itr != begin(st)) {
      itr--;
      st.erase(itr);
    }
    st.emplace(a[i]);
  }
  cout << st.size() << endl;
}