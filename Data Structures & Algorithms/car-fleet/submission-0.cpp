class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> car;
        int n=position.size();
        for(int i=0;i<n;i++){
            car.push_back({position[i],speed[i]});
        }
        sort(car.begin(),car.end());
        double lastTime=0;
        int fleets=0;
        for(int i=n-1;i>=0;i--){
            double time= (double)(target-car[i].first)/car[i].second;

            if(time>lastTime){
                fleets++;
                lastTime=time;
            }
        }
        return fleets;
    }
};
