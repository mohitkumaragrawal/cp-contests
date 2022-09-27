#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

int helper(const string& str, int start, string& vec) {
  vector<vector<int>> indices(10);

  for (int i = start; i < str.size(); ++i) {
    indices[str[i] - '0'].push_back(i);
  }

  int m_num;
  for (int i = 0; i <= 9; ++i) {
    if (indices[i].size() > 0) {
      m_num = i;
      break;
    }
  }

  int last = start;
  for (int i = 0; i < indices[m_num].size(); ++i) {
    int m_idx = indices[m_num][i];
    string s;
    s.push_back('0' + m_num);

    for (int j = last; j < m_idx; ++j) {
      if (str[j] == '9') {
        s.push_back('9');
      } else {
        s.push_back(1 + str[j]);
      }
    }
    vec.append(s);
    last = indices[m_num][i] + 1;
  }
  return last;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int T;
  cin >> T;
  while (T--) {
    string num;
    cin >> num;

    string res;
    int start = 0;

    while (start < num.size()) {
      start = helper(num, start, res);
    }

    sort(res.begin(), res.end());
    cout << res << endl;
  }
}