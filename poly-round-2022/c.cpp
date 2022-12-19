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

  ll dp[n + 1];
  fill(dp, dp + n + 1, 1);

  for (ll i = 1; i < n - 1; ++i) {
    if (s[i] == s[i - 1]) {
      dp[i] = dp[i - 1];
    } else {
      dp[i] = (i + 1);
    }
  }

  for (ll i = 0; i < n - 1; ++i) {
    cout << dp[i] << " ";
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
