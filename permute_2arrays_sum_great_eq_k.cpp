#include<iostream>
#include<algorithm>
using namespace std;

bool isExist(int a[],int b[],int n,int k){
    sort(a,a+n);
    sort(b,b+n,greater<int>());
    
    for(int i=0;i<n;i++){
       if(a[i]+b[i] >= k){
           return true;
       }
    }
    return false;
}

int main()
{
    int a[] = {2,1,3};
    int b[] = {7,8,9};
    int k = 10;
    int n = sizeof(a)/sizeof(int);
    cout<< isExist(a,b,n,k);
 
    return 0;
}