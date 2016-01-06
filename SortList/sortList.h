#ifndef _SORTLIST_H_
#define _SORTLIST_H_

#include <cstdio>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode * next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode * sortList(ListNode * head);
};

void test_main();



#endif // _SORTLIST_H_