//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        int left=0, right=0;
        int sLen = s.length();
        int pLen = p.length();
        int minWindowSize = INT_MAX;
        int startIdx = -1;
        
        vector<int> freqS(26,0);
        vector<int> freqP(26,0);
        
        for (auto x : p) {
            freqP[x - 'a']++;
        }
        
        int charsToMatch = pLen;
        while(right < sLen){
            char currChar = s[right];
            
            if(freqP[currChar - 'a'] > 0){
                freqS[currChar - 'a']++;
                if (freqS[currChar - 'a'] <= freqP[currChar - 'a']) {
                    charsToMatch--;
                }
            }
            
            while (charsToMatch == 0) {
                int windowSize = right - left + 1;
                if (windowSize < minWindowSize) {
                    minWindowSize = windowSize;
                    startIdx = left;
                }

                char leftChar = s[left];
                if (freqP[leftChar - 'a'] > 0) {
                    freqS[leftChar - 'a']--;
                    if (freqS[leftChar - 'a'] < freqP[leftChar - 'a']) {
                        charsToMatch++;
                    }
                }
    
                left++;
            }
    
            right++;
        }
        
        if (startIdx == -1) {
            return "-1";
        }

        return s.substr(startIdx, minWindowSize);

    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
