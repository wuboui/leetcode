/*
Given a linked list, remove the n-th node from the end of list and return its head.

author:alkenwu
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
}
class RemoveFromEnd {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* temp = head;
		ListNode* des = head;
		for (int i = 0; i < n; ++i)
		{
			if (temp == NULL)
				return head;
			temp = temp->next;
		}
		if (temp != NULL)
		{
			temp = temp->next;
		}
		else
		{
			return head->next;
		}
		while (temp != NULL)
		{
			des = des->next;
			temp = temp->next;
		}

		des->next = des->next->next;
		return head;
	}
};