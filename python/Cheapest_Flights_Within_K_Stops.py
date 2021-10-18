# Problem Description:- Cheapest_Flights_Within_K_Stops
# Link:- https://leetcode.com/problems/cheapest-flights-within-k-stops/


class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        flightsDict = defaultdict(list)
        
        for s, d, c in flights:
            flightsDict[s].append((d, c))
            
        queue = deque([(src, 0, -1)])
        visited = defaultdict(int)
        visited[src] = 0
        minCost = float('inf')
        
        while queue:
            city, cost, stops = queue.popleft()
            if city == dst:
                minCost = min(minCost, cost)
                continue
            
            for d, c in flightsDict[city]:
                if stops+1 <= k and (d not in visited or visited[d] > cost+c):
                    queue.append((d, cost+c, stops+1))
                    visited[d] = cost + c
                
        return minCost if minCost != float('inf') else -1
