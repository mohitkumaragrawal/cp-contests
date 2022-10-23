#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

void solve() {
  ll n;
  cin >> n;

  string s;
  cin >> s;

  ll op = 0;
  ll x = 0;

  for (ll i = 0; i < n - 1; ++i) {
    ll a = (s[i] - '0') ^ x;
    ll b = (s[i+1] - '0') ^ x;

    if (a == 1 && b == 0) {
      op ++;
      x ^= 1;
    }
  }

  cout << op << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll t;
  cin >> t;
  while (t--)
    solve();
}
