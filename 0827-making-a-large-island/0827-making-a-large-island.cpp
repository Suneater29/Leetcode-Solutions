class DisjointSet {
public:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;
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
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                int delrow[]={-1,0,1,0};
                int delcol[]={0,-1,0,1};
                for(int k=0;k<4;k++){
                    int newr=i+delrow[k];
                    int newc=j+delcol[k];
                    if(newr>=0 && newr<n && newc>=0 && newc<n && grid[newr][newc]==1){
                        int nodenum=i*n+j;
                        int adjnodenum=newr*n+newc;
                        ds.unionBySize(nodenum,adjnodenum);
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) continue;
                int delrow[]={-1,0,1,0};
                int delcol[]={0,-1,0,1};
                set<int>st;
                for(int k=0;k<4;k++){
                    int newr=i+delrow[k];
                    int newc=j+delcol[k];
                    if(newr>=0 && newr<n && newc>=0 && newc<n && grid[newr][newc]==1){
                        int nodenum=newr*n+newc;
                        st.insert(ds.findUPar(nodenum));
                    }
                }
                int total=1;
                for(auto it:st){
                    total+=ds.size[it];
                }
                ans=max(ans,total);
            }
        }
        for(int i=0;i<n;i++){
            ans=max(ans,ds.size[ds.findUPar(i)]);
        }
        return ans;
    }
};