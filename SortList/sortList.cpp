/*
 * sortList.hpp
 *
 *  Created on: 2014年5月12日
 *      Author: admin
 */

#include <vector>
#include <string>
#include <stack>
#include <iostream>
#include <sstream>
#include <stdio.h>

#include "sortList.h"



ListNode * Solution::sortList(ListNode * head) {
	if(head == 0){
		return 0;
	}

	bool toNext = true;
	ListNode * pNext, * ppNext, * pp, * p = head;
	ListNode tmp = ListNode(0);
	ListNode * root = &tmp;
	root->next = head;

	do{
		pNext = p->next;
		pp = root;
		do{
			ppNext = pp->next;

			if( pNext != 0 && (pNext->val < ppNext->val) ){
				p->next = pNext->next;
				pNext->next = ppNext;
				pp->next =pNext;
				toNext = false;
				break;
			}

		}while( (pp = pp->next) != p );

		if(toNext){
			p = p->next;
		}
		else{
			toNext = true;
		}

	}while( p->next != 0);

	return root->next;
}


void hello()
{
	cout << "hello world" << endl;
}
void test_main(){
    Solution s  = Solution();
     ListNode head  = ListNode(9);
     ListNode a     = ListNode(3);
     ListNode b     = ListNode(2);
     ListNode c     = ListNode(4);
     ListNode d     = ListNode(10);
     head.next  = &a;
     a.next     = &b;
     b.next     = &c;
     c.next     = &d;
     ListNode * ret = s.sortList(&head);
     //ListNode * ret = &head;
     do{
        std::cout << ret->val << std::endl;
     } while ( (ret = ret->next) != 0 ) ;
}