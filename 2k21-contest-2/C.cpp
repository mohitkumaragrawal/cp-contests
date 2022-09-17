#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
  ll T;
  cin >> T;

  while (T--) {
    ll N;
    cin >> N;

    vector<ll> b(N + 2);
    for (ll &i : b) cin >> i;

    ll sum = 0;
    for (ll i : b) sum += i;

    map<ll, ll> mp;
    for (ll i = 0; i < b.size(); ++i) {
      mp[b[i]] = i;
    }

    bool found = false;
    ll idx = -1;
    ll sidx = -1;

    for (ll i = 0; i < b.size(); ++i) {
      // test if b[i] qualifies as x;

      ll k = sum - b[i];
      if (k & 1) continue;

      k /= 2;
      if (mp.find(k) != mp.end() && mp[k] != i) {
        // we found an answer;
        found = true;
        idx = i;
        sidx = mp[k];
        break;
      }
    }

    if (found) {
      for (ll i = 0; i < b.size(); ++i) {
        if (i == idx || i == sidx) continue;
        cout << b[i] << " ";
      }
      cout << endl;
    } else {
      cout << -1 << endl;
    }
  }
}