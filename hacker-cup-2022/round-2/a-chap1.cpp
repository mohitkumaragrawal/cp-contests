#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

int main() {
  freopen("a-1-input.txt", "r", stdin);
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int T;
  cin >> T;
  for (int test = 1; test <= T; ++test) {
    string str;
    cin >> str;

    vector<vector<int>> freq(str.size(), vector<int>(26, 0));
    freq[0][str[0] - 'a']++;

    for (int i = 1; i < str.size(); ++i) {
      for (int j = 0; j < 26; ++j) {
        freq[i][j] = freq[i - 1][j];
      }
      freq[i][str[i] - 'a']++;
    }

    int ans = 0;

    int Q;
    cin >> Q;

    while (Q--) {
      int l, r;
      cin >> l >> r;
      l--, r--;

      int sz = (r - l + 1);
      if (sz % 2 == 0) {
        continue;
      }

      vector<int> f(26, 0);
      for (int i = 0; i < 26; ++i) {
        if (l == 0) {
          f[i] = freq[r][i];
          continue;
        }
        f[i] = freq[r][i] - freq[l - 1][i];
      }

      // for (char ch = 'a'; ch <= 'z'; ++ch) {
      //   cout << ch << " " << f[ch - 'a'] << endl;
      // }

      int odd_count = 0;
      char ch;
      for (int i = 0; i < 26; ++i) {
        if (f[i] % 2 != 0) {
          odd_count++;
          ch = i + 'a';
        }
      }
      // cout << "odd count is " << odd_count << endl;
      if (odd_count != 1) continue;
      // cout << "odd char is " << ch << endl;

      int mid = (l + r) / 2;

      vector<int> lh(26, 0), rh(26, 0);
      for (int i = 0; i < 26; ++i) {
        lh[i] = freq[mid][i];
        if (l != 0) {
          lh[i] -= freq[l - 1][i];
        }

        rh[i] = freq[r][i];
        if (mid != 0) {
          rh[i] -= freq[mid][i];
        }
      }

      // for (char ch = 'a'; ch <= 'z'; ++ch) {
      //   cout << ch << " " << lh[ch - 'a'] << " " << rh[ch - 'a'] << endl;
      // }

      int diff = 0;
      for (int i = 0; i < 26; ++i) {
        diff += abs(rh[i] - lh[i]);
      }
      if (diff == 1) {
        ans++;
        continue;
      }

      mid--;
      diff = 0;
      lh.assign(26, 0), rh.assign(26, 0);

      for (int i = 0; i < 26; ++i) {
        lh[i] = freq[mid][i];
        if (l != 0) {
          lh[i] -= freq[l - 1][i];
        }

        rh[i] = freq[r][i];
        if (mid != 0) {
          rh[i] -= freq[mid][i];
        }
      }

      // for (char ch = 'a'; ch <= 'z'; ++ch) {
      //   cout << ch << " " << lh[ch - 'a'] << " " << rh[ch - 'a'] << endl;
      // }

      for (int i = 0; i < 26; ++i) {
        diff += abs(rh[i] - lh[i]);
      }
      if (diff == 1) {
        ans++;
        continue;
      }
    }
    cout << "Case #" << test << ": " << ans << endl;
  }
}