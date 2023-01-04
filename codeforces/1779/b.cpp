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

  if (n % 2 == 1) {
    cout << "NO\n";
    return;
  }

  cout << "YES\n";
  ll num = -1;
  for (ll i = 1; i <= n; ++i) {
    cout << num << " ";
    num = -num;
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
