#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

void solve() {
  ll n;
  cin >> n;

  vector<pair<ll, ll>> ans;

  vector<pair<ll, ll>> vpr;
  for (ll i = 0; i < n; ++i) {
    ll x;
    cin >> x;
    vpr.push_back({x, i + 1});
  }

  sort(all(vpr));

  for (ll i = 1; i < n; ++i) {
    ll prev_num = vpr[i - 1].first;
    ll num = vpr[i].first;

    if (num % prev_num == 0) {
      continue;
    } else if (prev_num > num) {
      ans.push_back({vpr[i].second, (prev_num - num)});
      vpr[i].first = prev_num;
      continue;
    }

    ll new_num = num - (num % prev_num) + prev_num;
    ans.push_back({vpr[i].second, (new_num - num)});
    vpr[i].first = new_num;
  }

  cout << ans.size() << '\n';
  for (auto [i, x] : ans) {
    cout << i << " " << x << '\n';
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
