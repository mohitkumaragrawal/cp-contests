#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N, k;
    cin >> N >> k;

    vector<int> arr(N);
    for (int& i : arr) cin >> i;

    int G = arr[0];
    for (int i = 1; i < N; ++i) {
      G = gcd(G, arr[i]);
    }

    int count = 0;
    int tmp = 0;

    for (int i = 0; i < N; ++i) {
      tmp = gcd(tmp, arr[i]);
      if (tmp == G) {
        ++count;
        tmp = 0;
      }
    }

    if (count >= k) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}