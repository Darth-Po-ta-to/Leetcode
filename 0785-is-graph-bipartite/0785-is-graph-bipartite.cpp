class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        for (int i = 0; i < graph.size(); i++) {
            if (color[i] != -1)
                continue;
            queue<int> q;
            q.push(i);
            color[i] = 1;

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (auto i : graph[node]) {
                    if (color[i] == -1) {
                        if (color[node] == 1)
                           { color[i] = 2;}
                        else
                           { color[i] = 1;}
                           q.push(i);

                    
                    } else if (color[i] == color[node])
                        return false;
                }
            }
        }
        return true;
    }
};