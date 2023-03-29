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
  cin >> n;
  string s;
  cin >> s;

  ll ans = INT_MAX;
  for (char ch = 'a'; ch <= 'z'; ++ch) {
    char it = ch;

    ll t = 0;
    for (ll i = 0; i < n; ++i) {
      if (s[i] != it) ++t;

      if (it != 'z')
        it++;
      else
        it = 'a';
    }
    ans = min(ans, t);
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
