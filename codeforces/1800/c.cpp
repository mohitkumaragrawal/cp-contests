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

  ll ans = 0;
  priority_queue<ll> pq;

  for (ll i = 0; i < n; ++i) {
    ll x;
    cin >> x;

    if (x != 0) {
      pq.push(x);
      continue;
    }

    if (!pq.empty()) {
      ans += pq.top();
      pq.pop();
    }
  }

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
