#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

void solve() {
  ll mat[2][2];
  ll m = 1e+17;
  for (ll i = 0; i < 2; ++i) {
    for (ll j = 0; j < 2; ++j) {
      cin >> mat[i][j];
      m = min(m, mat[i][j]);
    }
  }

  while (mat[0][0] != m) {
    ll cp[2][2];
    for (ll i = 0; i < 2; ++i) {
      for (ll j = 0; j < 2; ++j) {
        cp[i][j] = mat[i][j];
      }
    }

    mat[0][0] = cp[1][0];
    mat[0][1] = cp[0][0];
    mat[1][0] = cp[1][1];
    mat[1][1] = cp[0][1];
  }

  for (ll i = 0; i < 2; ++i) {
    if (mat[i][0] > mat[i][1]) {
      cout << "NO\n";
      return;
    }
  }

  for (ll i = 0; i < 2; ++i) {
    if (mat[0][i] > mat[1][i]) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
