#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
  ll N;
  cin >> N;

  vector<ll> arr(N);
  for (auto& el : arr) cin >> el;

  if (N == 1) {
    cout << 0 << endl;
    return;
  }

  vector<ll> tmp;
  ll l = 0, r = N - 1;
  bool valid = true;
  while (r >= l) {
    if (arr[r] < arr[l]) {
      valid = false;
    }
    tmp.push_back(arr[r] - arr[l]);
    l++, r--;
  }

  for (ll i = 1; i < tmp.size(); ++i) {
    if (tmp[i] > tmp[i - 1]) {
      valid = false;
      break;
    }
  }

  if (!valid || tmp[0] < 0) {
    cout << -1 << endl;
    return;
  }
  cout << tmp[0] << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}