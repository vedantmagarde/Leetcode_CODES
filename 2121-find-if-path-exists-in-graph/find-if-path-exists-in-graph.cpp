class Solution {
public:
    vector<list<int>> graph;
    void add_edge(int src, int dest) {
        graph[src].push_back(dest);
        graph[dest].push_back(src); // both directional.....
    }
    void f(vector<int>& visited, int curr, int destination, bool& ans) {
        // if (visited[curr] == true)
        //     return;
        visited[curr] = true;
        if (curr == destination) {
            ans = true;
            return;
        }
        for (auto itr : graph[curr]) {
            if (visited[itr] == false) // explore karna hai.....
                f(visited, itr, destination, ans);
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        graph.resize(n);
        for (int i = 0; i < edges.size(); i++) {
            add_edge(edges[i][0], edges[i][1]);
        }
        vector<int> visited(n, false);
        bool ans = false;
        f(visited, source, destination, ans);
        return ans;
    }
};