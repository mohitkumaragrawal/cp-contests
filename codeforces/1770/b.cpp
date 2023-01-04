#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

void solve() {
  ll n, k;
  cin >> n >> k;
  if (k == 1) {
    for (ll i = 1; i <= n; ++i) {
      cout << i << " ";
    }
    cout << endl;
    return;
  }

  vector<ll> a(n, 0);

  ll seg = n / k;

  ll large = n;
  ll small = 1;

  for (ll i = 0; i < seg; ++i) {
    ll start = i * k;
    ll last = start + k - 1;

    a[start] = large;
    a[last] = small;

    large--;
    small++;
  }

  for (ll i = 0; i < n; ++i) {
    if (a[i] == 0) {
      a[i] = small;
      small++;
    }
  }
  for (ll i = 0; i < n; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
