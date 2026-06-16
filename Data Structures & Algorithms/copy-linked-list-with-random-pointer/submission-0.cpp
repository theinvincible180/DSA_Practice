/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        vector<Node*> temp;
        unordered_map<Node*, Node*> mp;

        Node* ptr = head;
        while(ptr != nullptr) {
            temp.push_back(ptr);
            ptr = ptr -> next;
        }

        Node* dummy = new Node(0);
        Node* node = dummy;

        for(int i = 0 ; i < temp.size() ; i++) {
            Node* x = temp[i];
            int val = x -> val;

            Node* y = new Node(val);
            
            mp[x] = y;

            node -> next = y;
            node = node -> next;
        }

        ptr = dummy -> next;
        int idx = 0;
        while(ptr != nullptr) {
            Node* x = temp[idx];
            
            if(x -> random != nullptr) {
                ptr -> random = mp[x-> random];
            }
            else {
                ptr -> random = nullptr;
            }

            ptr = ptr -> next;
            idx++;
        }

        return dummy -> next;
    }
};
