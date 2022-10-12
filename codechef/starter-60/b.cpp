#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;

using ll = long long;
using ull = unsigned long long;

bool vis[200005];

ll solve() {
  fill(all(vis), false);

  ll N, K;
  cin >> N >> K;

  vector<ll> arr(N);
  for (ll& i: arr) {
    cin >> i;
    vis[i] = true;
  } 

  ll mx = *max_element(all(arr));
  ll ans = 0;

  ll el = 1;
  ll count = 0;

  while (count < K) {
    if (vis[el]) {
      el++;
      continue;
    }

    ans += max((mx - el), 0LL);
    ++el;
    ++count;
  }

  if (mx == 2 * N) {
    return ans;
  }

  ll tmp = 0;
  count = 1;
  el = 1;

  while (count < K) {
    if (vis[el]) {
      el ++;
      continue;
    }

    tmp += (2 * N - el);
    ++el;
    ++count;
  }

  return max(ans, tmp);
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int T;
  cin >> T;
  while(T--) {
    cout << solve() << endl;
  } 
}