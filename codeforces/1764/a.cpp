#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

void solve() {
  ll n;
  cin >> n;

  vector<ll> a(n + 1);
  for (ll i = 1; i <= n; ++i) cin >> a[i];
  //
  // set<ll> s;
  // vector<ll> b(n + 1);
  // b[0] = -1;
  //
  // for (ll i = 1; i <= n; ++i) {
  //   s.insert(a[i]);
  //
  //   b[i] = i - s.size() - 1;
  // }

  cout << 1 << " " << n << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
