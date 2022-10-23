#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
  ll n, _;
  cin >> n >> _;

  vector<ll> arr(n + 1);
  for (ll i = 1; i <= n; ++i) cin >> arr[i];

  vector<ll> ps(n + 1), px(n + 1);
  ps[0] = 0;
  px[0] = 0;
  for (ll i = 1; i <= n; ++i) ps[i] = ps[i - 1] + arr[i];
  for (ll i = 1; i <= n; ++i) px[i] = px[i - 1] ^ arr[i];

  ll left, right;
  cin >> left >> right;

  ll val = (ps[right] - ps[left - 1]) - (px[right] ^ px[left - 1]);

  while (right > left) {
    ll l_val = (ps[right] - ps[left]) - (px[right] ^ px[left]);
    ll r_val = (ps[right - 1] - ps[left - 1]) - (px[right - 1] ^ px[left - 1]);

    if (l_val < val && r_val < val) break;

    if (l_val <= r_val) {
      right--;
    } else {
      left++;
    }
  }

  cout << left << " " << right << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll t;
  cin >> t;
  while (t--) solve();
}