class Solution:
    def palindromePath(self, n: int, edges: list[list[int]], s: str, queries: list[str]) -> list[bool]:
        adjList = [[] for _ in range(n)]
        for u, v in edges:
            adjList[u].append(v)
            adjList[v].append(u)
            
        LOG = 17
        ancestorTable = [[-1] * n for _ in range(LOG)]
        nodeDepth = [0] * n
        tin = [0] * n
        tout = [0] * n
        dfsTimer = 0
        
        def dfs(node: int, parentNode: int):
            nonlocal dfsTimer
            tin[node] = dfsTimer
            dfsTimer += 1
            ancestorTable[0][node] = parentNode
            
            for neighbor in adjList[node]:
                if neighbor == parentNode:
                    continue
                nodeDepth[neighbor] = nodeDepth[node] + 1
                dfs(neighbor, node)
                
            tout[node] = dfsTimer - 1
            
        dfs(0, -1)
        
        for k in range(1, LOG):
            for i in range(n):
                p = ancestorTable[k - 1][i]
                if p != -1:
                    ancestorTable[k][i] = ancestorTable[k - 1][p]
                    
        def lca(u: int, v: int) -> int:
            if nodeDepth[u] < nodeDepth[v]:
                u, v = v, u
                
            diff = nodeDepth[u] - nodeDepth[v]
            for k in range(LOG):
                if diff & (1 << k):
                    u = ancestorTable[k][u]
                    
            if u == v:
                return u
                
            for k in reversed(range(LOG)):
                if ancestorTable[k][u] != ancestorTable[k][v]:
                    u = ancestorTable[k][u]
                    v = ancestorTable[k][v]
                    
            return ancestorTable[0][u]
            
        fenwickSize = n
        fenwickTree = [0] * (n + 1)
        
        def fenwickAdd(idx: int, val: int):
            idx += 1
            while idx <= fenwickSize:
                fenwickTree[idx] ^= val
                idx += idx & -idx
                
        def fenwickPrefix(idx: int) -> int:
            res = 0
            idx += 1
            while idx > 0:
                res ^= fenwickTree[idx]
                idx -= idx & -idx
            return res
            
        def charMask(c: str) -> int:
            return 1 << (ord(c) - ord('a'))
            
        labels = list(s)
        
        for u, c in enumerate(labels):
            mask = charMask(c)
            fenwickAdd(tin[u], mask)
            fenwickAdd(tout[u] + 1, mask)
            
        answers = []
        for q in queries:
            parts = q.split()
            if parts[0] == "update":
                u = int(parts[1])
                newChar = parts[2]
                delta = charMask(labels[u]) ^ charMask(newChar)
                labels[u] = newChar
                fenwickAdd(tin[u], delta)
                fenwickAdd(tout[u] + 1, delta)
            else:
                u, v = int(parts[1]), int(parts[2])
                w = lca(u, v)
                pathMask = fenwickPrefix(tin[u]) ^ fenwickPrefix(tin[v]) ^ charMask(labels[w])
                
                answers.append(pathMask == 0 or (pathMask & (pathMask - 1)) == 0)
                
        return answers