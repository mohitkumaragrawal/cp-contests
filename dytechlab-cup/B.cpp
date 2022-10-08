#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

ll f(ll x) {
  if (x == 0) return 0;
  ll rt = (ll)floor(sqrt(x));
  ll ans = 3 * (rt - 1);

  ans += (x / rt) - rt + 1;

  return ans;
}

void solve() {
  ll l, r;
  cin >> l >> r;

  cout << f(r) - f(l - 1) << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}