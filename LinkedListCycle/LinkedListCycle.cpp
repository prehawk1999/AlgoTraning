/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    bool hasCycle(ListNode *head) {
      if(head == NULL) return false;

      auto n = head;
      while((n = n->next) != NULL) {

        if(_exists_node.find(n) == _exists_node.end()) {
          _exists_node.insert(n);
        }
        else {
          return true;
        }
      }
      return false;
    }
  private:
    set<ListNode*>    _exists_node;
};


} // namespcae


int main() {
  std::cout << "compile succ" << std::endl;
  auto s  = Solution();
  auto head  = new ListNode(9);
  auto a = new ListNode(1);
  head->next = a;
  auto b = new ListNode(2);
  a->next = b;
  b->next = head;


  bool isCycleList = s.hasCycle(head);
  if(isCycleList)
    std::cout << "listnode has cycle" << std::endl;
  else
    std::cout << "listnode doesnt has cycle" << std::endl;

  return 0;
}