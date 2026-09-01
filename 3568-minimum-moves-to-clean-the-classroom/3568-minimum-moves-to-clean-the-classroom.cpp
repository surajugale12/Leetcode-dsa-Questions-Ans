#include <vector>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        int startI = -1, startJ = -1;
        int litterC = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    startI = i;
                    startJ = j;
                } else if (classroom[i][j] == 'L') {
                    litterC++;
                }
            }
        }

        if (litterC == 0) return 0;

        int fullMask = (1 << litterC) - 1;
        vector<vector<vector<int>>> bestEnergy(m, vector<vector<int>>(n, vector<int>(1 << litterC, -1)));
        
        vector<pair<int, int>> litterP;
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(classroom[i][j] == 'L') litterP.push_back({i, j});
            }
        }

        queue<tuple<int, int, int, int, int>> q; 
        q.push({startI, startJ, 0, energy, 0});
        bestEnergy[startI][startJ][0] = energy;

        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        while (!q.empty()) {
            auto [r, c, mask, e, steps] = q.front();
            q.pop();

            if (mask == fullMask) return steps;

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && classroom[nr][nc] != 'X') {
                    int newEnergy = e - 1;

                    if (newEnergy < 0) continue;

                    int newMask = mask;
                    for (int k = 0; k < litterC; ++k) {
                        if (litterP[k].first == nr && litterP[k].second == nc) {
                            newMask |= (1 << k);
                            break;
                        }
                    }

                    if (classroom[nr][nc] == 'R') {
                        newEnergy = energy;
                    }

                    if (newEnergy <= bestEnergy[nr][nc][newMask]) continue;
                    
                    bestEnergy[nr][nc][newMask] = newEnergy;
                    q.push({nr, nc, newMask, newEnergy, steps + 1});
                }
            }
        }

        return -1;
    }
};