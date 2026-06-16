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
    void reorderList(ListNode* head) {
        map<ListNode*, ListNode*> mp;

        ListNode* ptr = head;

        while(ptr -> next != nullptr) {
            mp[ptr->next] = ptr;
            ptr = ptr -> next;
        }

        ListNode* temp = head;

        while(ptr != temp && mp[ptr] != temp) {
            ListNode* next = temp -> next;

            temp -> next = ptr;
            ptr -> next = next;
            ptr = mp[ptr];
            temp = next;
        }

        ptr -> next = nullptr;

        // return head;
    }
};
