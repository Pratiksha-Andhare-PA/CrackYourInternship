class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int len = 0;
        while(temp!=NULL){
            len++;
            temp = temp->next;
        }

        temp = head;
        for(int i=0;i<len/2;i++){
            temp = temp->next;
        }
        return temp;
    }
};
