class Solution {
public:
    bool dfs(int start,vector<int> &vis,vector<int> &pathvis,vector<vector<int>> &adj,vector<int> &ans){
        vis[start]=1;
        pathvis[start]=1;
        for(auto it:adj[start]){
            if(!vis[it]){
                if(dfs(it,vis,pathvis,adj,ans)==true) return true;
            }
            else if(pathvis[it]) return true;
        }
        pathvis[start]=0;
        ans.push_back(start);
        return false;
}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& edge : prerequisites) {
            int course = edge[0];
            int prerequisite = edge[1];
            adj[prerequisite].push_back(course);
        }
        
        vector<int>vis(numCourses,0);
        vector<int>pathvis(numCourses,0);
        vector<int>ans;
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,vis,pathvis,adj,ans)) return {};
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};