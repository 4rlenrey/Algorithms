#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int row;
    int col;
    cin >> row;
    cin >> col;

    char arr[row][col];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> arr[i][j];

    set<pair<int, int>> walls;

    int dir[4][2] = {{0, 1},
                     {0, -1},
                     {1, 0},
                     {-1, 0}};
    //queue
    queue<pair<int, int>> q;

    //insert the top right corner.
    q.push(make_pair(0, 0));

    //until queue is empty
    while (q.size() > 0)
    {
        pair<int, int> p = q.front();
        q.pop();

        //mark as visited
        arr[p.first][p.second] = 1;

        //check all four directions
        for (int i = 0; i < 4; i++)
        {
            //using the direction array
            int a = p.first + dir[i][0];  //0
            int b = p.second + dir[i][1]; //1

            //not blocked and valid
            if (a >= 0 && b >= 0 && a < row && b < col && arr[a][b] != '#' && arr[a][b] != 1)
            {
                q.push(make_pair(a, b));
            }
            else if (a >= 0 && b >= 0 && a < row && b < col && arr[a][b] == '#')
                walls.insert(std::make_pair(a, b));
        }
    }

    set<pair<int, int>> walls2;

    //queue
    queue<pair<int, int>> q2;

    //insert the top right corner.
    q2.push(make_pair(row - 1, col - 1));

    //until queue is empty
    while (q2.size() > 0)
    {
        pair<int, int> p2 = q2.front();
        q2.pop();

        //mark as visited
        arr[p2.first][p2.second] = 1;

        //check all four directions
        for (int i = 0; i < 4; i++)
        {
            //using the direction array
            int a = p2.first + dir[i][0];  //0
            int b = p2.second + dir[i][1]; //1

            //not blocked and valid
            if (a >= 0 && b >= 0 && a < row && b < col && arr[a][b] != '#' && arr[a][b] != 1)
            {
                q2.push(make_pair(a, b));
            }
            else if (a >= 0 && b >= 0 && a < row && b < col && arr[a][b] == '#')
                walls2.insert(std::make_pair(a, b));
        }
    }
    vector<pair<int, int>> secc;
    set_intersection(walls.begin(), walls.end(), walls2.begin(), walls2.end(),
                     std::inserter(secc, secc.begin()));

    cout << secc.size() << "\n";
}
