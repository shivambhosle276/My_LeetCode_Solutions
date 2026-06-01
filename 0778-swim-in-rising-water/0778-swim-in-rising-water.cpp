class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>> pq;

        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0,0}});

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if(r == n-1 && c == m-1)
                return dis;

            for(int i = 0; i < 4; i++) {
                int newr = r + dr[i];
                int newc = c + dc[i];

                if(newr >= 0 && newr < n &&
                   newc >= 0 && newc < m) {

                    int newTime = max(dis, grid[newr][newc]);

                    if(newTime < dist[newr][newc]) {
                        dist[newr][newc] = newTime;
                        pq.push({newTime, {newr, newc}});
                    }
                }
            }
        }

        return -1;
    }
};