#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

void solve() {
  ll n, m;
  cin >> n >> m;

  vector<vector<ll>> a(n, vector<ll>(m));
  vector<int> popcnt(n, 0);

  ll sum = 0;
  for (ll i = 0; i < n; ++i) {
    for (ll j = 0; j < m; ++j) {
      cin >> a[i][j];
      sum += a[i][j];

      popcnt[i] += a[i][j];
    }
  }

  if (sum % n != 0) {
    cout << "-1\n";
    return;
  }

  ll avg = sum / n;
  vector<ll> big, small;

  for (ll i = 0; i < n; ++i) {
    if (popcnt[i] > avg) {
      big.push_back(i);
    } else if (popcnt[i] < avg) {
      small.push_back(i);
    }
  }

  vector<tuple<ll, ll, ll>> ans;
  while (!big.empty()) {
    ll x = big.back();
    ll y = small.back();

    ll delta = min(abs(avg - popcnt[x]), abs(avg - popcnt[y]));
    for (ll i = 0; i < m; ++i) {
      if (delta == 0) break;

      if (a[x][i] == 1 && a[y][i] == 0) {
        swap(a[x][i], a[y][i]);
        popcnt[x]--;
        popcnt[y]++;
        delta = min(abs(avg - popcnt[x]), abs(avg - popcnt[y]));

        ans.push_back({x + 1, y + 1, i + 1});
      }
    }

    if (popcnt[x] == avg) {
      big.pop_back();
    }

    if (popcnt[y] == avg) {
      small.pop_back();
    }
  }

  cout << ans.size() << endl;
  for (auto& [x, y, z] : ans) {
    cout << x << " " << y << " " << z << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
