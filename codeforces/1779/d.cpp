#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

ll n, m, a[200005], b[200005], x[200005];
vector<ll> tree, lazy;

void eval_lazy(ll i) {
  if (lazy[i] == -1) return;

  if (lazy[2 * i] == -1) {
    lazy[2 * i] = lazy[i];
  } else {
    lazy[2 * i] = min(lazy[2 * i], lazy[i]);
  }
  if (lazy[2 * i + 1] == -1) {
    lazy[2 * i + 1] = lazy[i];
  } else {
    lazy[2 * i + 1] = min(lazy[2 * i + 1], lazy[i]);
  }
}

ll init(ll i, ll l, ll r) {
  if (l == r) {
    return tree[i] = a[l];
  }
  ll mid = (l + r) / 2;
  ll mx1 = init(2 * i, l, mid);
  ll mx2 = init(2 * i, mid + 1, r);

  return tree[i] = max(mx1, mx2);
}

ll query(ll i, ll l, ll r, ll ql, ll qr) {
  if (ql > r || qr < l) return -1;
  if (ql >= l && qr <= r) {
    if (lazy[i] != -1 && tree[i] >= lazy[i]) {
      return lazy[i];
    } else {
      return tree[i];
    }
  }

  eval_lazy(i);
  ll mid = (l + r) / 2;
  ll mx1 = query(2 * i, l, mid, ql, qr);
  ll mx2 = query(2 * i + 1, mid + 1, r, ql, qr);

  return max(mx1, mx2);
}

void update(ll i, ll l, ll r, ll ql, ll qr, ll val) {
  if (ql > r || qr < l) return;

  if (ql >= l && qr <= r) {
    if (lazy[i] == -1)
      lazy[i] = val;
    else
      lazy[i] = min(lazy[i], val);

    return;
  }

  eval_lazy(i);

  ll mid = (l + r) / 2;
  update(2 * i, l, mid, ql, qr, val);
  update(2 * i + 1, mid + 1, r, ql, qr, val);
}

struct max_t {
  long long val;
  static const long long null_v = -9223372036854775807LL;

  max_t() : val(0) {}
  max_t(long long v) : val(v) {}
  max_t op(max_t& other) { return max_t(max(val, other.val)); }
  max_t lazy_op(max_t& v, int size) { return max_t(val + v.val); }
};

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

segtree<max_t> st;

#ifdef _DEBUG
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void solve() {
  cin >> n;

  tree.resize(4 * n + 10);
  lazy.resize(4 * n + 10, -1);

  for (ll i = 0; i < n; ++i) cin >> a[i];
  for (ll i = 0; i < n; ++i) cin >> b[i];

  cin >> m;

  for (ll i = 0; i < m; ++i) cin >> x[i];

  init(1, 0, n - 1);
  st.init(n, b);

  map<ll, vector<ll>, greater<ll>> mp;
  for (ll i = 0; i < n; ++i) {
    mp[b[i]].push_back(i);
  }

  // sort(x, x + m, greater<ll>());
  //
  map<ll, ll, greater<ll>> xmp;
  for (ll i = 0; i < m; ++i) xmp[x[i]]++;

  for (auto [r, count] : xmp) {
    if (mp[r].empty()) continue;

    dbg(r, mp[r].size());

    auto& v = mp[r];
    if (v.size() == 1) {
      update(1, 0, n - 1, v[0], v[0], r);
      continue;
    }

    ll left = 0, right = 0, ops = 0;

    while (right < v.size() - 1) {
      ll mx = st.query(v[left], v[right + 1]).val;
      if (mx <= r) {
        right++;
        continue;
      }

      update(1, 0, n - 1, v[left], v[right], r);
      dbg(v[left], v[right], r);
      left = right + 1;
      right++;
      ops++;
    }

    if (left != v.size()) {
      update(1, 0, n - 1, v[left], v.back(), r);
      dbg(v[left], v.back(), r);
      ops++;
    }

    if (ops > count) {
      dbg(227);
      dbg(ops, count);
      cout << "NO\n";
      return;
    }
  }

  for (ll i = 0; i < n; ++i) {
    ll val = query(1, 0, n - 1, i, i);
    if (val != b[i]) {
      dbg(236, val, b[i], i);
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}
