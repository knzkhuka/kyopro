int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  cin >> a;
  vector<int> S(2e6);
  set<int> st;
  rep(i, m) { S[a[i]]++; }
  rep(i, 2e6) if (S[i] == 0) st.emplace(i);
  int mex = 0;
  while (S[mex])
    mex++;
  int ans = mex;
  for (int i = m; i < n; ++i) {
    dout << mex << newl;
    S[a[i]]++;
    S[a[i - m]]--;
    if (S[a[i]] == 1) {
      st.erase(a[i]);
    }
    if (S[a[i - m]] == 0) {
      st.emplace(a[i - m]);
      if (chmin(mex, a[i - m])) {
        chmin(ans, mex);
      }
    }
    dout << mex << newl;
    if (S[a[i]] == 1 and a[i] == mex) {
      auto itr = st.upper_bound(mex);
      mex = *itr;
    }
  }
  cout << (ans) << endl;
}