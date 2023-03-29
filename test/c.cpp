#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

struct node {
  ll len, pre, suf, l, r;
};

vector<node> tree;
ll n, a[200005];

node combine(node left, node right) {
  if (left.len == -1) return right;
  if (right.len == -1) return left;

  node cur;
  cur.l = left.l;
  cur.r = right.r;

  bool across = a[left.r] <= a[right.l];

  cur.pre = left.pre;
  if (left.pre == left.r - left.l + 1 && across) cur.pre += right.pre;

  cur.suf = right.suf;
  if (right.suf == right.r - right.l + 1 && across) cur.suf += left.suf;

  cur.len = max({left.len, right.len});
  if (across) {
    cur.len = max(cur.len, left.suf + right.pre);
  }

  return cur;
}

void recalc_node(ll id, ll l, ll r) {
  if (l == r) {
    tree[id].len = 1;
    tree[id].pre = 1;
    tree[id].suf = 1;
    tree[id].l = l;
    tree[id].r = r;
    return;
  }

  tree[id] = combine(tree[id * 2], tree[id * 2 + 1]);
}

void build_tree(ll id, ll l, ll r) {
  if (l == r) {
    recalc_node(id, l, r);
    return;
  }

  ll mid = (l + r) / 2;
  build_tree(id * 2, l, mid);
  build_tree(id * 2 + 1, mid + 1, r);
  recalc_node(id, l, r);
}

node query(ll id, ll tl, ll tr, ll l, ll r) {
  if (l <= tl && tr <= r) return tree[id];
  if (tr < l || r < tl) return node{-1, -1, -1, -1, -1};

  ll mid = (tl + tr) / 2;
  return combine(query(id * 2, tl, mid, l, r),
                 query(id * 2 + 1, mid + 1, tr, l, r));
}

void update(ll id, ll tl, ll tr, ll pos, ll val) {
  if (tl == tr) {
    a[pos] = val;
    return;
  }

  ll mid = (tl + tr) / 2;
  if (pos <= mid)
    update(id * 2, tl, mid, pos, val);
  else
    update(id * 2 + 1, mid + 1, tr, pos, val);
  recalc_node(id, tl, tr);
}

void solve() {
  ll q;
  cin >> n >> q;
  tree.resize(4 * n + 1);
  for (ll i = 0; i < n; ++i) cin >> a[i];

  build_tree(1, 0, n - 1);

  // for (ll i = 0; i < 4 * n; ++i) {
  //   cout << tree[i] << endl;
  // }

  for (ll i = 0; i < q; ++i) {
    ll t;
    cin >> t;

    if (t == 1) {
      ll p, x;
      cin >> p >> x;
      p--;

      update(1, 0, n - 1, p, x);
    } else {
      ll l, r;
      cin >> l >> r;
      l--;
      r--;
      ll ans = query(1, 0, n - 1, l, r).len;
      cout << ans << endl;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}
