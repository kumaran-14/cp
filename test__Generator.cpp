#include <bits/stdc++.h>
using namespace std;

int main() {
	int seed;
	cin>>seed;
	srand(seed);
	int temp = rand()%1000;
	cout<<temp;
	// cout<<rand()%11<<" "<<rand()%11<<" "<<rand()%11;
}