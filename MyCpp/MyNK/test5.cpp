#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <vector>
#include <iostream>
#include <string.h>
using namespace std;


struct ListNode {
        int val;
       struct ListNode *next;
        ListNode(int x) :
              val(x), next(NULL) {
        }
  };


vector<int> printListFromTailToHead(ListNode* head) {
    vector<int> a;
    for(ListNode* node=head;node!=NULL;node=node->next)
    {
    	cout<< node->val<< endl;
        a.insert(a.begin(), node->val);
    }
    return a;
}

int main()
{
	struct ListNode* head = new ListNode(1);
	vector<int> a = printListFromTailToHead(head);
	for(vector<int>::iterator it = a.begin(); it != a.end(); it++)
	{
		cout<< *it << endl;
	}
}