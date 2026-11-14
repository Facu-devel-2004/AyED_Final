#include <iostream>
using namespace std;

int main(){
  int v[5] = {21, 4, -6, 7, 80};
  int *px = &v[0];
  int *py = v;

  cout << "1ra forma" << endl;
  for(int i = 0; i < 5; i++){
    cout << px[i] << endl;
  }
  cout << endl;

  cout << "2da forma" << endl;
  for(int i = 0; i < 5; i++){
    cout << *(px + i) << endl;
  }
  cout << endl;

  cout << "3ra forma" << endl;
  for(int i = 0; i < 5; i++){
    cout << *(v + i) << endl;
  }
  cout << endl;

  cout << "4ta forma" << endl;
  for(int i = 0; i < 5; i++){
    cout << *py++ << endl;
  }
  cout << endl;

  cout << "Trampa" << endl;
  for(int i = 0; i < 5; i++){
    cout << *v++ << endl;
  }
  return 0;
}
