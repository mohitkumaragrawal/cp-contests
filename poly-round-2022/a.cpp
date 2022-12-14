#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

void solve() {
  ll n;
  cin >> n;
  string s;
  cin >> s;

  string op(n, '-');
  ll x = (s[0] == '1');
  for (ll i = 1; i < n; ++i) {
    if (s[i] == '1') {
      if (x == 0) {
        op[i] = '+';
        x++;
      } else {
        op[i] = '-';
        x--;
      }
    }
  }

  cout << op.substr(1) << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
