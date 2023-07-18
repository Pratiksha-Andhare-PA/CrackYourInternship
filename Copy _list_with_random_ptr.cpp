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
        if(head == NULL){
            return NULL;
        }
        Node* temp = head;
        unordered_map<Node*,Node*>mp;
        
        while(temp != NULL){
            mp[temp] = new Node(temp->val);
            temp = temp->next;
        }

        temp = head;
        while(temp != NULL){
            Node* n = mp[temp];
            n->next = mp[temp->next];
            n->random = mp[temp->random];
            temp = temp->next;
        }
        return mp[head];
    }
};
