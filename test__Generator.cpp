#include <bits/stdc++.h>
using namespace std;

int main() {
	int seed;
	cin>>seed;
	srand(seed);
	int temp = rand()%1000;
	cout<<temp;
	int a, b, c, d;
	b = 1 + rand()%10000;
	d = 1 + rand()%10000;
	a = 1 + rand()%10000;
	c = 1 + rand()%10000;
	// cout<<rand()%11<<" "<<rand()%11<<" "<<rand()%11;
	cout<<a<<" "<<b<<" "<<c<<" "<<d;
}