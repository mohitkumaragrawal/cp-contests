#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

mt19937_64 rng;

void solve() {
  ll n, m;
  cin >> n >> m;

  vector<vector<ll>> mat(n, vector<ll>(m));

  for (ll num = 1; num <= 31; ++num) {
    ll idx = 2 * num - 1;

    ll k = rng();

    for (ll i = 0; i < n; ++i) {
      if (i % 63 == 0) k = rng();

      for (ll j = 0; j < m; ++j) {
        ll bit = (k >> (i % 63)) & 1;
        if (bit) mat[i][j] |= (1LL << idx);
      }
    }

    idx = 2 * num;
    for (ll j = 0; j < m; ++j) {
      if (j % 63 == 0) k = rng();
      for (ll i = 0; i < n; ++i) {
        ll bit = (k >> (j % 63)) & 1;
        if (bit) mat[i][j] |= (1LL << idx);
      }
    }
  }

  set<ll> dis;
  for (ll i = 0; i < n; ++i) {
    for (ll j = 0; j < m; ++j) {
      dis.insert(mat[i][j]);
    }
  }

  cout << dis.size() << "\n";

  for (ll i = 0; i < n; ++i) {
    for (ll j = 0; j < m; ++j) {
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
