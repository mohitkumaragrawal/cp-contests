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

  ll pc = -1;

  for (ll i = (n + 1) / 2; i < n; ++i) {
    ll j = (n - 1) - i;
    if (s[i] != s[j]) {
      if (pc == -1) {
        pc = i;
      } else {
        if (pc != i - 1) {
          cout << "NO\n";
          return;
        }
        pc = i;
      }
    }
  }

  cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
