#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

template <typename num_t>
struct segtree {
  int n, depth;
  vector<num_t> tree, lazy;

  void init(int s, long long* arr) {
    n = s;
    tree = vector<num_t>(4 * s, 0);
    lazy = vector<num_t>(4 * s, 0);
    init(0, 0, n - 1, arr);
  }

  num_t init(int i, int l, int r, long long* arr) {
    if (l == r) return tree[i] = arr[l];

    int mid = (l + r) / 2;
    num_t a = init(2 * i + 1, l, mid, arr),
          b = init(2 * i + 2, mid + 1, r, arr);
    return tree[i] = a.op(b);
  }

  void update(int l, int r, num_t v) {
    if (l > r) return;
    update(0, 0, n - 1, l, r, v);
  }

  num_t update(int i, int tl, int tr, int ql, int qr, num_t v) {
    eval_lazy(i, tl, tr);

    if (tr < ql || qr < tl) return tree[i];
    if (ql <= tl && tr <= qr) {
      lazy[i] = lazy[i].val + v.val;
      eval_lazy(i, tl, tr);
      return tree[i];
    }

    int mid = (tl + tr) / 2;
    num_t a = update(2 * i + 1, tl, mid, ql, qr, v),
          b = update(2 * i + 2, mid + 1, tr, ql, qr, v);
    return tree[i] = a.op(b);
  }

  num_t query(int l, int r) {
    if (l > r) return num_t::null_v;
    return query(0, 0, n - 1, l, r);
  }

  num_t query(int i, int tl, int tr, int ql, int qr) {
    eval_lazy(i, tl, tr);

    if (ql <= tl && tr <= qr) return tree[i];
    if (tr < ql || qr < tl) return num_t::null_v;

    int mid = (tl + tr) / 2;
    num_t a = query(2 * i + 1, tl, mid, ql, qr),
          b = query(2 * i + 2, mid + 1, tr, ql, qr);
    return a.op(b);
  }

  void eval_lazy(int i, int l, int r) {
    tree[i] = tree[i].lazy_op(lazy[i], (r - l + 1));
    if (l != r) {
      lazy[i * 2 + 1] = lazy[i].val + lazy[i * 2 + 1].val;
      lazy[i * 2 + 2] = lazy[i].val + lazy[i * 2 + 2].val;
    }

    lazy[i] = num_t();
  }
};

struct min_t {
  long long val;
  static const long long null_v = 9223372036854775807LL;

  min_t() : val(0) {}
  min_t(long long v) : val(v) {}

  min_t op(min_t& other) { return min_t(min(val, other.val)); }
  min_t lazy_op(min_t& v, int size) { return min_t(val + v.val); }
};

segtree<min_t> st;
void solve() {
  ll n, k;
  cin >> n >> k;

  vector<pair<ll, ll>> e(n);
  for (ll i = 0; i < n; ++i) {
    cin >> e[i].first;
  }
  for (ll i = 0; i < n; ++i) {
    cin >> e[i].second;
  }
  sort(all(e));

  ll power[n];
  for (ll i = 0; i < n; ++i) {
    power[i] = e[i].second;
  }

  vector<ll> health(n);
  for (ll i = 0; i < n; ++i) {
    health[i] = e[i].first;
  }

  st.init(n, power);

  ll t = 0;
  ll x = k;
  ll gp = k;
  ll killed = 0;

  while (t < k) {
    ll idx = upper_bound(all(health), x) - health.begin();
    killed = max(killed, idx);

    if (idx >= n) {
      cout << "YES\n";
      return;
    }

    ll mp = st.query(idx, n - 1).val;

    gp -= mp;
    x += gp;

    t += mp;
  }

  if (killed == n) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll t;
  cin >> t;
  while (t--) solve();
}
