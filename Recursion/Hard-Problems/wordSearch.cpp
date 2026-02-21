//Word Search

// Given a grid of n x m dimension grid of characters board and a string word.The word can be created by assembling the letters of successively surrounding cells, whether they are next to each other vertically or horizontally. It is forbidden to use the same letter cell more than once.

// Return true if the word exists in the grid otherwise false.


// Example 1

// Input : board = [ ["A", "B", "C", "E"] , ["S" ,"F" ,"C" ,"S"] , ["A", "D", "E", "E"] ] , word = "ABCCED"

// Output : true


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& vis,
             string &word, int i, int j, int idx) {

        if (idx == word.size() - 1) return true;

        int r = board.size();
        int c = board[0].size();

        vis[i][j] = true;

        // left
        if (j - 1 >= 0 && !vis[i][j - 1] && board[i][j - 1] == word[idx + 1] &&
            dfs(board, vis, word, i, j - 1, idx + 1))
            return true;

        // up
        if (i - 1 >= 0 && !vis[i - 1][j] && board[i - 1][j] == word[idx + 1] &&
            dfs(board, vis, word, i - 1, j, idx + 1))
            return true;

        // right
        if (j + 1 < c && !vis[i][j + 1] && board[i][j + 1] == word[idx + 1] &&
            dfs(board, vis, word, i, j + 1, idx + 1))
            return true;

        // down
        if (i + 1 < r && !vis[i + 1][j] && board[i + 1][j] == word[idx + 1] &&
            dfs(board, vis, word, i + 1, j, idx + 1))
            return true;

        vis[i][j] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size();
        int c = board[0].size();

        vector<vector<bool>> vis(r, vector<bool>(c, false));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] == word[0] &&
                    dfs(board, vis, word, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {
    Solution obj;

    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    string word;
    cout << "Enter word to search: ";
    cin >> word;

    if (obj.exist(board, word))
        cout << "Word exists in board\n";
    else
        cout << "Word does not exist\n";

    return 0;
}