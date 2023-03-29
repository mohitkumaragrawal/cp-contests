#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

void solve() {
  string s;
  cin >> s;

  map<char, int> mp;
  for (auto c : s) mp[c]++;

  ll max_count = 0;
  for (auto [k, v] : mp) max_count = max(max_count, (ll)v);

  if (max_count <= 2) {
    cout << 4 << endl;
  } else if (max_count == 3) {
    cout << 6 << endl;
  } else {
    cout << -1 << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
