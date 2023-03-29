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
  string s;
  cin >> n >> s;

  string t = s.substr(2);
  ll ans = 0;

  for (ll i = 0; i < n - 2; ++i) {
    if (t[i] == s[i]) continue;
    ans++;
    t[i] = s[i];
  }
  cout << ans + 1 << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
