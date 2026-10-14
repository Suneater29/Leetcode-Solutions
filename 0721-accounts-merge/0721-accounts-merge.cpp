class DisjointSet {
    vector<int> parent;
    vector<int> rank;
    vector<int> size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv)
            return;
        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } 
        else if(rank[pv]<rank[pu]){
            parent[pv]=pu;
        }
        else{
            parent[pv] = pu;
            rank[pu] ++;
        }
    }

    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv)
            return;
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv]+=size[pu];
        } else {
            parent[pv] = pu;
            size[pu]+=size[pv];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int>mpp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mpp.find(mail)==mpp.end()){
                    mpp[mail]=i;
                }
                else{
                    ds.unionBySize(i,mpp[mail]);
                }
            }
        }
        vector<vector<string>>mergedMail(n);
        for(auto it:mpp){
            string mail=it.first;
            int node=ds.findUPar(it.second);
            mergedMail[node].push_back(mail);
        }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(mergedMail[i].empty()) continue;
            sort(mergedMail[i].begin(),mergedMail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it:mergedMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};