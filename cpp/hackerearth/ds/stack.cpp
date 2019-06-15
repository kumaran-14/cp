// https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/tutorial/

// Stack implementation using Arrays

// reverse a stack, using recursion; void insert, void reverse;
#include <bits/stdc++.h>
using namespace std;

int top = -1;

void push(int stack[], int el, int n)
{
  if (top == n - 1)
  {
    cout << "Overflow" << endl;
    return;
  }
  top = top + 1;
  stack[top] = el;
}

int size()
{
  return top + 1;
}

int topElement(int stack[])
{
  return stack[top];
}

void pop()
{
  if (top == -1)
  {
    cout << "Underflow" << endl;
    return;
  }
  top = top - 1;
}

void insert(stack<int> &st, int el)
{
  if (st.empty())
  {
    st.push(el);
    return;
  }
  int topEl = st.top();
  st.pop();
  insert(st, el);
  st.push(topEl);
}

void sortInsert(stack<int> &s, int el)
{
  if (s.empty())
  {
    s.push(el);
    return;
  }
  int topEl = s.top();
  s.pop();
  if (topEl < el)
  {
    sortInsert(s, topEl);
    s.push(el);
  }
  else
  {
    sortInsert(s, el);
    s.push(topEl);
  }
}

void reverse(stack<int> &st)
{
  if (st.empty())
    return;
  int topEl = st.top();
  st.pop();
  reverse(st);
  // insert(st, topEl);
  sortInsert(st, topEl);
}

int main()
{
  int stack[3];
  push(stack, 5, 3);
  cout << "Current size of stack is " << size() << endl;
  push(stack, 10, 3);
  push(stack, 24, 3);
  cout << "Current size of stack is " << size() << endl;
  push(stack, 12, 3);
  cout << "The current top element in stack is " << topElement(stack) << endl;
  for (int i = 0; i < 3; i++)
    pop();
  cout << "Current size of stack is " << size() << endl;
  pop();
}
