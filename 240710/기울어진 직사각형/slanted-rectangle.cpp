#include <iostream>
#include <queue>
using namespace std;

const int MAX_SIZE = 20;
int grid[MAX_SIZE][MAX_SIZE] = {0};

int in_range(int n, int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < n;
}

int search(int n, int i, int j)
{
    int max_sum = 0;
    int sum = 0;
    int x = i;
    int y = j;
    int dx[4] = {1, 1, -1, -1};
    int dy[4] = {-1, 1, 1, -1};

    for (int a = 1; a < n - i; a++)
    {
        for (int b = 1; b <= min(j, n - j - 1); b++)
        {
            // width = a, height = b 인 square
            sum = 0;
            int flag = 0;
            int len[2] = {a, b};

            for(int dir = 0; dir < 4; dir++){
                if (!in_range(n, x + len[dir%2] * dx[dir], y + len[dir%2] * dy[dir]))
                {
                    flag = 1;
                    break;
                }
                for (int iter = 1; iter <= len[dir%2]; iter++)
                {
                    sum += grid[x + iter * dx[dir]][y + iter * dy[dir]];
                }
                x = x + len[dir%2] * dx[dir];
                y = y + len[dir%2] * dy[dir];
            }
            
            if(!flag) max_sum = max(max_sum, sum);
        }
    }

    return max_sum;
}

int main()
{
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    int res = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // cout << i << "," << j << ": " << search(n, i, j) << endl;
            res = max(res, search(n, i, j));
        }
    }
    cout << res << endl;
}