class ReconstructItinerary {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> graph;
        for(auto ticket : tickets) {
            string src = ticket[0];
            string dest = ticket[1];
            graph[src].push_back(dest);
        }
        
        for(auto& node : graph) {
            sort(node.second.begin(), node.second.end());
        }
        
        vector<string> result;
        dfs("JFK", result, graph);
        
        reverse(result.begin(), result.end());
        return result;
    }
    
    void dfs(string src_node, vector<string>& result, unordered_map<string, vector<string>>& graph) {
        if(graph.find(src_node) != graph.end()) {
            auto neighbours = graph[src_node];
            while(!neighbours.empty()) {
                string neigh = neighbours[0];
                neighbours.erase(neighbours.begin());
                dfs(neigh, result, graph);
            }
        }
        
        result.push_back(src_node);
    }
};
