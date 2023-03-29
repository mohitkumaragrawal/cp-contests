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
  ll n = s.size();

  // bool all_b = all_of(all(s), [](char ch) { return ch == 'b'; });
  //
  // if (all_b) {
  //   cout << "b" << s.substr(1, s.size() - 2) << "b\n";
  //   return;
  // }
  //
  for (ll i = 1; i < n - 1; ++i) {
    if (s[i] == 'a') {
      cout << s.substr(0, i) << " "
           << "a"
           << " " << s.substr(i + 1) << "\n";
      return;
    }
  }

  // if (s[0] == 'a' || s[n - 1] == 'a') {
  cout << s[0] << " " << s.substr(1, s.size() - 2) << " " << s[n - 1] << '\n';
  // }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
