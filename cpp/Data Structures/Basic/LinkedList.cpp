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

  // mergekSortedLists;
  /* two solutions.
    1. Take 2 at a time: (nk) : k =  8
    // considering each list contains n/k elements
        merge 1&2 => a ; (n/k) + n/k = 2n/k
        merge a&3 => b : 2n/k + n/k = 3n/k
        merge b&4 => c   3n/k + n/k = 4n/k
        merge c&5 => d
        merge d&6 => e
        merge e&7 => f
        merge f&8 => Final        =  8n/k;
        ((k*k-1)/2)  * n/k = O(kn)

    2. DIVIDE AND CONQUER. O(nlogk) : k = 8, then
    step 1: this step takes O(n) why ? access each element once
        merge 1&2 => a
        merge 3&4 => b
        merge 5&6 => c
        merge 7&8 => d
    step 2: this step takes O(n)
        merge a&b => A
        merge c&d => B
    step 3: this step takes O(n)
    .
    .
    .
    log k steps:
        merge A&B => Final list

        therefore O(n*logk)
   */
  return 0;
}
