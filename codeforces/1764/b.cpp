#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

void solve() {
  ll n;
  cin >> n;

  vector<ll> a(n);
  for (ll& i : a) cin >> i;

  ll g = 0;
  for (ll x : a) {
    g = __gcd(x, g);
  }

  ll m = *max_element(all(a));
  cout << m / g << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
