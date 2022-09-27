#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int T;
  cin >> T;
  while (T--) {
    int N, C;
    cin >> N >> C;

    int arr[101] = {0};
    for (int i = 1; i <= N; ++i) {
      int orbit;
      cin >> orbit;

      arr[orbit]++;
    }

    int cost = 0;
    for (int i = 1; i <= 100; ++i) {
      cost += min(arr[i], C);
    }
    cout << cost << endl;
  }
}