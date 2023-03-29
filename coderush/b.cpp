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

  ll a[n];
  ll even_c = 0;
  for (ll i = 0; i < n; ++i) {
    cin >> a[i];

    if (a[i] % 2 == 0) {
      even_c++;
    }
  }

  auto odd_c = n - even_c;

  if (even_c < odd_c) {
    cout << even_c << endl;
  } else {
    cout << odd_c << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}
