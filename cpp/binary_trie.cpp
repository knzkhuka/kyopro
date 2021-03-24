#include <iostream>
#include <vector>

template <class T, class F> struct binary_trie {
  struct node_t {
    T val;
    size_t sz;
    size_t zero, one;
    node_t() : sz(0), val(), zero(0), one(0) {}
    node_t(T v) : sz(0), val(v), zero(0), one(0) {}
  };

  size_t sz;
  size_t bitlen;
  std::vector<node_t> data;
  F merge;
  T identity;

  binary_trie(T ide, F f) : bitlen(30), identity(ide), merge(f) {
    data.push_back(node_t(identity));
  }

  void update_node(size_t node_i) {
    node_t &node = data[node_i];
    if (node.zero and node.one) {
      node_t left = data[node.zero];
      node_t righ = data[node.one];
      node.val = merge(left.val, righ.val);
      node.sz = left.sz + righ.sz;
    } else if (node.zero) {
      node.val = data[node.zero].val;
      node.sz = data[node.zero].sz;
    } else if (node.one) {
      node.val = data[node.one].val;
      node.sz = data[node.one].sz;
    } else {
    }
  }

  void set(size_t i, T v) { set_impl(0, bitlen - 1, i, v); }
  void set_impl(size_t node_i, size_t dep, size_t i, T v) {
    if (dep == 0) {
      if ((i >> dep) & 1) {
        if (!data[node_i].one) {
          data[node_i].one = data.size();
          data.push_back(node_t());
          data[data[node_i].one].sz = 1;
        }
        data[data[node_i].one].val = v;
      } else {
        if (!data[node_i].zero) {
          data[node_i].zero = data.size();
          data.push_back(node_t());
          data[data[node_i].zero].sz = 1;
        }
        data[data[node_i].zero].val = v;
      }
    } else if ((i >> dep) & 1) {
      if (!data[node_i].one) {
        data[node_i].one = data.size();
        data.push_back(node_t(identity));
      }
      set_impl(data[node_i].one, dep - 1, i, v);
    } else {
      if (!data[node_i].zero) {
        data[node_i].zero = data.size();
        data.push_back(node_t(identity));
      }
      set_impl(data[node_i].zero, dep - 1, i, v);
    }
    update_node(node_i);
  }

  T fold(size_t l, size_t r) {
    T lv = identity;
    if (data[0].zero)
      lv = fold_impl(l, r, data[data[0].zero], bitlen, 0ll);
    T rv = identity;
    if (data[0].one)
      rv = fold_impl(l, r, data[data[0].one], bitlen, 1ll << (bitlen - 1));
    return merge(lv, rv);
  }
  T fold_impl(size_t l, size_t r, node_t const &node, size_t dep, size_t k) {
    dep--;
    size_t a = k;
    size_t b = k + (1ll << dep) - 1;
    if (l <= a and b <= r)
      return node.val;
    if (r < a or b < l)
      return identity;
    T lv = identity;
    if (node.zero)
      lv = fold_impl(l, r, data[node.zero], dep, k);
    T rv = identity;
    if (node.one)
      rv = fold_impl(l, r, data[node.one], dep, k | (1ll << dep - 1));
    return merge(lv, rv);
  }
  T operator[](size_t k) {
    node_t node = data[0];
    for (int i = bitlen; i-- > 0;) {
      if ((k >> i) & 1) {
        if (node.one)
          node = data[node.one];
        else
          return identity;
      } else {
        if (node.zero)
          node = data[node.zero];
        else
          return identity;
      }
    }
    return node.val;
  }
};

signed main() {
  using namespace std;
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  constexpr char newl = '\n';

  int n, q;
  cin >> n >> q;
  auto merge = [](auto a, auto b) { return a > b ? b : a; };
  uint ide = (1ll << 31) - 1;
  binary_trie<uint, decltype(merge)> ushi(ide, merge);
  for (int i = 0; i < q; ++i) {
    int com, x, y;
    cin >> com >> x >> y;
    if (com == 0) {
      ushi.set(x, y);
    }
    if (com == 1) {
      uint v = ushi.fold(x, y);
      cout << v << newl;
    }
  }
}
