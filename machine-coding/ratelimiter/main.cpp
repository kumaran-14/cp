//
// Created by kumaran on 11/5/22.
//

#include <bits/stdc++.h>
using namespace std;
#include <chrono>
using namespace chrono;

int main() {
  long timestamp = duration_cast<mill>(system_clock::now().time_since_epoch()).count();
  cout<<"hi"<<" "<<timestamp<<endl;
  return 0;
}
