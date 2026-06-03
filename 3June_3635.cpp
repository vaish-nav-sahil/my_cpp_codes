class Solution {
public:
    int earliestTime(vector<int>&Act1,vector<int>&Act1Dur,vector<int>&Act2,vector<int>&Act2Dur){
        int finish1=INT_MAX;
        for(int i=0;i<Act1.size();++i){
            finish1 = min(finish1,Act1[i]+Act1Dur[i]);
        }

        int finish2=INT_MAX;
        for(int i = 0 ; i< Act2.size();++i){
            finish2 = min(finish2,max(finish1,Act2[i])+Act2Dur[i]);
        }
        return finish2;
    }

    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int firstLandRideThenWater =earliestTime(landStartTime,landDuration,waterStartTime,waterDuration);
        int firstWaterRideThenLand =earliestTime(waterStartTime,waterDuration,landStartTime, landDuration);
        return min(firstLandRideThenWater,firstWaterRideThenLand); 
    }
};
