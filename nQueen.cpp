#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row, int col, vector<string> &board, int n)
{
    int dr = row;
    int dc = col;
    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }
    row = dr;
    col = dc;
    while (col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
    }
    row = dr;
    col = dc;
    while (row < n && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row++;
        col--;
    }
    return true;
}

void solveByBacktrack(int col, vector<vector<string>> &ans, vector<string> &board, int n)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 'Q';
            solveByBacktrack(col + 1, ans, board, n);
            board[row][col] = '-';
        }
    }
}

void print(vector<vector<string>> &ans)
{

    for (int i = 0; i < ans.size(); i++)
    {
        cout << "\nBoard : " << i + 1 << "\n";
        for (int j = 0; j < ans[i].size(); j++)
        {
            for (int k = 0; k < ans[i][j].size(); k++)
            {
                cout << ans[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

void solveByBranchAndBound(int col, vector<vector<string>> &ans, vector<string> &board, int n, vector<int> &leftrow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (leftrow[row] == 0 && upperDiagonal[n - 1 + col - row] == 0 && lowerDiagonal[row + col] == 0)
        {
            board[row][col] = 'Q';
            leftrow[row] = 1;
            upperDiagonal[n - 1 + col - row] = 1;
            lowerDiagonal[row + col] = 1;
            solveByBranchAndBound(col + 1, ans, board, n, leftrow, upperDiagonal, lowerDiagonal);
            board[row][col] = '-';
            leftrow[row] = 0;
            upperDiagonal[n - 1 + col - row] = 0;
            lowerDiagonal[row + col] = 0;
        }
    }
}

int main()
{
    int n;
    cout << "\nEnter no of queens = ";
    cin >> n;
    string s(n, '-');
    vector<vector<string>> ans;
    vector<string> board(n, s);

    solveByBacktrack(0, ans, board, n);
    cout << "\nAns by backtracking = \nTotal solutions = " << ans.size() << endl;
    print(ans);

    ans.clear();
    board.clear();
    s.assign(n, '-');
    board.assign(n, s);

    vector<int> leftrow(n, 0);
    vector<int> upperDiagonal(2 * n - 1, 0);
    vector<int> lowerDiagonal(2 * n - 1, 0);

    solveByBranchAndBound(0, ans, board, n, leftrow, upperDiagonal, lowerDiagonal);
    cout << "\nAns by branch and bound = \nTotal solutions = " << ans.size() << endl;
    print(ans);
}