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
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxRow=0;
        int maxCol=0;
        for(auto it:stones){
            maxRow=max(maxRow,it[0]);
            maxCol=max(maxCol,it[1]);
        }
        DisjointSet ds(maxRow+maxCol+1);
        unordered_map<int,int>stoneNode;
        for(auto it:stones){
            int rowNode=it[0];
            int colNode=it[1]+maxRow+1;
            ds.unionBySize(rowNode,colNode);
            stoneNode[rowNode]=1;
            stoneNode[colNode]=1;
        }
        int components=0;
        for(auto it:stoneNode){
            if(ds.findUPar(it.first)==it.first) components++;
        }
        return n-components;
    }
};