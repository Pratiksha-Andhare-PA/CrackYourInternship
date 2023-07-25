#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* next;
    node* prev;
    
    node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class deque{
public:
    int num_ele;
    node* front;
    node* rear;
    
    deque(){
        num_ele = 0;
        front=rear=NULL;
    }
    
    void push_front(int val){
        node* n = new node(val);
        if(isEmpty()){
            front = rear = n;
        }
        else{
            n->next = front;
            front->prev = n;
            front = n;
        }
        num_ele++;
    }
    
    void push_back(int val){
        node* n = new node(val);
        if(isEmpty()){
            front = rear = n;
        }
        else{
            rear->next = n;
            n->prev = rear;
            rear = n;
        }
        num_ele++;
    }
    
    void pop_front(){
        if(!isEmpty()){
            node* todelete = front;
            front = front->next;
            if(front)
                front->prev = NULL;
            delete todelete;
            num_ele--;
        }
    }
    
    void pop_back(){
        if(!isEmpty()){
            node* todelete = rear;
            rear = rear->prev;
            if(rear)
                rear->next = NULL;
            delete todelete;
            num_ele--;
        }
    }
    
    int frontEle(){
        return front->data;
    }
    
    int backEle(){
        return rear->data;
    }
    
    bool isEmpty(){
        return num_ele == 0;
    }
    
    int size(){
        return num_ele;
    }
    
    ~deque(){
        while(!isEmpty()){
            pop_front();
        }
    }
};

class stack{
    deque dq;
    
public:
    void push(int val){
        dq.push_front(val);
    }
    void pop(){
        dq.pop_front();
    }
    int top(){
        return dq.frontEle();
    }
    bool empty(){
        return dq.isEmpty();
    }
    int size(){
        return dq.size();
    }
    
};

class queue{
    deque dq;
    
public:
    void push(int val){
        dq.push_back(val);
    }
    void pop(){
        dq.pop_front();
    }
    int front(){
        return dq.frontEle();
    }
    bool empty(){
        return dq.isEmpty();
    }
    int size(){
        return dq.size();
    }
    
};

int main(){
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    
    cout<< "Stack : ";
    while(!st.empty()){
        cout<< st.top() <<" ";
        st.pop();
    }
    cout<< endl;
    
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    
    cout<< "Queue : ";
    while(!q.empty()){
        cout<< q.front() <<" ";
        q.pop();
    }
    cout<< endl;
    
    return 0;
}