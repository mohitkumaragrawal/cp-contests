#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N, d;
    cin >> N >> d;
    vector<int> arr(N);
    for (int& i : arr) cin >> i;

    int mx = *max_element(arr.begin(), arr.end());
    if (mx <= d) {
      cout << "YES" << endl;
      continue;
    }

    sort(arr.begin(), arr.end());
    int S = arr[0] + arr[1];

    if (S <= d) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}