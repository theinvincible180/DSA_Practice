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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp != nullptr) {
            ListNode* next = temp -> next;
            
            temp -> next = prev;
            prev = temp;
            temp = next;
        }

        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode* mid = reverseList(slow -> next);
        slow -> next = nullptr;
        ListNode* temp = head;

        while(mid != nullptr) {
            ListNode* tempNext = temp -> next;
            ListNode* midNext = mid -> next;

            temp -> next = mid;
            mid -> next = tempNext;
            mid = midNext;
            temp = tempNext;
        }
    }
};
