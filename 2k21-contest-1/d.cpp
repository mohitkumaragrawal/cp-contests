#include <bits/stdc++.h>
using namespace std;

int main() {
  int r1, c1, r2, c2;
  cin >> r1 >> c1 >> r2 >> c2;

  int rook = 2;
  if (r1 == r2 || c1 == c2) {
    rook = 1;
  }

  int bishop = 2;
  if (((r1 + c1) % 2) != ((r2 + c2) % 2)) {
    bishop = 0;
  } else {
    // see if it is on the same diagonal;
    bool same_d = false;
    if ((r1 + c1) == (r2 + c2)) same_d = true;
    if ((r1 - c1) == (r2 - c2)) same_d = true;

    if (same_d) bishop = 1;
  }

  int vert = abs(r1 - r2);
  int horz = abs(c1 - c2);
  int king = max(vert, horz);

  cout << rook << " " << bishop << " " << king << endl;
}