#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    int N;
    cin >> N;

    if (N < 2020) {
      cout << "NO" << endl;
      continue;
    }

    int k1 = N / 2020;
    int k2 = N % 2020;

    if (k2 <= k1) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}