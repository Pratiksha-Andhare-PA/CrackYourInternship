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
        return ;
    }
    
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

long long multiplyLists(node* &l1, node* &l2){
    long long N = 1000000007;
    long long num1=0, num2=0;
    
    while(l1!=NULL || l2!=NULL){
        if(l1){
            num1 = (num1*10)%N + l1->data;
            l1 = l1->next;
        }
        if(l2){
            num2 = (num2*10)%N + l2->data;
            l2 = l2->next;
        }
    }
    return ((num1%N) * (num2%N))%N;
}

void display(node* &head){
    node* temp = head;
    while(temp != NULL){
        cout<< temp->data <<" ";
        temp = temp->next;
    }
    cout<< endl;
}

int main(){
    node* l1 = NULL;
    Insert(l1,3);
    Insert(l1,2);
    Insert(l1,1);
    
    node* l2 = NULL;
    Insert(l2,1);
    Insert(l2,2);
    
    cout<< "l1 : ";
    display(l1);
    cout<< "l2 : ";
    display(l2);
    
    cout<< "Multiplication : " << multiplyLists(l1,l2) <<endl;
    
    return 0;
}