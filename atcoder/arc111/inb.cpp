int main() {
  const int n = 2e5;
  const int amax = 2e5;
  cout << n << endl;
  for (int i = 1; i <= n; ++i) {
    random_device rnd;
    int a = rnd() % amax + 1;
    int b = rnd() % amax + 1;
    cout << a << " " << b << newl;
  }
}