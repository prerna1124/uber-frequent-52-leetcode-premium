from typing import List
from collections import defaultdict

class ReconstructItinerary:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        graph = defaultdict(list)
        for ticket in tickets:
            src, dest = ticket
            graph[src].append(dest)
        
        for node in graph:
            graph[node].sort()
        
        result = []
        self.dfs("JFK", result, graph)
        
        return result
    
    def dfs(self, src_node: str, result: List[str], graph: dict):
        if src_node in graph:
            neighbours = graph[src_node]
            while neighbours:
                neigh = neighbours.pop(0)
                self.dfs(neigh, result, graph)
        
        result.insert(0, src_node)
