#include<iostream>
#include<unordered_map>
using namespace std;

void printDuplicates(string str){
    unordered_map<char,int>mp;
    for(int i=0;i<str.length();i++){
        mp[str[i]]++;
    }
    
    for(auto ch : mp){
        if(ch.second > 1){
            cout<< ch.first << " - " << ch.second << " times"<<endl;
        }
    }
}

int main(){
    string str;
    cout<< "Enter a string : ";
    getline(cin,str);
    printDuplicates(str);
    
    return 0;
}
