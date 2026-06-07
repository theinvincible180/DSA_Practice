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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        int carry = 0;

        while(l1 != nullptr || l2 != nullptr || carry != 0){
            int val1 = l1 != nullptr ? l1->val : 0;
            int val2 = l2 != nullptr ? l2->val : 0;

            int num = (val1 + val2 + carry) % 10;
            carry = (val1 + val2 + carry) / 10;

            curr->next = new ListNode(num);
            curr = curr -> next;

            l1 = l1 != nullptr ? l1 -> next : nullptr;
            l2 = l2 != nullptr ? l2 -> next : nullptr;
        }

        return dummy->next;
    }
};
