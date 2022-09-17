#include <bits/stdc++.h>
using namespace std;

using ll = unsigned long long;

ll n, k, A, B;

int main() {
  cin >> n >> k >> A >> B;

  if (k == 1) {
    ll res = (n - 1) * A;
    cout << res << endl;
    return 0;
  }

  ll x = n;
  ll ans = 0;
  while (x > 1) {
    ll m = x % k;

    if (m != 0) {
      x -= m;
      ans += A * m;
    } else {
      ll nx = x / k;
      ans += min(B, (x - nx) * A);
      x = nx;
    }
  }

  if (x == 0) {
    ans -= A;
  }

  cout << ans << endl;
}