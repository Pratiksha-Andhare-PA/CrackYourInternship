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
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return true;
        }

        ListNode* temp = head;
        int l = 0;
        while(temp!=NULL){
            l++;
            temp = temp->next;
        }
        temp = head;
        stack<ListNode*> st;
        for(int i=0;i<l/2;i++){
            st.push(temp);
            temp = temp->next;
        }

        int start;
        if(l%2 != 0)
            temp = temp->next;
        
        while(!st.empty()) {
            if(st.top()->val != temp->val){
                return false;
            }
            st.pop();
            temp = temp->next;
        }
        return true;
    }
};
