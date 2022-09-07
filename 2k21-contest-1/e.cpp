#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> arr(N);
  for (int& i : arr) cin >> i;

  int sum = accumulate(arr.begin(), arr.end(), 0);

  int low_load = sum / N;
  int high_load;
  if (sum % N == 0) {
    high_load = low_load;
  } else {
    high_load = low_load + 1;
  }

  if (low_load == high_load) {
    int ans = 0;
    for (int el : arr) {
      ans += abs(el - low_load);
    }
    ans /= 2;

    cout << ans << endl;
    return 0;
  }

  sort(arr.begin(), arr.end());
  int low_cnt = high_load * N - sum;

  int ans = 0;
  for (int i = 0; i < low_cnt; ++i) {
    ans += abs(arr[i] - low_load);
  }
  for (int i = low_cnt; i < N; ++i) {
    ans += abs(arr[i] - high_load);
  }
  ans /= 2;
  cout << ans << endl;
  return 0;
}