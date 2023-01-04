#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

void solve() {
  int n;
  string s;

  cin >> n >> s;

  int l_cnt = 0, r_cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'L')
      l_cnt++;
    else
      r_cnt++;
  }

  if (l_cnt == 0 || r_cnt == 0) {
    cout << "-1\n";
    return;
  }

  for (int i = 0; i < n - 1; ++i) {
    if (s[i] == 'L' && s[i + 1] == 'R') {
      cout << i + 1 << '\n';
      return;
    }
  }

  cout << "0\n";
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
