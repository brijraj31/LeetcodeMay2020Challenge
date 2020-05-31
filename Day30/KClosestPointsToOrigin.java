// Problem Link : https://leetcode.com/explore/featured/card/may-leetcoding-challenge/538/week-5-may-29th-may-31st/3345/

// K Closest Points to Origin


/* We have a list of points on the plane.  Find the K closest points to the origin (0, 0).

(Here, the distance between two points on a plane is the Euclidean distance.)

You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)

 

Example 1:

Input: points = [[1,3],[-2,2]], K = 1
Output: [[-2,2]]
Explanation: 
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].
Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], K = 2
Output: [[3,3],[-2,4]]
(The answer [[-2,4],[3,3]] would also be accepted.)
 

Note:

1 <= K <= points.length <= 10000
-10000 < points[i][0] < 10000
-10000 < points[i][1] < 10000 */






class Solution {
    private class Pair<F, S> {
        private final F first; //first member of pair
        private final S second; //second member of pair

        Pair(F first, S second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }

            if (o == null || getClass() != o.getClass())
                return false;

            Pair<?, ?> pair = (Pair<?, ?>) o;
            if(!first.equals(pair.first))
                return false;
            return second.equals(pair.second);
        }

        @Override
        public int hashCode() {
            return 31 * first.hashCode() + second.hashCode();
        }

        @Override
        public String toString() {
            return "(" + first +", "+ second +")";
        }

        
        public F getFirst() {
            return first;
        }

        public S getSecond() {
            return second;
        }
    }
    class PairCompare implements Comparator<Pair<Integer, Integer>> {
        @Override
        public int compare(Pair<Integer, Integer> p1, Pair<Integer, Integer> p2) {
            
            double dist1 = Math.sqrt(Math.pow(p1.getSecond(), 2) + Math.pow(p1.getFirst(), 2));
            double dist2 = Math.sqrt(Math.pow(p2.getSecond(), 2) + Math.pow(p2.getFirst(), 2));
            return  Double.compare(dist2, dist1);
        }
    }
    public int[][] kClosest(int[][] points, int K) {
        PriorityQueue<Pair<Integer, Integer>> pq = new PriorityQueue<Pair<Integer, Integer>>(new PairCompare());
        
        for (int i = 0; i < Math.min(points.length, K); ++i) {
            pq.offer(new Pair<Integer, Integer>(points[i][0], points[i][1]));
        }
        
        for (int i = K; i < points.length; ++i) {
            Pair<Integer, Integer> p = new Pair<Integer, Integer>(points[i][0], points[i][1]);
            Pair<Integer, Integer> t = pq.peek();
            
            if (new PairCompare().compare(p, t) >= 0) {
                pq.poll();
                pq.offer(p);
            }
        }
        
        int[][] ans = new int[K][2];
        
        int i = 0;
        while (!pq.isEmpty()) {
            Pair<Integer, Integer> temp = pq.peek();
            
            ans[i][0] = temp.getFirst();
            ans[i ++][1] = temp.getSecond();
            pq.poll();
        }
        
        return ans;
    }
}