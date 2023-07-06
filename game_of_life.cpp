class Solution {
public:

    int canLive(vector<vector<int>> &board,int x,int y){
        int cnt = 0;
        int m = board.size();
        int n = board[0].size();
    
        if(x>0 && board[x-1][y] == 1){
            cnt++;
        }
        if(y<n-1 && board[x][y+1] == 1){
            cnt++;
        }
        if(x>0 && y>0 && board[x-1][y-1] == 1){
            cnt++;
        }
        if(x<m-1 && board[x+1][y] == 1){
            cnt++;
        }
        if(y>0 && board[x][y-1] == 1){
            cnt++;
        }
        if (x < m - 1 && y > 0 && board[x + 1][y - 1] == 1) {
            cnt++;
        }
        if(x>0 && y<n-1 && board[x-1][y+1] == 1){
            cnt++;
        }
        if(x<m-1 && y<n-1 && board[x+1][y+1] == 1){
            cnt++;  
        }
        return cnt;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> nextBoard(m, vector<int>(n, 0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int count = canLive(board,i,j);
                if(board[i][j] == 1){
                    if(count<2 || count>3){
                        nextBoard[i][j] = 0;
                    }
                    else{
                        nextBoard[i][j] = 1;
                    }
                }
                else{
                    if(count == 3){
                        nextBoard[i][j] = 1;
                    }
                }
            }
        }
        board = nextBoard;
    }
}; 
