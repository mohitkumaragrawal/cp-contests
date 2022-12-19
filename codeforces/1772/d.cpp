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
  for (ll i = 0; i < n; ++i) cin >> a[i];

  bool sorted = true;
  for (ll i = 1; i < n; ++i) {
    if (a[i] < a[i - 1]) {
      sorted = false;
      break;
    }
  }
  if (sorted) {
    cout << "0\n";
    return;
  }

  bool rev_sorted = true;
  for (ll i = 0; i < n - 1; ++i) {
    if (a[i] < a[i + 1]) {
      rev_sorted = false;
      break;
    }
  }
  if (rev_sorted) {
    cout << a[0] << '\n';
    return;
  }

  ll first = a[0];
  ll INF = 1e17;
  ll mx = 0, mn = INF;
  bool eq = false;
  for (ll i = 1; i < n; ++i) {
    if (a[i] > first) {
      mn = min(mn, a[i]);
    } else if (a[i] < first) {
      mx = max(mx, a[i]);
    } else {
      eq = true;
    }
  }

  // if (mx == 0 || mn == INF) {
  //   if (!eq) {
  //     cout << "-1\n";
  //     return;
  //   }
  // }

  ll mx_x = (mn + a[0]) / 2;
  ll mn_x = (mx + a[0] + 1) / 2;

  ll x;
  if (mx_x >= mn_x) {
    x = mn_x;
  } else {
    cout << "-1\n";
    return;
  }

  vector<ll> b(n);
  for (ll i = 0; i < n; ++i) {
    b[i] = abs(a[i] - x);
  }

  sorted = true;
  for (ll i = 1; i < n; ++i) {
    if (b[i] < b[i - 1]) {
      sorted = false;
      break;
    }
  }
  if (sorted) {
    cout << x << '\n';
    return;
    // } else {
    //   cout << -1 << '\n';
  }

  x = mx_x;
  for (ll i = 0; i < n; ++i) {
    b[i] = abs(a[i] - x);
  }

  sorted = true;
  for (ll i = 1; i < n; ++i) {
    if (b[i] < b[i - 1]) {
      sorted = false;
      break;
    }
  }
  if (sorted) {
    cout << x << '\n';
    return;
  }

  cout << "-1\n";
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
