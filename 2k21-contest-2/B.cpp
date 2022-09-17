#include <bits/stdc++.h>
using namespace std;

int sum(vector<int>& arr) {
  int res = 0;
  for (int i : arr) res += i;
  return res;
}

int main() {
  int T;
  cin >> T;

  while (T--) {
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int& i : arr) cin >> i;

    vector<int> pos, neg;
    int zero_cnt = 0;

    for (int i : arr) {
      if (i > 0)
        pos.push_back(i);
      else if (i < 0)
        neg.push_back(i);
      else
        ++zero_cnt;
    }

    int pos_sum = sum(pos);
    int neg_sum = -sum(neg);

    if (pos_sum == neg_sum) {
      cout << "NO" << endl;
      continue;
    } else if (pos_sum > neg_sum) {
      cout << "YES" << endl;
      for (int i : pos) {
        cout << i << " ";
      }
      for (int i : neg) {
        cout << i << " ";
      }
    } else {
      cout << "YES" << endl;
      for (int i : neg) {
        cout << i << " ";
      }
      for (int i : pos) {
        cout << i << " ";
      }
    }

    while (zero_cnt--) {
      cout << 0 << " ";
    }
    cout << endl;
  }
}