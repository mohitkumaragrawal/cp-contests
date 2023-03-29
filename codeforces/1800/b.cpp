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

  string s;
  cin >> s;

  map<char, int> mp;

  ll ans = 0;

  for (int i = 0; i < n; ++i) {
    char ch = s[i];
    char CH = islower(ch) ? toupper(ch) : tolower(ch);

    if (mp[CH] > 0) {
      ans++;
      mp[CH]--;
    } else {
      mp[ch]++;
    }
  }

  for (auto [ch, cnt] : mp) {
    if (k == 0) break;
    ll delta = min<ll>(cnt / 2, k);
    ans += delta;
    k -= delta;
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
