#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

void solve() {
  ll n, k;
  cin >> n >> k;

  vector<ll> index(n + 1);

  for (ll i = 1; i <= n; ++i) {
    ll x;
    cin >> x;

    index[x] = i;
  }

  ll mn = -1;
  for (ll i = 2; i <= n; ++i) {
    if (index[i] < index[i - 1]) {
      mn = i;
      break;
    }
  }

  if (mn == -1) {
    cout << 0 << endl;
    return;
  }

  ll bad = (n - mn + 1);
  ll ans = (bad + k - 1) / k;
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
