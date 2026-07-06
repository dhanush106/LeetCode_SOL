# Last updated: 7/6/2026, 12:00:23 PM
from typing import List
from collections import defaultdict
from sortedcontainers import SortedSet  # pip install sortedcontainers

class DSU:
    def __init__(self, size):
        self.parent = list(range(size + 1))

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])  # path compression
        return self.parent[x]

    def union(self, x, y):
        xr, yr = self.find(x), self.find(y)
        if xr != yr:
            self.parent[yr] = xr  # union

class Solution:
    def processQueries(self, c: int, connections: List[List[int]], queries: List[List[int]]) -> List[int]:
        dsu = DSU(c)
        online = [True] * (c + 1)  # 1-based indexing

        # Step 1: Union all connected stations
        for u, v in connections:
            dsu.union(u, v)

        # Step 2: Build a mapping from component root to sorted set of online stations
        component_online = defaultdict(SortedSet)
        for i in range(1, c + 1):
            root = dsu.find(i)
            component_online[root].add(i)

        res = []
        for qtype, x in queries:
            root = dsu.find(x)

            if qtype == 1:
                if online[x]:
                    res.append(x)
                else:
                    online_set = component_online[root]
                    if online_set:
                        res.append(online_set[0])  # min id in component
                    else:
                        res.append(-1)
            elif qtype == 2:
                if online[x]:
                    online[x] = False
                    component_online[root].discard(x)

        return res
