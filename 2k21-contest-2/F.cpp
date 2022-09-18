#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

void solve3(int i, int j, int k, vector<int>& arr, vector<int>& res) {
  if (arr[i] == arr[j]) {
  } else if (arr[j] == arr[k]) {
    swap(i, k);
  } else if (arr[i] == arr[k]) {
    swap(j, k);
  } else {
    res[i] = arr[j] - arr[k];
    res[j] = arr[k] - arr[i];
    res[k] = arr[i] - arr[j];
    return;
  }

  res[k] = arr[i];

  int b = -arr[k];
  if (b == 1) {
    res[i] = 2;
    res[j] = -1;
  } else {
    res[i] = 1;
    res[j] = b - 1;
  }
}

void solve2(int i, int j, vector<int>& arr, vector<int>& res) {
  int g = gcd(arr[i], arr[j]);
  res[i] = -arr[j] / g;
  res[j] = arr[i] / g;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int& i : arr) cin >> i;

    vector<int> res(N);

    int curr = -1;
    while (curr < N - 1) {
      int left = N - curr - 1;

      if (left >= 5) {
        solve3(curr + 1, curr + 2, curr + 3, arr, res);
        curr += 3;
        continue;
      }

      if (left > 3 || left == 2) {
        solve2(curr + 1, curr + 2, arr, res);
        curr += 2;
      } else {
        solve3(curr + 1, curr + 2, curr + 3, arr, res);
        break;
      }
    }

    for (int i : res) cout << i << " ";
    cout << endl;
  }
}