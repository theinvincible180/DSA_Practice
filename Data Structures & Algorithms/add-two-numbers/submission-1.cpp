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
    ListNode* addTwoNumbers(ListNode* list1, ListNode* list2) {
        ListNode* ptr = new ListNode(0);
        ListNode* head = ptr;
        int carry = 0;

        while(list1 != nullptr && list2 != nullptr) {
            int num = (list1->val+list2->val+carry) % 10;
            carry = (list1->val+list2->val+carry) / 10;

            ListNode* temp = new ListNode(num);
            ptr -> next = temp;
            ptr = ptr->next;

            list1 = list1->next;
            list2 = list2 -> next;
        }

        while(list1 != nullptr) {
            int num = (list1->val+carry) % 10;
            carry = (list1->val+carry) / 10;

            ListNode* temp = new ListNode(num);
            ptr -> next = temp;
            ptr = ptr->next;

            list1 = list1->next;
        }

        while(list2 != nullptr) {
            int num = (list2->val+carry) % 10;
            carry = (list2->val+carry) / 10;

            ListNode* temp = new ListNode(num);
            ptr -> next = temp;
            ptr = ptr->next;

            list2 = list2 -> next;
        }

        if(carry > 0) {
            ListNode* temp = new ListNode(1);
            ptr -> next = temp;
            ptr = ptr->next;
        }

        return head->next;
    }
};
