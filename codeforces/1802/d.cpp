#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

// don't trust code on stackoverflow
template <typename Set>
auto find_closest(Set& set, const typename Set::value_type& value)
    -> decltype(set.begin()) {
  const auto it = set.lower_bound(value);
  if (it == set.begin()) return it;

  const auto prev_it = std::prev(it);
  return (it == set.end() || value - *prev_it <= *it - value) ? prev_it : it;
}

void solve() {
  ll n;
  cin >> n;

  vector<pll> vp(n);
  for (auto& [a, b] : vp) cin >> a >> b;
  sort(all(vp));

  vector<ll> suf_max(n + 1);

  for (ll i = n - 1; i >= 0; --i) {
    suf_max[i] = max(suf_max[i + 1], vp[i].second);
  }

  ll ans = INT_MAX;

  set<ll> st;

  for (ll i = 0; i < n; ++i) {
    ll m1 = vp[i].first;

    ll m21 = suf_max[i + 1];
    if (i + 1 < n) ans = min(ans, abs(m21 - m1));

    if (!st.empty()) {
      auto it = find_closest(st, m1);
      ll x = max(*it, m21);

      ans = min(ans, abs(x - m1));
    }

    st.insert(vp[i].second);
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
