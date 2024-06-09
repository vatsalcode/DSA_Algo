import heapq

# times = [[2,1,1],[2,3,1],[3,4,2]], n = 4, k = 2

# 1-  graph
# node 2 --> node 1 with w=1
# node 2 --> node 3 with w=1
# node 3--> node 3 with w=1
# dist{0, inf ,inf inf, inf.....}
# node 2, dist 0
# uupdt the node 1 and node3  to 1 ( 0+1=1)
# node 1 & node 3 are next proc with dis of 1
# node 3 upd node 3 with dis 2 (1+2)=3
# (

class Solution(object):
    def networkDelayTime(self, times, n, k):
        graph={i: [] for i in range(1,n+1)}
        for u,v,w in times:
            graph[u].append((v,w)) # add directed edge u-> v with weight w

        dist={node: float('inf') for node in range(1,n+1)}
        dist[k]=0

        heap=[(0,k)] #(dis, node)
        while heap:
            curr_dist,u= heapq.heappop(heap)

            if curr_dist>dist[u]: # skip if we found a shoter path alrerady
                continue

            for v, time in graph[u]:
                new_dist= curr_dist+time
                if new_dist<dist[v]: ## if better path
                    dist[v]=new_dist ## update the shoretstes dis to v 
                    heapq.heappush(heap,(new_dist,v))

        ## res= max of all the short path to all node
        max_D=max(dist.values())
        return max_D if max_D!= float('inf')else -1


            
       