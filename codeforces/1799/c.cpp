#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

void solve() {
  ll freq[26];
  memset(freq, 0, sizeof(freq));

  string s;
  cin >> s;

  for (char ch : s) {
    freq[ch - 'a']++;
  }

  bool right_bias = true;
  string left, singles, right;

  for (ll idx = 0; idx < 26; ++idx) {
    if (freq[idx] == 0) continue;

    if (freq[idx] % 2 == 1) {
      if (singles.empty()) {
        char ch2 = idx + 'a';
        ll pairs = (freq[idx] - 1) / 2;
        for (ll i = 0; i < pairs; ++i) {
          left.push_back(ch2);
          right.push_back(ch2);
        }
        singles.push_back('a' + idx);
      } else {
        char ch1 = singles.back();
        char ch2 = idx + 'a';
        singles.pop_back();

        if (right_bias) {
          right.push_back(ch1);
          left.push_back(ch2);
        } else {
          left.push_back(ch1);
          right.push_back(ch2);
        }
        right_bias = !right_bias;

        ll pairs = (freq[idx] - 1) / 2;
        for (ll i = 0; i < pairs; ++i) {
          left.push_back(ch2);
          right.push_back(ch2);
        }
      }
    } else {
      ll pairs = freq[idx] / 2;

      char ch = 'a' + idx;

      for (ll i = 0; i < pairs; ++i) {
        left.push_back(ch);
        right.push_back(ch);
      }
    }
  }

  reverse(all(right));

  string t1 = left + singles + right;
  auto t2 = t1;
  reverse(all(t2));

  string tmex = max(t1, t2);
  cout << tmex << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
