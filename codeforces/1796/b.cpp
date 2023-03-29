#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

void solve() {
  string a, b;
  cin >> a >> b;

  ll n = a.size(), m = b.size();

  if (a[0] == b[0]) {
    cout << "YES\n";
    cout << a[0] << "*\n";
    return;
  }

  if (a[n - 1] == b[m - 1]) {
    cout << "YES\n";
    cout << '*' << a[n - 1] << '\n';
    return;
  }

  for (ll i = 0; i < n - 1; ++i) {
    for (ll j = 0; j < m - 1; ++j) {
      if (a[i] == b[j] && a[i + 1] == b[j + 1]) {
        cout << "YES\n";
        cout << '*' << a[i] << a[i + 1] << "*\n";
        return;
      }
    }
  }

  cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
