/*

Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL

*/

/*

Author:AlkenWu
*/

 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
}};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        auto end = head;
        int len = 1;
        if (head == NULL)
            return head;
        for (; end->next != NULL; end = end->next)
            ++len;

        if (k % len == 0)
            return head;

        end->next = head;


        for (int i = 0; i < len - k % len; ++i)
        {
            end = end->next;
        }
        head = end->next;
        end->next = NULL;
        return head;
    }
};