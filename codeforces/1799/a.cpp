#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

void solve() {
  ll n, m;
  cin >> n >> m;

  ll time = 0, last_idx = n;
  map<ll, bool> in;

  vector<ll> ans(n + 1, -1);

  for (ll i = 0; i < m; ++i) {
    ll pm;
    cin >> pm;
    time++;

    if (!in[pm]) {
      in[pm] = true;

      if (last_idx <= n && last_idx >= 1) {
        ans[last_idx] = time;
        last_idx--;
      }
    }
  }

  for (ll i = 1; i <= n; ++i) cout << ans[i] << " \n"[i == n];
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
