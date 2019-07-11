#include <iostream>
#include <cmath>
using namespace std;

int modExp(int x, int y, int N)
{
  //output : (x ^ y ) mod N
  if (y == 0)
    return 1;
  int z = modExp(x, floor(y / 2), N);
  if (y % 2 == 0)
    return (z * z) % N;
  else
    return (x * z) % N;
}

int main()
{
  int a = 5;
  int b = 4;
  int N = 3;
  int c = modExp(a, b, N);
  cout << "The modular exponentiation value of " << a << "^" << b << " mod " << N << " is " << c << endl;
  return 0;
}
