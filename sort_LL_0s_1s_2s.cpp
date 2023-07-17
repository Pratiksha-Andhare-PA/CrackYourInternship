#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* next;
    
    node(int val){
        data = val;
        next = NULL;
    }
};

void InsertAtTail(node* &head,int val){
    node* n = new node(val);
    if(head == NULL){
        head = n;
        return;
    }
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void SortList(node* &head){
    node* temp = head;
    int cnt0=0,cnt1=0,cnt2=0;
    int len = 0;
    while(temp!=NULL){
        if(temp->data == 0){
            cnt0++;
        }
        else if(temp->data == 1){
            cnt1++;
        }
        else{
            cnt2++;
        }
        len++;
        temp = temp->next;
    }

    temp = head;
    for(int i=0;i<cnt0;i++){
        temp->data = 0;
        temp = temp->next;
    }
    for(int i=cnt0;i<(cnt0+cnt1);i++){
        temp->data = 1;
        temp = temp->next;
    }
    for(int i=(cnt0+cnt1);i<len;i++){
        temp->data = 2;
        temp = temp->next;
    }
}

void display(node* &head){
    node* temp = head;
    while(temp!=NULL){
        cout<< temp->data <<"-->";
        temp = temp->next;
    }
    cout<< "NULL" <<endl;
}

int main(){
    node* head = NULL;
    InsertAtTail(head,1);
    InsertAtTail(head,1);
    InsertAtTail(head,2);
    InsertAtTail(head,0);
    InsertAtTail(head,2);
    InsertAtTail(head,0);
    InsertAtTail(head,1);
    
    display(head);
    SortList(head);
    display(head);
    
    return 0;
}