#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSum(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int minArea = INT_MAX;
        //getting bounding area
        auto getBoundingArea = [&](int r1, int r2, int c1, int c2) -> int {
            int top = INT_MAX, bottom = INT_MIN;
            int left = INT_MAX, right = INT_MIN;
            bool found = false;
            
            for (int i = r1; i <= r2; i++) {
                for (int j = c1; j <= c2; j++) {
                    if (grid[i][j]) {
                        if (!found) {
                            found = true;
                            top = bottom = i;
                            left = right = j;
                        } else {
                            if (i < top) top = i;
                            if (i > bottom) bottom = i;
                            if (j < left) left = j;
                            if (j > right) right = j;
                        }
                    }
                }
            }
            
            return found ? (bottom - top + 1) * (right - left + 1) : 0;
        };
        
        for (int r1 = 0; r1 < m - 2; r1++) {
            for (int r2 = r1 + 1; r2 < m - 1; r2++) {
                int a1 = getBoundingArea(0, r1, 0, n - 1);
                if (a1 == 0) continue;
                int a2 = getBoundingArea(r1 + 1, r2, 0, n - 1);
                if (a2 == 0) continue;
                int a3 = getBoundingArea(r2 + 1, m - 1, 0, n - 1);
                if (a3 == 0) continue;
                
                int total = a1 + a2 + a3;
                if (total < minArea) minArea = total;
            }
        }
        
        for (int c1 = 0; c1 < n - 2; c1++) {
            for (int c2 = c1 + 1; c2 < n - 1; c2++) {
                int a1 = getBoundingArea(0, m - 1, 0, c1);
                if (a1 == 0) continue;
                int a2 = getBoundingArea(0, m - 1, c1 + 1, c2);
                if (a2 == 0) continue;
                int a3 = getBoundingArea(0, m - 1, c2 + 1, n - 1);
                if (a3 == 0) continue;
                
                int total = a1 + a2 + a3;
                if (total < minArea) minArea = total;
            }
        }
        
        for (int r = 0; r < m - 1; r++) {
            for (int c = 0; c < n - 1; c++) {
                int a1 = getBoundingArea(0, r, 0, n - 1);
                if (a1 > 0) {
                    int a2 = getBoundingArea(r + 1, m - 1, 0, c);
                    int a3 = getBoundingArea(r + 1, m - 1, c + 1, n - 1);
                    if (a2 > 0 && a3 > 0) {
                        int total = a1 + a2 + a3;
                        if (total < minArea) minArea = total;
                    }
                }
                
                a1 = getBoundingArea(0, r, 0, c);
                if (a1 > 0) {
                    int a2 = getBoundingArea(0, r, c + 1, n - 1);
                    int a3 = getBoundingArea(r + 1, m - 1, 0, n - 1);
                    if (a2 > 0 && a3 > 0) {
                        int total = a1 + a2 + a3;
                        if (total < minArea) minArea = total;
                    }
                }
                
                a1 = getBoundingArea(0, m - 1, 0, c);
                if (a1 > 0) {
                    int a2 = getBoundingArea(0, r, c + 1, n - 1);
                    int a3 = getBoundingArea(r + 1, m - 1, c + 1, n - 1);
                    if (a2 > 0 && a3 > 0) {
                        int total = a1 + a2 + a3;
                        if (total < minArea) minArea = total;
                    }
                }
                
                a1 = getBoundingArea(0, r, 0, c);
                if (a1 > 0) {
                    int a2 = getBoundingArea(r + 1, m - 1, 0, c);
                    int a3 = getBoundingArea(0, m - 1, c + 1, n - 1);
                    if (a2 > 0 && a3 > 0) {
                        int total = a1 + a2 + a3;
                        if (total < minArea) minArea = total;
                    }
                }
            }
        }
        
        return minArea;
    }
};
