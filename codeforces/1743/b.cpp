
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "

using namespace std;
using ll = long long;

const ll MOD = 1e9+7;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int T;
  cin >> T;
  while (T--) {
    int x;
    cin >> x;

    cout << 1 << " ";

    for (int i = 3; i <= x; ++i) {
      cout << i << " ";
    }
    cout << 2 << endl;
  }
}
