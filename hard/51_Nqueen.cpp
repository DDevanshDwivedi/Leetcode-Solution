class Solution {
    public:
        vector<vector<string>> solveNQueens(int n) {
            vector<string> sitting(n);
            string s = string(n, '.');
            for (int i = 0; i < n; i++)
                sitting[i] = s;
            vector<vector<string>> ans;
            solve(0, ans, sitting, n);
            return ans;
        }
        bool isSafe(int col, int row, vector<string> &sitting, int n) {
        int dc = col, dr = row;
        // Upper-left diagonal
        while (dc >= 0 && dr >= 0) {
            if (sitting[dr][dc] == 'Q')
                return false;
            dc--;
            dr--;
        }
        // Left row
        dc = col;
        while (dc >= 0) {
            if (sitting[row][dc] == 'Q')
                return false;
            dc--;
        }
        // Lower-left diagonal
        dc = col, dr = row;
        while (dc >= 0 && dr < n) {
            if (sitting[dr][dc] == 'Q')
                return false;
            dc--;
            dr++;
        }
        return true;
    }
    
    void solve(int col, vector<vector<string>> &ans, vector<string> &sitting, int n)
    {
        if (col == n)
        {
            ans.push_back(sitting);
            return;
        }
        for (int row = 0; row < n; row++)
        {
            if (isSafe(col, row, sitting, n))
            {
                sitting[row][col] = 'Q';
                solve(col + 1, ans, sitting, n);
                sitting[row][col] = '.';
            }
        }
    }
    };