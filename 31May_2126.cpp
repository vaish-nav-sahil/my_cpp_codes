class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long massi=mass;
        sort(asteroids.begin(),asteroids.end());
        for(auto it : asteroids){
            if (massi>=it){
                massi+=it;
            }
            else  return false; 
        }
        
        return true;
    }
};
