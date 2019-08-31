#include <bits/stdc++.h>
using namespace std;

class listNode
{
public:
  int data;
  listNode *next;

  listNode(int data)
  {
    this->data = data;
    this->next = nullptr;
  }
};

class mylist
{
public:
  listNode *head;

  mylist()
  {
    this->head = nullptr;
  }
  void addNode(int data)
  {
    listNode *newNode = new listNode(data), *temp = this->head;
    if (this->head == nullptr)
    {
      this->head = newNode;
      return;
    }
    while (temp->next != nullptr)
    {
      temp = temp->next;
    }
    temp->next = newNode;
    // return this->head;
  }

  void printList(listNode *head)
  {
    if (head != nullptr)
    {
      cout << head->data << " ";
      return printList(head->next);
    }
    return;
  }
};

int main()
{
  mylist *templist = new mylist();
  templist->addNode(10);
  templist->addNode(3);
  templist->addNode(5);
  templist->printList(templist->head);
  return 0;
}
