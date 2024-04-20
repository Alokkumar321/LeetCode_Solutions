class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> result;
        int m = land.size();
        int n = land[0].size();
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (land[i][j] == 1) {
                    int bottomRightI = i;
                    int bottomRightJ = j;
                    while (bottomRightI < m && land[bottomRightI][j] == 1) {
                        while (bottomRightJ < n && land[i][bottomRightJ] == 1) {
                            ++bottomRightJ;
                        }
                        ++bottomRightI;
                    }                 
                    --bottomRightJ;
  
                    result.push_back({i, j, bottomRightI - 1, bottomRightJ});
                    for (int p = i; p < bottomRightI; ++p) {
                        for (int q = j; q <= bottomRightJ; ++q) {
                            land[p][q] = 0;
                        }
                    }
                }
            }
        }
        
        return result;
    }
};
