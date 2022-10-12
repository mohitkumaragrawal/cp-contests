#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    string str;
    cin >> str;

    auto itr = min_element(str.begin(), str.end());

    char ch = *itr;
    str.erase(itr);

    cout << ch << " " << str << endl;
  }
}
