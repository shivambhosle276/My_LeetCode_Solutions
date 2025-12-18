class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int longestTime = logs[0][1];
        int longestId = logs[0][0];

        for(int i = 1; i < logs.size(); i++) {
            int time = logs[i][1] - logs[i-1][1];
            if(time > longestTime) {
                longestTime = time;
                longestId = logs[i][0];
            } else if (time == longestTime) {
                longestId = min(longestId, logs[i][0]);
            }
        }

        return longestId;
    }
};