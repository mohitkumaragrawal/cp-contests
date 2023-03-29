#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

void solve() {
  ll n;
  cin >> n;

  vector<vector<ll>> parent(n + 1, vector<ll>(21));
  vector<ll> depth(n + 1);

  ll ds = 0, de = 0;
  ll curr = 0;

  auto lift = [&](ll a, ll x) {
    ll it = a;
    for (ll j = 0; j < 21; ++j) {
      if ((x >> j) & 1) it = parent[it][j];
    }
    return it;
  };

  auto lca = [&](ll a, ll b) {
    if (depth[b] < depth[a]) swap(a, b);
    b = lift(b, depth[b] - depth[a]);
    if (a == b) return a;

    for (ll j = 20; j >= 0; --j) {
      ll na = parent[a][j];
      ll nb = parent[b][j];
      if (na != nb) {
        a = na;
        b = nb;
      }
    }

    return parent[a][0];
  };

  auto dist = [&](ll a, ll b) {
    ll p = lca(a, b);
    return (depth[a] - depth[p]) + (depth[b] - depth[p]);
  };

  for (ll i = 0; i < n; ++i) {
    ll a, b;
    cin >> a >> b;

    depth[a] = 1 + depth[b];

    parent[a][0] = b;

    for (ll j = 1; j < 21; ++j) {
      ll x = parent[a][j - 1];
      parent[a][j] = parent[x][j - 1];
    }

    ll d1 = dist(ds, a);
    ll d2 = dist(de, a);

    ll D = max(d1, d2);
    if (D <= curr) {
      cout << curr << " ";
      continue;
    }

    if (d1 > d2) {
      de = a;
    } else {
      ds = a;
    }

    curr = D;
    cout << D << " ";
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
