#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

ll n, m;
string s;

map<ll, vector<pll>> diff;
map<ll, vector<pll>> sum;

void solve() {
  cin >> n >> m;
  cin >> s;

  ll px, py;

  for (ll i = 0; i < n; ++i) {
    ll x, y;
    cin >> x >> y;

    if (i == 0) {
      px = x;
      py = y;
    }

    diff[x - y].emplace_back(x, y);
    sum[x + y].emplace_back(x, y);
  }

  for (auto& [x, v] : diff) sort(all(v));
  for (auto& [x, v] : sum) sort(all(v));

  map<pll, bool> removed;

  for (ll i = 0; i < m; ++i) {
    if (s[i] == 'A') {
      auto& v = diff[px - py];

      auto itr = lower_bound(all(v), make_pair(px, py));
      ll id = itr - v.begin();
      if (id < v.size()) {
        ll j = id + 1;

        while (j < v.size()) j++;
        if (j < v.size()) {
          px = v[j].first;
          py = v[j].second;
          v.erase(itr);
        }
      }
    } else if (s[i] == 'B') {
      auto& v = sum[px + py];

      auto itr = lower_bound(all(v), make_pair(px, py));
      ll id = itr - v.begin();
      if (id < v.size()) {
        ll j = id + 1;

        while (j < v.size() && removed[v[j]]) j++;
        if (j < v.size()) {
          px = v[j].first;
          py = v[j].second;
          v.erase(itr);
        }
      }
    } else if (s[i] == 'C') {
      auto& v = sum[px + py];

      auto itr = lower_bound(all(v), make_pair(px, py));
      ll id = itr - v.begin();
      if (id < v.size()) {
        ll j = id - 1;

        while (j >= 0 && removed[v[j]]) j--;
        if (j >= 0) {
          px = v[j].first;
          py = v[j].second;
          v.erase(itr);
        }
      }
    } else {
      auto& v = diff[px - py];

      auto itr = lower_bound(all(v), make_pair(px, py));
      ll id = itr - v.begin();
      if (id < v.size()) {
        ll j = id - 1;

        while (j >= 0 && removed[v[j]]) j--;
        if (j >= 0) {
          px = v[j].first;
          py = v[j].second;
          v.erase(itr);
        }
      }
    }
  }

  cout << px << " " << py << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}
