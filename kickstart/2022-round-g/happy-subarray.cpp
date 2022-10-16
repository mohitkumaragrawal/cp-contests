#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "

using namespace std;
using ll = long long;

const ll MOD = 1e9+7;

ll arr[400005], pre[400005], ppr[400005];
ll N;

ll calc_sum(ll left, ll right) {
  ll f = N - right;
  
  ll pp_s = ppr[right];
  ll pre_s = pre[right];

  if (left > 0) {
    pp_s -= ppr[left-1];
    pre_s -= pre[left-1];
  }

  return pp_s - (f - 1) * pre_s;
}

void solve(ll T) {
  cin >> N;
  
  for (ll i = 0; i < N; ++i) cin >> arr[i];

  pre[0] = arr[0];
  for (ll i = 1; i < N; ++i) pre[i] = pre[i-1] + arr[i];

  ppr[0] = N * arr[0];
  for (ll i = 1; i < N; ++i) {
    ppr[i] = ppr[i-1] + (N - i) * arr[i];
  }

  ll left = N-1, right = N-1;
  ll _left = N;
  ll ans = 0;

  for (; left >= 0; --left) {
    if (arr[left] < 0) continue;

    ll neg_sum = pre[_left - 1] - pre[left];

    // one more case missing; like 10 -3 -4 -5

    if (arr[left] + neg_sum >= 0) {
      cout << "left = " << left << ", right = " << right << endl;
      ans += calc_sum(left, right);
      _left = left;
      continue;
    }

    ll low = left + 1, high = _left - 1;
    right = left;
    while (high >= low) {
      ll mid = (low + high) / 2;
      ll ns = arr[left] + pre[mid] - pre[left];

      if (ns >= 0) {
        right = mid;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    _left = left;
    cout << "left = " << left << ", right = " << right << endl;
    ans += calc_sum(left, right);
  }

  OUT(T) << ans << endl;
}


int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;

  for (ll i = 1; i <= T; ++i) solve(i);
}
