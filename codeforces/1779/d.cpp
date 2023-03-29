#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

ll n, m, a[200005], b[200005];
ll tree[200005 * 4];

// MISTAKE: there was no need to implement lazy propagation :) instead just see
// where the elements are not equal and then do razors on them instead of the
// whole array;
//
// GOOD THING: I had the right idea;

ll build_tree(ll* arr, ll i, ll tl, ll tr) {
  if (tl == tr) {
    return tree[i] = arr[tl];
  }

  ll mid = (tl + tr) / 2;
  ll mx1 = build_tree(arr, 2 * i, tl, mid);
  ll mx2 = build_tree(arr, 2 * i + 1, mid + 1, tr);

  return tree[i] = max(mx1, mx2);
}

ll query(ll i, ll tl, ll tr, ll ql, ll qr) {
  if (ql > tr || qr < tl) return -1;
  if (ql <= tl && qr >= tr) return tree[i];

  ll mid = (tl + tr) / 2;
  ll mx1 = query(2 * i, tl, mid, ql, qr);
  ll mx2 = query(2 * i + 1, mid + 1, tr, ql, qr);

  return max(mx1, mx2);
}

void solve() {
  cin >> n;
  for (ll i = 0; i < n; ++i) cin >> a[i];
  for (ll i = 0; i < n; ++i) cin >> b[i];

  build_tree(b, 1, 0, n - 1);

  map<ll, vector<ll>> where;
  for (ll i = 0; i < n; ++i) {
    if (a[i] != b[i]) {
      where[b[i]].push_back(i);
    }
  }

  cin >> m;
  map<ll, ll> have;
  for (ll i = 0; i < m; ++i) {
    ll x;
    cin >> x;
    have[x]++;
  }

  for (ll i = 0; i < n; ++i) {
    if (a[i] < b[i]) {
      cout << "NO\n";
      return;
    }
  }

  for (auto& [x, v] : where) {
    ll need = 1;
    for (ll i = 0; i + 1 < v.size(); ++i) {
      ll val = query(1, 0, n - 1, v[i], v[i + 1]);
      if (val > x) {
        ++need;
      }
    }

    if (need > have[x]) {
      cout << "NO\n";

      return;
    }
  }
  cout << "YES\n";
}

int main() {
  ll T;
  cin >> T;
  while (T--) solve();
}
