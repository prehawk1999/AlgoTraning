/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?

*/

#include <string>
#include <iostream>
#include <sstream>
#include <set>
#include <list>

namespace {

using std::set;
using std::list;
using std::string;
using std::cout;
using std::endl;
using std::ostream;

struct ListNode {
  int val;
  ListNode * next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode *detectCycle(ListNode *head) {
      // without using extra space.
      if(head == NULL) return NULL;

      auto n = head;
      while(n != NULL) {
        if(_exists_node.find(n) == _exists_node.end()) {
          _exists_node.insert(n);
        }
        else {
          return n;
        }
        n = n->next;
      }
      return NULL;
    }
  private:
    set<ListNode*>    _exists_node;
};


} // namespcae


int main() {
  auto s  = Solution();
  // case 1:
  auto head = new ListNode(3);
  std::cout << "new node=" << head << std::endl;
  auto b = new ListNode(2);
  std::cout << "new node=" << b << std::endl;
  head->next = b;
  auto c = new ListNode(0);
  std::cout << "new node=" << c << std::endl;
  b->next = c;
  auto d = new ListNode(-4);
  std::cout << "new node=" << d << std::endl;
  c->next = d;
  d->next = b;

  auto node = s.detectCycle(head);
  if(node != NULL)
    std::cout << "listnode has cycle node=" << node << std::endl;
  else
    std::cout << "listnode doesnt has cycle" << std::endl;

  std::cout << "==============case 2==========" << std::endl;
  // case 2:
  head = new ListNode(1);
  std::cout << "new node=" << head << std::endl;
  b = new ListNode(2);
  std::cout << "new node=" << b << std::endl;
  head->next = b;
  b->next = head;


  node = s.detectCycle(head);
  if(node != NULL)
    std::cout << "listnode has cycle node=" << node << std::endl;
  else
    std::cout << "listnode doesnt has cycle" << std::endl;

  return 0;
}