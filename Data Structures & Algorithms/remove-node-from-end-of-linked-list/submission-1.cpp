/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !head->next) return nullptr;

        ListNode* temp = head;
        int len = 0;
        while(temp != nullptr) {
            len++;
            temp = temp -> next;
        }

        if(n == len) return head -> next;
        temp = head;
        int loop = len-n-1;

        while(loop > 0) {
            temp = temp -> next;
            loop--;
        }

        temp -> next = temp -> next -> next;
        return head;
    }
};
