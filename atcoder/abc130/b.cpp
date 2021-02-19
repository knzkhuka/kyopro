int main() {
  int n, x;
  cin >> n >> x;
  vector<int> l(n);
  cin >> l;
  vector<int> sum(n + 1);
  rep(i, n) sum[i + 1] = sum[i] + l[i];
  auto itr = upper_bound(begin(sum), end(sum), x);
  int ans = itr - begin(sum);
  cout << (ans) << endl;
}