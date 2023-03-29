#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

ll k = 1000000000000LL;

void solve() {
  string s;
  cin >> s;
  ll n = s.size();

  ll ans = 0;

  ll l = 0, r = n - 1;

  vector<ll> pre(n);
  pre[0] = s[0] == '1' ? 1 : 0;

  for (ll i = 1; i < n; i++) {
    pre[i] = pre[i - 1] + (s[i] == '1' ? 1 : 0);
  }

  while (r > l) {
    if (s[l] == '0') {
      l++;
      continue;
    }

    if (s[r] == '1') {
      r--;
      continue;
    }

    ll ones = pre[r - 1] - pre[l];
    ll L = (r - 1) - (l + 1) + 1;

    ll tmp = 2 * (k + 1);

    ll o_swap = (L - ones);
    ll z_swap = ones;

    tmp = min(tmp, o_swap * k + k + 1);
    tmp = min(tmp, z_swap * k + k + 1);
    tmp = min(tmp, (o_swap + z_swap + 1) * k);

    ans += tmp;

    l++;
    r--;
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
