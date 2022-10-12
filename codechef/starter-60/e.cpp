#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

struct v3 {
  ll x, y, z;
};

void solve() {
  ll N;
  cin >> N;

  vector<ll> arr(N);
  for (ll& el : arr) cin >> el;

  vector<v3> mvs = {
      {0, 1, 2}, {3, 4, 5}, {0, 1, 3}, {2, 4, 5},
      {1, 3, 4}, {0, 1, 2}, {1, 2, 3}, {2, 3, 4},
  };

  auto op_do = [&](int i, int j, int k) {
    int a = arr[i] ^ arr[j];
    int b = arr[j] ^ arr[k];
    int c = arr[k] ^ arr[i];

    arr[i] = a;
    arr[j] = b;
    arr[k] = c;
  };

  ll cnt = 8;

  vector<v3> res;
  for (auto [i, j, k] : mvs) {
    res.push_back({arr[i], arr[j], arr[k]});
    op_do(i, j, k);
  }

  for (ll i = 3; i < N; ++i) {
    if (arr[i] == 0) continue;

    ll x = arr[i];
    arr[i] = 0;

    cnt += 3;

    res.push_back({0, 0, x});
    res.push_back({0, 0, x});
    res.push_back({x, x, x});
  }

  cout << res.size() << endl;
  for (auto [a, b, c] : res) {
    cout << a << " " << b << " " << c << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}