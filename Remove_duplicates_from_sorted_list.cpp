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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        unordered_map<int,int> mp;
        ListNode* temp = head;
        while(temp){
            mp[temp->val]++;
            temp = temp->next;
        }

        ListNode list(-1);
        ListNode* ptr = &list;
        temp = head;
        while(temp){
            if(mp[temp->val] == 1){
                ptr->next = new ListNode(temp->val);
                ptr = ptr->next;
            }
            temp = temp->next;
        }
        return list.next;
    }
};
