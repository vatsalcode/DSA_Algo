## all all points --> hash set
## check for all points 

class Solution:
    def minAreaRect(self, points: List[List[int]]) -> int:
        point_set=set()
        min_area=float('inf')

        # add all points to set==> O(1)
        for p in points:
            point_set.add((p[0], p[1]))
        #set {(1,1)}
        # going throwwww each pair of points
        for i in range(len(points)):
            for j in range(i+1, len(points)):
                x1,y1=points[i]
                x2,y2=points[j]
                # pair (1,1) and (1,3)skip
                #pair(1,1)(3,1)y1=y2 skip
                #pair (1,1)(3,3)--->(1,3)(3,1)-->set
                # area= abs(3-1)* abs(3-1)= 2*2=4
                #pair(1,1)(2,2)--set-->(1,2)(2,1)skip
                
                # check if the can from a diog of a rec
                if x1!=x2 and y1!=y2:
                    if(x1,y2) in point_set and (x2,y1) in point_set:
                        area=abs(x2-x1)*abs(y2-y1)
                        min_area=min(min_area,area)

        return 0 if min_area==float('inf')else min_area