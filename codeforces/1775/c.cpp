#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

void solve() {
  ll n, x;
  cin >> n >> x;

  bool ok = true;
  ll m_min = n, m_max = 5e18 + 100;

  for (ll i = 0; i < 63; ++i) {
    bool x_set = (x >> i) & 1;
    bool n_set = (n >> i) & 1;

    if (x_set && !n_set) {
      ok = false;
      break;
    }

    if (!x_set && !n_set) {
      continue;
    }

    ll y = n;
    for (ll j = 0; j < i; ++j) {
      y |= (1LL << j);
    }

    if (x_set) {
      m_max = min(m_max, y);
    } else {
      m_min = max(m_min, y + 1);
    }
  }

  if (!ok) {
    cout << "-1\n";
    return;
  }

  if (m_min > m_max) {
    cout << "-1\n";
    return;
  }

  cout << m_min << "\n";
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
