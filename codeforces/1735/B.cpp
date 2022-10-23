#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int T;
  cin >> T;
  while (T--) {
    ll N;
    cin >> N;
    vector<ll> arr(N);
    for (ll &i : arr)
      cin >> i;

    sort(arr.begin(), arr.end());
    ll ans = 0;
    ll key = (2 * arr[0] - 1);

    for (ll i = 1; i < N; ++i) {
      ll q = arr[i] / key;
      if (arr[i] % key != 0)
        q++;
      ans += (q - 1);
    }

    cout << ans << endl;
  }
}
