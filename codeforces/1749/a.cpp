#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "

using namespace std;
using ll = long long;

const ll MOD = 1e9+7;

void solve() {
  ll n, m;
  cin >> n >> m;

  for (ll i = 0; i < m; ++i) {
    ll x, y;
    cin >> x >> y;
  }

  if (m >= n) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;

  while (T--) solve();
}
