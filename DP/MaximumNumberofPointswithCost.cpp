class Solution {
public:
    using vvi = vector<vector<long long>>;
    int n, m;
    vector<vector<int>> points;

    vvi c1, c2, c3;
    
    
    long long helper1(int i, int x){
        // Max of (rec(i+1, c) + points[i][c] - c) for c >= x
        if(x == m) return -1e18;
        if(c1[i][x] != -1e18) return c1[i][x];
        
        long long val = rec(i+1, x) + points[i][x] - x;
        return c1[i][x] = max(val, helper1(i, x+1));
    }

    long long helper2(int i, int x){
        // Max of (rec(i+1, c) + points[i][c] + c) for c <= x
        if(x == -1) return -1e18;
        if(c2[i][x] != -1e18) return c2[i][x];
        
        long long val = rec(i+1, x) + points[i][x] + x;
        return c2[i][x] = max(val, helper2(i, x-1));
    }

    long long rec(int i, int pcol){
        if(i == n) return 0;
        if(pcol != -1 && c3[i][pcol] != -1e18) return c3[i][pcol];
        
        long long ans = -1e18;
        
        if(pcol == -1) {
            // First row - no penalty
            for(int c = 0; c < m; c++) {
                ans = max(ans, (long long)points[i][c] + rec(i+1, c));
            }
            return ans;
        }
        
        // Coming from left (columns <= pcol): penalty = pcol - c
        // (points[i][c] + rec(i+1, c)) - (pcol - c) = (points[i][c] + c + rec(i+1, c)) - pcol
        long long val1 = helper2(i, pcol) - pcol;
        
        // Coming from right (columns >= pcol): penalty = c - pcol
        // (points[i][c] + rec(i+1, c)) - (c - pcol) = (points[i][c] - c + rec(i+1, c)) + pcol
        long long val2 = helper1(i, pcol) + pcol;
        
        ans = max(val1, val2);
        
        return c3[i][pcol] = ans;
    }

    long long maxPoints(vector<vector<int>>& points) {
        this->points = points;
        n = points.size();
        m = points[0].size();
        
        c1.assign(n, vector<long long>(m, -1e18));
        c2.assign(n, vector<long long>(m, -1e18));
        c3.assign(n, vector<long long>(m, -1e18));
        
        return rec(0, -1);
    }
};
