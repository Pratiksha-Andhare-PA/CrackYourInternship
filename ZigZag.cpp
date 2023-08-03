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

void Insert(node* &head, int val){
    node* n = new node(val);
    if(head == NULL){
        head = n;
        return;
    }
    node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = n;
}

node* zigzag(node* &head, bool flag){
    if(!head || !head->next){
        return head;
    }
    if(flag == 1){
        if(head->data > head->next->data){
            swap(head->data, head->next->data);
        }
        return zigzag(head->next, !flag);
    }
    else{
        if(head->data < head->next->data){
            swap(head->data, head->next->data);
        }
        return zigzag(head->next, !flag);
    }
}

void display(node* &head){
    node* temp = head;
    while(temp){
        cout<< temp->data <<" ";
        temp = temp->next;
    }
    cout<< endl;
}

int main(){
    node* head = NULL;
    Insert(head,10);
    Insert(head,5);
    Insert(head,20);
    Insert(head,15);
    Insert(head,11);
    
    display(head);
    zigzag(head,1);
    display(head);
    
    return 0;
}