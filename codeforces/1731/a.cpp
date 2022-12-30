#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

void solve() {
  ll n;
  cin >> n;

  ll p = 1;
  for (ll i = 0; i < n; ++i) {
    ll x;
    cin >> x;

    p *= x;
  }

  p += (n - 1);

  cout << p * 2022 << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
