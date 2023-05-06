package Java;

import java.util.*;

public class ReconstructItinerary {
    
    public List<String> findItinerary(List<List<String>> tickets) {
        HashMap<String, LinkedList<String>> graph = new HashMap<>();
        for(int i = 0; i < tickets.size(); i++) {
            String src = tickets.get(i).get(0);
            String destination = tickets.get(i).get(1);
            
            graph.putIfAbsent(src, new LinkedList<>());
            graph.get(src).add(destination);
        }
        
        graph.keySet().forEach(node -> {
            Collections.sort(graph.get(node));
        });
        
        LinkedList<String> result = new LinkedList<>();
        
        dfs("JFK", result, graph);
        
        return result;
    }
    
    void dfs(String srcNode, LinkedList<String> result, HashMap<String, LinkedList<String>> graph) {
        
        if(graph.containsKey(srcNode)) {
            LinkedList<String> neighbour = graph.get(srcNode);
            while(neighbour.size() > 0) {
                String neigh = neighbour.pollFirst();
                dfs(neigh, result, graph);
            }
        }
        
        result.addFirst(srcNode);
    }
}