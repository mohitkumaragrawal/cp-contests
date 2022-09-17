#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    vector<int> A(3);
    cin >> A[0] >> A[1] >> A[2];
    sort(A.begin(), A.end());

    int colors = 0;
    for (int& i : A) {
      if (i > 0) {
        i--;
        colors++;
      }
    }

    if (A[0] == 0) {
      if (A[1] > 0) {
        colors++;
      }
    } else {
      if (A[0] >= 2) {
        colors += 3;
      } else {
        if (A[2] == 1) {
          colors += 1;
        } else {
          colors += 2;
        }
      }
    }
  }
}