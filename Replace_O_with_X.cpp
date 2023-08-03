#include <iostream>
#include <vector>

using namespace std;

// Function to perform DFS to mark 'O's that are not surrounded by 'X'
void dfs(vector<vector<char>>& board, int row, int col) {
    int rows = board.size();
    int cols = board[0].size();

    if (row < 0 || row >= rows || col < 0 || col >= cols || board[row][col] != 'O') {
        return;
    }

    board[row][col] = '#'; // Mark 'O' as visited temporarily

    // Visit adjacent cells
    dfs(board, row - 1, col);
    dfs(board, row + 1, col);
    dfs(board, row, col - 1);
    dfs(board, row, col + 1);
}

// Function to replace surrounded 'O's with 'X's
void replaceSurroundedRegions(vector<vector<char>>& board) {
    int rows = board.size();
    int cols = board[0].size();

    // Traverse the boundary and mark all connected 'O's as visited temporarily
    for (int row = 0; row < rows; ++row) {
        if (board[row][0] == 'O') {
            dfs(board, row, 0);
        }
        if (board[row][cols - 1] == 'O') {
            dfs(board, row, cols - 1);
        }
    }

    for (int col = 0; col < cols; ++col) {
        if (board[0][col] == 'O') {
            dfs(board, 0, col);
        }
        if (board[rows - 1][col] == 'O') {
            dfs(board, rows - 1, col);
        }
    }

    // Now, mark all remaining 'O's as 'X's, and restore temporarily marked '#' to 'O'
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            if (board[row][col] == 'O') {
                board[row][col] = 'X';
            } else if (board[row][col] == '#') {
                board[row][col] = 'O';
            }
        }
    }
}

// Utility function to print the matrix
void printMatrix(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char c : row) {
            cout << c << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'X', 'X', 'X'}
    };

    cout << "Original Matrix:" << endl;
    printMatrix(board);

    replaceSurroundedRegions(board);

    cout << "\nModified Matrix:" << endl;
    printMatrix(board);

    return 0;
}
