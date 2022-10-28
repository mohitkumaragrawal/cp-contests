#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) {
    ll N;
    cin >> N;

    cout << 1 << endl;

    for (int i = 2; i <= N; ++i) {
      cout << 1 << " ";
      for (int j = 2; j < i; ++j) {
        cout << 0 << " ";
      }
      cout << 1 << endl;
    }
  }
}
