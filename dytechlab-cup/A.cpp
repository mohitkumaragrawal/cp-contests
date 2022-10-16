#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ostream& operator<<(ostream& out, pair<char, int> pr) {
  out << "[" << pr.first << " " << pr.second << " ]";
  return out;
}

void solve() {
  int N, K;
  cin >> N >> K;

  string s;
  cin >> s;

  int c = N / K;

  int f[26] = {0};
  for (char ch : s) {
    f[ch - 'a']++;
  }

  vector<pair<char, int>> v(K, make_pair('a', c));

  for (int i = 0; i < 26; ++i) {
    char ch = i + 'a';
    for (int j = 0; j < K; ++j) {
      if (f[i] == 0) break;

      if (v[j].first == ch && v[j].second > 0) {
        v[j].first++;
        v[j].second--;
        f[i]--;
      }
    }
  }

  string res;
  for (int i = 0; i < K; ++i) {
    res.push_back(v[i].first);
  }
  cout << res << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int T;
  cin >> T;
  while (T--) solve();
}
