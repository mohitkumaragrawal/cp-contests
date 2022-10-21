#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "

using namespace std;
using ll = long long;

const ll MOD = 1e9+7;

void solve() {
  ll n;
  cin >> n;

  vector<ll> a(n), b(n);
  for (ll&i: a) cin >> i;
  for (ll& i: b) cin >> i;

  ll ans = 0;
  for (ll i : a) ans += i;
  for (ll i: b) ans += i;

  ans -= *max_element(all(b));
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  
  ll T;
  cin >> T;
  while (T--) solve();
}
