#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "

using namespace std;
using ll = long long;

const ll MOD = 1e9+7;

ll N;
ll arr[105];

bool check(ll k) {
  vector<ll> t(begin(arr), begin(arr) + N);
  sort(all(t));

  for (ll i = 1; i <= k; ++i) {
    ll el = k - i + 1;

    if (t[0] > el) return false;

    if (t.empty()) return false;

    ll idx = 0;
    for (ll i = 0; i < t.size(); ++i) {
      if (t[i] <= el) idx = i;
      else break;
    }

    t.erase(t.begin() + idx);
    if (t.empty()) continue;

    t[0] += el;
    sort(all(t));
  }

  return true;
}

void solve() {
  cin >> N;
  for (ll i = 0; i < N; ++i) cin >> arr[i];

  ll low = 0, high = N, ans = 0;
  while (high >= low) {
    ll mid = (low + high) / 2;

    if (check(mid)) {
      ans = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
