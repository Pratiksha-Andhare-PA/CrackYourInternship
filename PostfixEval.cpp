#include<iostream>
#include<stack>
#include<cmath>
using namespace std;

int PostfixEval(string str){
    stack<int> st;
    int op1,op2;
    
    for(int i=0;i<str.length();i++){
        if(str[i]>='0' && str[i]<='9'){
            st.push(str[i]-'0');
        }
        else{
            op2 = st.top();
            st.pop();
            op1 = st.top();
            st.pop();
            
            switch(str[i]){
                case '+' : st.push(op1+op2);
                    break;
                case '-' : st.push(op1-op2);
                    break;
                case '*' : st.push(op1*op2);
                    break;
                case '/' : st.push(op1/op2);
                    break;
                case '^': st.push(pow(op1,op2));
                    break;
            }
        }
    }
    return st.top();
}

int main(){
    string str = "231*+9-";
    cout<< PostfixEval(str) <<endl;
    
    return 0;
}