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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL){
            temp = temp->next;
            len++;
        }
        int pos = len-n;
        if(pos==0){
            ListNode* todelete = head;
            head = head->next;
            delete todelete;
	        return head;
        }
        int count = 1;
        temp = head;
        while (count != pos && temp != nullptr) {
            temp = temp->next;
            count++;
        }
        if (temp != nullptr && temp->next != nullptr) {
            ListNode* todelete = temp->next;
            temp->next = temp->next->next;
            delete todelete;
        }
        return head;
    }
};
