#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

ll n;
ll likes[5005];

void solve() {
  cin >> n;
  for (ll i = 1; i <= n; ++i) cin >> likes[i];

  for (ll i = 1; i <= n; ++i) {
    ll node = likes[i];

    for (ll j = 2; j <= 3; ++j) {
      if (node == i) {
        node = 0;
        break;
      }
      node = likes[node];
    }

    if (node == i) {
      cout << "YES\n";
      return;
    }
  }

  cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}
