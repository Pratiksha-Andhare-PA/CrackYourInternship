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
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        int n=0;
        while(temp != NULL){
            n++;
            temp = temp->next;
        }
        
        int sum = 0;
        temp = head;
        int i = 0;
        while(temp != NULL){
            sum += temp->val*pow(2,n-i-1);
            temp = temp->next;
            i++;
        }
        return sum;
    }
};
