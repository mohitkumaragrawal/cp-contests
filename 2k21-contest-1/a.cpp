#include <bits/stdc++.h>

using namespace std;

int main() {
  string n;
  cin >> n;

  int count = 0;
  for (char ch: n) {
    if (ch == '4' || ch=='7') ++count;
  }

  string count_str = to_string(count);
  bool lucky = true;

  for (auto ch: count_str) {
    if (ch != '4' && ch != '7') {
      lucky = false;
      break;
    }
  }

  if (lucky) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}