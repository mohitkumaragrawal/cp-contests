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

  map<ll, vector<pll>> mp;
  for (ll i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    mp[y].push_back({x, i + 1});
  }

  for (auto &p : mp) {
    sort(all(p.second));
  }

  vector<ll> ans;
  vector<ll> v(202);

  for (ll i = 1; i <= 200; ++i) {
    if (mp[i].empty()) continue;
    auto &vec = mp[i];

    for (ll a = vec.size() - 1; a >= 0; --a) {
      auto [j, id] = vec[a];
      ll mx = *max_element(v.begin() + j, v.begin() + i + 1);

      if (mx >= k) {
        ans.push_back(id);

        for (ll t = a - 1; t >= 0; --t) {
          auto [x, id2] = vec[t];
          ans.push_back(id2);
        }

        break;
      }

      for (ll t = j; t <= i; ++t) v[t]++;
    }
  }

  cout << ans.size() << endl;
  for (auto &x : ans) cout << x << " ";
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}
