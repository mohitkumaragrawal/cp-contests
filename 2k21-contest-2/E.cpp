#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll big = 1e+5;

void solve() {
  ll min_x = -big, max_x = big, min_y = -big, max_y = big;

  ll n;
  cin >> n;

  while (n--) {
    ll x, y, f1, f2, f3, f4;
    cin >> x >> y >> f1 >> f2 >> f3 >> f4;

    if (f1 == 0) {
      min_x = max(min_x, x);
    }
    if (f2 == 0) {
      max_y = min(max_y, y);
    }
    if (f3 == 0) {
      max_x = min(max_x, x);
    }
    if (f4 == 0) {
      min_y = max(min_y, y);
    }
  }

  if (max_x < min_x || max_y < min_y) {
    cout << 0 << endl;
    return;
  }

  cout << 1 << " " << max_x << " " << max_y << endl;
}

int main() {
  int T;
  cin >> T;

  while (T--) solve();
}