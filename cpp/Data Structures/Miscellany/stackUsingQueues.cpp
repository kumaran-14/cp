#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
  queue<int> a, b;
  /** Initialize your data structure here. */
  MyStack() {}

  /** Push element x onto stack. */
  void push(int x) {
    a.push(x);
  }

  /** Removes the element on top of the stack and returns that element. */
  int pop() {
    while(a.size() != 1) {
      auto el = a.front();
      a.pop();
      b.push(el);
    }
    int el = -1;
    if(a.size() == 1) {
      el = a.front();
      a.pop();
    }
    auto temp = b;
    b = a;
    a = temp;
    return el;
  }

  /** Get the top element. */
  int top() {
    while(a.size() != 1) {
      auto el = a.front();
      a.pop();
      b.push(el);
    }
    auto el = a.size() == 1 ? a.front() : -1;
  }

  /** Returns whether the stack is empty. */
  bool empty() {
    return a.empty() && b.empty();
  }
};


int main() {
  MyStack stack = MyStack();

  stack.push(1);
  stack.push(2);
  cout<<stack.top()<<endl;   // returns 2
  stack.pop();   // returns 2
  cout<<stack.empty()<<endl; // returns false // returns 4
}