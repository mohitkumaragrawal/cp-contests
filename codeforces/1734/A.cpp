#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) {
    ll N;
    cin >> N;
    vector<ll> arr(N);
    for (ll &i : arr) cin >> i;

    sort(arr.begin(), arr.end());
    ll ans = arr[2] - arr[0];
    for (ll i = 3; i < N; ++i) {
      ans = min(ans, arr[i] - arr[i - 2]);
    }
    cout << ans << endl;
  }
}