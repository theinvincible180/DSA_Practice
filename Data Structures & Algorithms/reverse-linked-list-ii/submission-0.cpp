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
    ListNode* reverseList(ListNode* head, ListNode* right) {
        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp != right) {
            ListNode* next = temp -> next;
            
            temp -> next = prev;
            prev = temp;
            temp = next;
        }

        temp -> next = prev;
        prev = temp;

        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        int loop1 = left;
        int loop2 = right;
        int loop3 = left-1;
        ListNode* leftPtr = dummy;
        ListNode* rightPtr = dummy;
        ListNode* prev = dummy;

        while(loop1 > 0) {
            leftPtr = leftPtr -> next;
            loop1--;
        }

        while(loop2 > 0) {
            rightPtr = rightPtr -> next;
            loop2--;
        }
        
        ListNode* after = rightPtr -> next;

        while(loop3 > 0){
            prev = prev -> next;
            loop3--;
        }

        ListNode* tempHead = reverseList(leftPtr, rightPtr);
        prev->next = tempHead;
        leftPtr -> next = after;

        // ListNode* temp = tempHead;
        // while(temp->next != nullptr) {
        //     temp = temp -> next;
        // }


        return dummy -> next;
    }
};