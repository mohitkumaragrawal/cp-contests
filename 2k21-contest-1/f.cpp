#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int& i : arr) cin >> i;

    int k = 0;
    for (int el : arr) k ^= el;

    if (k == 0) {
      cout << "YES" << endl;
      continue;
    }

    int count = 0, x = 0;
    for (int i = 0; i < N; ++i) {
      x ^= arr[i];

      if (x == k) {
        ++count;
        x = 0;
      }
    }

    if (count > 1) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}