#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

ll n, m;
vector<pll> I;

bool check(ll x) {
  ll prev = INT_MIN;
  ll j = 0;
  ll cnt = 0;

  while (cnt < n && j < m) {
    ll np = max(prev + x, I[j].first);

    if (np > I[j].second) {
      j++;
      continue;
    }

    ++cnt;
    prev = np;
  }

  return cnt == n;
}

void solve() {
  cin >> n >> m;
  for (ll i = 0; i < m; ++i) {
    ll l, r;
    cin >> l >> r;
    I.push_back({l, r});
  }

  sort(all(I));

  ll low = 1, high = 1e18 + 1, ans = 0;

  while (low <= high) {
    ll mid = low + (high - low) / 2;
    if (check(mid)) {
      ans = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}
