#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

ll arr[100'005];
ll px[100'005], ps[100'005];
ll jmp[100'005];

void solve() {
  ll n, _;
  cin >> n >> _;

  for (ll i = 1; i <= n; ++i) cin >> arr[i];

  jmp[n+1] = n+1;
  for (ll i = n; i >= 0; --i) {
    if (arr[i] == 0) {
      jmp[i] = jmp[i+1];
    } else {
      jmp[i] = i;
    }
  }

  ps[0] = 0;
  px[0] = 0;
  for (ll i = 1; i <= n; ++i) ps[i] = ps[i - 1] + arr[i];
  for (ll i = 1; i <= n; ++i) px[i] = px[i - 1] ^ arr[i];

  auto calc_val = [&](ll l, ll r) -> ll {
    return (ps[r] - ps[l - 1]) - (px[r] ^ px[l - 1]);
  };

  ll left, right;
  while (_--) {
    cin >> left >> right;

    ll val = calc_val(left, right);

    int left_removal_count = 0;
    ll ans_l = jmp[left] > right ? right : jmp[left], ans_r = right;

    for (ll l = jmp[left]; l <= right; l = jmp[l + 1]) {
      if (left_removal_count >= 32) break;
      if (calc_val(l, right) < val) break;

      if (arr[l] != 0) ++left_removal_count;

      ll r = right;
      ll low = l, high = right;
      while (high >= low) {
        ll mid = (low + high) / 2;
        ll v = calc_val(l, mid);

        if (v == val) {
          r = mid;
          high = mid - 1;
        } else {
          low = mid + 1;
        }
      }

      if ((r - l) < (ans_r - ans_l)) {
        ans_l = l;
        ans_r = r;
      }
    }

    cout << ans_l << " " << ans_r << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll t;
  cin >> t;
  while (t--)
    solve();
}
