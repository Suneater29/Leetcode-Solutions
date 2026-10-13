class DisjointSet{
public:
    vector<int>parent;
    vector<int>rank;
    vector<int>size;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;    
            size[i]=1;
        }
    }

    int findUPar(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUPar(parent[node]);
    }

    void unionByRank(int u,int v){
        int pu=findUPar(u);
        int pv=findUPar(v);
        if(pu==pv) return;
        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
            rank[pv]+=rank[pu];
        }
        else{
            parent[pv]=pu;
            rank[pu]+=rank[pv];
        }
    }

    void unionBySize(int u,int v){
        int pu=findUPar(u);
        int pv=findUPar(v);
        if(pu==pv) return;
        if(size[pu] < size[pv]){
            parent[pu]=pv;
        }
        else if(size[pv] < size[pu]){
            parent[pv]=pu;
        }
        else{
            parent[pv]=pu;
            size[pu]++;
        }
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    ds.unionBySize(i,j);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) ans++;
        }
        return ans;
    }
};