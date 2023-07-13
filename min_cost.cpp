#include<iostream>
#include<cstring>
using namespace std;

int minCostToMakeElementEqual(int arr[],int n){
    int y;
    if(n%2 == 1){
        y = arr[n/2];
    }
    else{
        y = (arr[n/2]+arr[(n/2)-1])/2;
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        ans += abs(arr[i]-y);
    }
    return ans;
}

int main(){
    int arr[] = { 1, 100, 101 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout<< minCostToMakeElementEqual(arr,n) <<endl;
	
	return 0;
}