#include <bits/stdc++.h>
using namespace std;

int main() {
	int seed;
	cin>>seed;
	srand(seed);
	int n = 10;

	int A = 1 + rand()%10;
	int B = 1 + rand()%5;
	cout<<A<<" "<<B<<" "<<n;
	cout<<"\n";
	for(int i = 1; i <= n; i++) {
		cout<<1+rand()%6<<" ";
	}
	cout<<"\n";
	for(int i = 1; i <= n; i++) {
		cout<<1+rand()%6<<" ";
	}
}