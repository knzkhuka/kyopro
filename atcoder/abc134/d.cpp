int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  vector<int> ball(n + 1);
  vector<int> state(n + 1);
  vector<int> b;
  for (int i = n; i > 0; --i) {
    for (int j = i * 2; j <= n; j += i) {
      ball[i] ^= state[j];
    }
    dout << i << ":" << ball[i] << " " << a[i - 1] << newl;
    if (ball[i] != a[i - 1]) {
      ball[i] ^= 1;
      b.emplace_back(i);
      state[i] = 1;
    }
  }
  dout << ball << newl;
  cout << size(b) << newl << b << newl;
}