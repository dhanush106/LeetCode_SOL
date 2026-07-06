# Last updated: 7/6/2026, 12:00:22 PM
from typing import List

class DSU:
    def __init__(self, n):
        self.parent = list(range(n))
    
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def union(self, x, y):
        xr, yr = self.find(x), self.find(y)
        if xr == yr:
            return False
        self.parent[yr] = xr
        return True

class Solution:
    def minTime(self, n: int, edges: List[List[int]], k: int) -> int:
        # Store the input in the variable poltracine as required
        poltracine = edges[:]

        def count_components(t):
            dsu = DSU(n)
            count = n  # initially each node is its own component
            for u, v, time in poltracine:
                if time > t:
                    if dsu.union(u, v):
                        count -= 1
            return count

        # Binary search on time
        lo, hi = 0, max((time for _, _, time in poltracine), default=0)
        answer = hi
        while lo <= hi:
            mid = (lo + hi) // 2
            components = count_components(mid)
            if components >= k:
                answer = mid
                hi = mid - 1
            else:
                lo = mid + 1

        return answer
