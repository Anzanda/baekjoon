#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int n, ans;
vector<vector<int>> right(vector<vector<int>> board)
{
    vector<vector<bool>> check(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            if (board[i][j] == 0)
                continue;
            for (int k = j + 1; k < n; k++)
            {
                if (board[i][k] == board[i][k - 1] && !check[i][k])
                {
                    board[i][k] *= 2;
                    board[i][k - 1] = 0;
                    check[i][k] = true;
                    break;
                }
                else if (board[i][k] == 0)
                {
                    board[i][k] = board[i][k - 1];
                    board[i][k - 1] = 0;
                }
                else
                {
                    break;
                }
            }
        }
    }
    return board;
}
vector<vector<int>> left(vector<vector<int>> board)
{
    vector<vector<bool>> check(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (board[i][j] == 0)
                continue;
            for (int k = j - 1; k >= 0; k--)
            {
                if (board[i][k] == board[i][k + 1] && !check[i][k])
                {
                    board[i][k] *= 2;
                    board[i][k + 1] = 0;
                    check[i][k] = true;
                    break;
                }
                else if (board[i][k] == 0)
                {
                    board[i][k] = board[i][k + 1];
                    board[i][k + 1] = 0;
                }
                else
                {
                    break;
                }
            }
        }
    }
    return board;
}
vector<vector<int>> down(vector<vector<int>> board)
{
    vector<vector<bool>> check(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            if (board[j][i] == 0)
                continue;
            for (int k = j + 1; k < n; k++)
            {
                if (board[k][i] == board[k - 1][i] && !check[k][i])
                {
                    board[k][i] *= 2;
                    board[k - 1][i] = 0;
                    check[k][i] = true;
                    break;
                }
                else if (board[k][i] == 0)
                {
                    board[k][i] = board[k - 1][i];
                    board[k - 1][i] = 0;
                }
                else
                {
                    break;
                }
            }
        }
    }
    return board;
}
vector<vector<int>> up(vector<vector<int>> board)
{
    vector<vector<bool>> check(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (board[j][i] == 0)
                continue;
            for (int k = j - 1; k >= 0; k--)
            {
                if (board[k][i] == board[k + 1][i] && !check[k][i])
                {
                    board[k][i] *= 2;
                    board[k + 1][i] = 0;
                    check[k][i] = true;
                    break;
                }
                else if (board[k][i] == 0)
                {
                    board[k][i] = board[k + 1][i];
                    board[k + 1][i] = 0;
                }
                else
                {
                    break;
                }
            }
        }
    }
    return board;
}

void dfs(int now, vector<vector<int>> board) {
    if(now == 5) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(ans < board[i][j]) {
                    ans = board[i][j];
                }
            }
        
        }
        return;
    }
    dfs(now+1, right(board));
    dfs(now+1, left(board));
    dfs(now+1, up(board));
    dfs(now+1, down(board));
}
int main(void) {
    FastIO;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
           cin >> board[i][j]; 
        }
    }
    dfs(0, board);
    cout << ans << endl;
    return 0;
}