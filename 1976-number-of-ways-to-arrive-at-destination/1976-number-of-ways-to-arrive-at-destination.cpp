class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        long long mod = 1e9 + 7;

        vector<pair<long long,long long>> adj[n];

        // build graph
        for(auto it : roads)
        {
            long long u = it[0];
            long long v = it[1];
            long long wt = it[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        priority_queue<
            pair<long long,long long>,
            vector<pair<long long,long long>>,
            greater<pair<long long,long long>>
        > pq;

        vector<long long> dist(n, 1e18);
        vector<long long> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;

        pq.push({0, 0});

        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            long long dis = it.first;
            long long node = it.second;

            // skip outdated entries
            if(dis > dist[node]) continue;

            for(auto adjPair : adj[node])
            {
                long long adjNode = adjPair.first;
                long long wt = adjPair.second;

                // shorter path found
                if(dis + wt < dist[adjNode])
                {
                    dist[adjNode] = dis + wt;

                    ways[adjNode] = ways[node];

                    pq.push({dist[adjNode], adjNode});
                }

                // another shortest path found
                else if(dis + wt == dist[adjNode])
                {
                    ways[adjNode] =
                        (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1] % mod;
    }
};