#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) {
    ll N, K;
    cin >> N >> K;

    K--;
    vector<ll> arr(N);

    for (ll &i : arr) cin >> i;

    if (arr[K] < 0) {
      cout << "NO" << endl;
      continue;
    }

    ll left = K, right = K;
    ll slime = arr[K];

    while (left > 0 || right < (N - 1)) {
      ll prev_left = left;
      ll prev_right = right;

      ll tmp = slime;
      for (ll i = left - 1; i >= 0; i--) {
        tmp += arr[i];

        if (tmp < 0) break;
        if (tmp > slime) {
          slime = tmp;
          left = i;
        }
      }

      tmp = slime;
      for (ll i = right + 1; i < N; ++i) {
        tmp += arr[i];
        if (tmp < 0) break;
        if (tmp > slime) {
          slime = tmp;
          right = i;
        }
      }

      if (prev_left == left && prev_right == right) {
        break;
      }
    }

    if (left == 0 || right == N - 1) {
      cout << "YES" << endl;
      continue;
    }

    bool success = true;
    ll tmp = slime;
    for (ll i = left - 1; i >= 0; --i) {
      tmp += arr[i];
      if (tmp < 0) {
        success = false;
        break;
      }
    }

    if (success) {
      cout << "YES" << endl;
      continue;
    }

    success = true;
    tmp = slime;

    for (ll i = right + 1; i < N; ++i) {
      tmp += arr[i];

      if (tmp < 0) {
        success = false;
        break;
      }
    }

    if (success) {
      cout << "YES" << endl;
      continue;
    }

    cout << "NO" << endl;
  }
}
