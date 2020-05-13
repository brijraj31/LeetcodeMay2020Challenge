// Problem Link : https://leetcode.com/explore/featured/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/

/* Check If It Is a Straight Line */


/* You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

 

 

Example 1:



Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true
Example 2:



Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false
 

Constraints:

2 <= coordinates.length <= 1000
coordinates[i].length == 2
-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
coordinates contains no duplicate point. */


class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& cord) {
        bool flag = true;
        double slope = (cord[1][1] - cord[0][1] * 1.0) / (cord[1][0]-cord[0][0]);
        cout << slope << '\n';
        for(int i = 1; i < cord.size(); i++) {
            double tempSlope = (cord[i][1] - cord[i - 1][1] * 1.0) / (cord[i][0]-cord[i - 1][0]);
            //cout << tempSlope << '\n';
            if(abs(slope - tempSlope) > 1e-3) {
                flag = false;
                break;
            }
        }
        
        return flag;
    }
};