#include<iostream>
#include<cstring>
using namespace std;

void productArr(int arr[], int n){
    if(n == 1){
        cout<< 0;
        return;
    }
    int temp=1;
    
    int *prod = new int[(sizeof(int) * n)];
    memset(prod,1,n);
    
    for(int i=0;i<n;i++){
        prod[i] = temp;
        temp *= arr[i];
    }
    
    temp = 1;
    for(int i=n-1;i>=0;i--){
        prod[i] *= temp;
        temp *= arr[i];
    }
    
    for(int i=0;i<n;i++){
        cout<< prod[i] << " ";
    }
    return ;
}

int main(){
    int arr[] = { 10, 3, 5, 6, 2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout<< "The product array is : \n";
	productArr(arr,n);
	
	return 0;
}