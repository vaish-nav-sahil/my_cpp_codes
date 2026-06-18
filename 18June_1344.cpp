// 1344. Angle Between Hands of a Clock
// link -> https://leetcode.com/problems/angle-between-hands-of-a-clock/description/?envType=daily-question&envId=2026-06-18

//Approach->
// The minute hand moves 6° per minute and the hour hand moves 30° per hour along with an additional 0.5° per minute. We can calculate the exact position of both hands, find the absolute difference between their angles, and return the smaller angle formed between them.

// T.c -> O(1);
// S.c -> O(1);

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minuteAngle = minutes*6.0;
        double hourAngle = (hour*30.0) + 0.5*minutes;

        double diff = abs(minuteAngle - hourAngle);

        return min(diff,360 - diff);
    }
};

int main(){
    int hour ;
    cin>>hour;
    int minutes;
    cin>>minutes;
    Solution obj;
    cout<<obj.angleClock(hour,minutes);
    return 0;
}
