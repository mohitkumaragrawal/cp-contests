#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    long long num;
    cin >> num;

    while (num % 2 == 0) {
      num /= 2;
    }
    if (num > 1) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}