#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int R = grid.size(), C = grid[0].size();
        vector<vector<vector<bool>>> dp(R+1,vector<vector<bool>>(C+1, vector<bool>(R+C+1, false)));
        dp[R][C-1][0]=true;
        dp[R-1][C][0]=true;
        for(int r=R-1;r>=0;r--)
        {
            for(int c=C-1;c>=0;c--)
            {
                int inc = (grid[r][c]==')'?-1:1);
                for(int i=0;i<R+C;i++)
                {
                    if(i+inc>=0) dp[r][c][i] = dp[r+1][c][i+inc] || dp[r][c+1][i+inc];
                }
            }
        }
        return dp[0][0][0];
    }
};

int main()
{
    vector<vector<char>> grid = {{'(','(','(','(','(',')',')','(',')',')','(',')',')','(',')','(','(',')',')','(',')','(',')',')','(',')',')',')',')','(',')','(','('},
                                 {'(',')',')','(','(',')',')',')',')','(',')','(',')','(',')','(','(',')',')','(','(','(','(',')',')',')',')',')','(','(',')','(','('},
                                 {')',')','(','(',')',')',')',')','(',')','(',')',')',')','(','(',')','(',')','(','(','(',')',')',')',')',')',')',')',')',')','(','('},
                                 {'(','(','(',')','(',')',')',')','(',')','(','(','(',')','(',')','(',')','(',')','(',')','(',')',')',')','(','(',')','(',')',')',')'},
                                 {')','(',')','(',')',')',')',')','(','(','(','(',')','(',')','(','(','(','(','(',')','(','(',')',')','(','(','(',')','(',')',')','('},
                                 {')',')',')','(',')',')',')','(','(',')',')','(','(','(','(',')','(','(',')',')','(',')',')',')','(',')',')','(',')',')','(','(','('},
                                 {')','(',')','(','(',')',')','(',')',')',')','(','(','(',')','(','(','(',')','(',')','(',')',')',')',')',')','(',')',')','(','(',')'},
                                 {'(','(',')',')','(',')',')','(','(','(','(',')','(',')','(','(','(','(','(','(',')','(',')','(',')',')','(','(','(',')','(','(',')'},
                                 {')',')','(','(',')',')','(','(','(','(','(','(','(',')',')','(','(','(',')',')','(',')','(','(',')',')','(',')',')','(',')','(','('},
                                 {')',')',')',')','(',')',')','(','(','(','(',')',')',')','(',')',')',')',')',')',')','(','(','(','(',')',')',')',')','(','(','(',')'}};
    Solution s;
    cout << s.hasValidPath(grid) << '\n';


    return 0;
}