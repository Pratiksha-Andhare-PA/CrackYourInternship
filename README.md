class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        vector<pair<int,int>> v;
        
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 0){
                    v.push_back({i,j});
                }
            }
        }
        
        for(auto x : v){
            int a = x.first;
            int b = x.second;    
        
            for(int i=0;i<m;i++){
                matrix[i][b] = 0;
            }
            for(int j=0;j<n;j++){
                matrix[a][j] = 0;
            }
        }   
    }
};
