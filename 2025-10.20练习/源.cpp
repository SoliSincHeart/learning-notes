class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i)
        {
            if (board[i][0] == 'O')
            {
                dfs(board, i, 0, visited);
            }
            if (board[i][n - 1] == 'O')
            {
                dfs(board, i, n - 1, visited);
            }
        }
        for (int j = 0; j < n; ++j)
        {
            if (board[0][j] == 'O')
            {
                dfs(board, 0, j, visited);
            }
            if (board[m - 1][j] == 'O')
            {
                dfs(board, m - 1, j, visited);
            }
        }
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (!visited[i][j])
                {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& visited)
    {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || visited[i][j] || board[i][j] == 'X')
        {
            return;
        }
        visited[i][j] = true;
        int dx[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
        for (int k = 0; k < 4; ++k)
        {
            int x = i + dx[k][0];
            int y = j + dx[k][1];
            dfs(board, x, y, visited);
        }
    }
};