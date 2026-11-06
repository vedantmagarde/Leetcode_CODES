class Solution {
public:
    vector<list<int>> graph;

    void add_edge(int src, int des) {
        graph[src].push_back(des);
        graph[des].push_back(src);
    }

    void dfs(int node,unordered_set<int>&visited){
        visited.insert(node);

        for(auto itr:graph[node]){
            if(visited.count(itr)==0){
                dfs(itr,visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        graph.resize(n + 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(isConnected[i][j]==1)
                add_edge(i, j);
            }
        }

        unordered_set<int>visited;
        int count=0;
        for(int i=0;i<n;i++){
            if(visited.count(i)==0){
                count++;
                dfs(i,visited);
            }
        }
        return count;
    }
};