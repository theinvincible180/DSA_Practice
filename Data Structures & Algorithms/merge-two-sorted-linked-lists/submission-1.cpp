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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ptr = new ListNode(0);
        ListNode* head = ptr;

        while(list1 != nullptr && list2 != nullptr) {
            ListNode* temp = new ListNode(0);
            
            if(list1->val <= list2->val) {
                temp->val = list1->val;
                ptr -> next = temp;

                list1 = list1 -> next;
                ptr = ptr -> next;
            }
            else {
                temp->val = list2->val;
                ptr -> next = temp;

                list2 = list2 -> next;
                ptr = ptr -> next;
            }
        }

        if(list1 != nullptr) ptr -> next = list1;

        if(list2 != nullptr) ptr -> next = list2;

        return head->next;
    }
};
