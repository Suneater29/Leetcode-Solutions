class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:times){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
        }
        vector<int>dist(n+1,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            int node=pq.top().second;
            int currTime=pq.top().first;
            pq.pop();
            for(auto it:adj[node]){
                int adjnode=it.first;
                int travelTime=it.second;
                if(currTime+travelTime < dist[adjnode]){
                    dist[adjnode]=currTime+travelTime;
                    pq.push({currTime+travelTime,adjnode});
                }
            }
        }
        int ans=0;
        for(int node=1;node<=n;node++){
            if(dist[node]==1e9) return -1;
            ans=max(ans,dist[node]);
            if(node==n) break;
        }
        return ans;
    }
};