#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    int a, b, k;
    cin >> a >> b >> k;

    vector<int> A(k);
    vector<int> B(k);

    for (int& i : A) cin >> i;
    for (int& i : B) cin >> i;

    unordered_map<int, int> boy, girl;

    for (int i : A) boy[i]++;
    for (int i : B) girl[i]++;

    long long ans = 0;
    for (int i = 0; i < k; ++i) {
      int b = A[i], g = B[i];
      ans += (k - boy[b] - girl[g] + 1);
    }
    cout << ans / 2 << endl;
  }
}