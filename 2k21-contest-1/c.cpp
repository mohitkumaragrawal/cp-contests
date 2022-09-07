#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> cute_sieve(3001, 1);
  cute_sieve[0] = cute_sieve[1] = 0;

  for (int i = 2; i <= N; ++i) {
    if (cute_sieve[i] != 1) {
      continue;
    }
    for (int j = 2 * i; j <= N; j += i) {
      cute_sieve[j]++;
    }
  }
  int ans = 0;
  for (int i = 1; i <= N; ++i) {
    if (cute_sieve[i] == 3) ++ans;
  }
  cout << ans << endl;
}