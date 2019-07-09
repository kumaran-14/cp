// kumaran_14
#include <bits/stdc++.h>
using namespace std;

long long binpow(long long a, long long b) {
  if(b==1)
    return a;
  long long res = binpow(a, b / 2);
  if(b%2 != 0)
    return res * res * a;
  else
    return res * res;
}


long long recursivemodbinpow(long long a, long long b, long long m) {
  if(b==1)
    return a;
  long long res = recursivemodbinpow(a, b / 2, m);
  if(b%2 != 0)
    return res * res * a % m;
  else
    return res * res % m;
}

long long modbinpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main() {
  long long a = 3;
  long long b = 13;
  cout << std::fixed << binpow(a, b)<<endl;
}
