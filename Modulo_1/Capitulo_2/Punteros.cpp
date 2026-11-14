#include <iostream>
using namespace std;

int main() {
  int x = 55;
  int y = -22;

  int *px = &x;
  int *py = &y;

  cout << "px1 = " << *px << endl;

  cout << "py1 = " << *py << endl;

  //Reemplazo lo que hay en px.
  *px = 7;
  py = px;

  cout << "px2 = " << *px << endl;

  cout << "py2 = " << *py << endl;


  return 0;
}
