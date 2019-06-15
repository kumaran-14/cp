#include <iostream>
#include <cmath>
using namespace std;


int multiply(int x, int y) {
  //output : x * y
  if(y == 0)
    return 0;
  int z = multiply(x, floor(y / 2));
  if(y % 2 == 0)
    return 2*z;
  else
    return x + 2 * z;
}

int main() {
  int a = 11;
  int b = 13;
  int c = multiply(a, b);
  cout << "The product is " << c<<endl;
  return 0;
}
