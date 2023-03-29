#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case " << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

void solve(ll t) {
  ll n;
  cin >> n;
  string a, b;
  cin >> a >> b;

  vector<vector<bool>> dp(n, vector<bool>(n, false));

  for (ll i = 0; i < n; ++i) {
    dp[i][i] = a[0] == b[i];
  }

  for (ll length = 2; length <= n; ++length) {
    for (ll i = 0; i < n; ++i) {
      ll j = i + length - 1;
      if (j >= n) continue;

      ll matched = n - (j - i + 1);
      if (a[n - matched - 1] == b[i]) {
        dp[i][j] = dp[i][j] || dp[i + 1][j];
      }

      if (a[n - matched - 1] == b[j]) {
        dp[i][j] = dp[i][j] || dp[i][j - 1];
      }
    }
  }

  if (dp[0][n - 1]) {
    OUT(t) << "YES" << endl;
  } else {
    OUT(t) << "NO" << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;

  for (ll t = 1; t <= T; ++t) solve(t);
}
