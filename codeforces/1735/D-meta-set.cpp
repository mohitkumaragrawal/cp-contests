#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int N, K;
map<ll, int> mp;
vector<vector<int>> cards;

ll calculate_hash(const vector<int>& feature) {
  ll res = 0;
  ll p = 1;

  for (int i = 0; i < feature.size(); ++i) {
    res += feature[i] * p;
    p *= 3;
  }
  return res;
}

void solve() {
  cin >> N >> K;
  cards.resize(N, vector<int>(K));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < K; ++j) {
      cin >> cards[i][j];
    }
    mp[calculate_hash(cards[i])] = i;
  }

  ll ans = 0;

  for (int i = 0; i < N; ++i) {
    ll set_count = 0;
    for (int j = 0; j < N; ++j) {
      if (j == i) continue;
      vector<int> feature(K);
      for (int f = 0; f < K; ++f) {
        if (cards[i][f] == cards[j][f]) {
          feature[f] = cards[i][f];
        } else {
          int f_val = 3 ^ cards[i][f] ^ cards[j][f];
          feature[f] = f_val;
        }
      }
      ll req_card = calculate_hash(feature);
      if (auto itr = mp.find(req_card); itr != mp.end() && itr->second > j) {
        ++set_count;
      }
    }
    ans += (set_count * (set_count - 1)) / 2;
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  solve();
}