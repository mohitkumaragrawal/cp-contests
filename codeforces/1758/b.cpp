#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;
void solve() {
  ll n;
  cin >> n;

  if (n % 2 == 1) {
    for (ll i = 0; i < n; ++i) {
      cout << 2 << " ";
    }
    cout << endl;
    return;
  }

  if (n == 2) {
    cout << "1 3" << endl;
    return;
  }

  cout << "2 4 6 ";
  for (ll i = 0; i < n - 3; ++i) {
    cout << "4 ";
  }
  cout << endl;

  return;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
