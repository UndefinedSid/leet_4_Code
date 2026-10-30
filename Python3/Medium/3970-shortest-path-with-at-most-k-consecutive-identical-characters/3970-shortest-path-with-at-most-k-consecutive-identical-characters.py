import heapq
from typing import List

class Solution:
    def shortestPath(self, n: int, edges: List[List[int]], labels: str, k: int) -> int:
        graph = [[] for _ in range(n)]
        for u, v, w in edges:
            graph[u].append((v, w))
            
        pq = [(0, 0, 1)]
        
        dist = {}
        
        while pq:
            d, u, count = heapq.heappop(pq)
            
            if u == n - 1:
                return d
                
            if dist.get((u, count), float('inf')) < d:
                continue
                
            for v, w in graph[u]:
                if labels[u] == labels[v]:
                    next_count = count + 1
                else:
                    next_count = 1
                    
                if next_count > k:
                    continue
                    
                next_dist = d + w
                if next_dist < dist.get((v, next_count), float('inf')):
                    dist[(v, next_count)] = next_dist
                    heapq.heappush(pq, (next_dist, v, next_count))
                    
        return -1