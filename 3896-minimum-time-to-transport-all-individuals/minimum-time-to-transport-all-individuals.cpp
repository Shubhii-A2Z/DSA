class Solution {
public:

    typedef tuple<double,int,int,int> state;

    double minTime(int n, int k, int m, vector<int>& time, vector<double>& mul) {
        int totalMask=(1<<n)-1;

        // dist[mask][stage][pos]: minimum time to reach dest
        vector<vector<vector<double>>> dist(totalMask+1,vector<vector<double>>(m,vector<double>(2,1e18)));

        priority_queue<state,vector<state>,greater<state>> pq; // {totalTime,mask,stage,boatPos}

        // starting from boat at base camp, no people crossed, stage 0, time 0
        dist[0][0][0]=0.0;
        pq.push({0.0,0,0,0});

        while(pq.size()){
            auto [currTime,currMask,currStage,currPos]=pq.top(); pq.pop();

            if(currTime>dist[currMask][currStage][currPos]) continue;

            // all people crossed and boat is at destination
            if(currMask==totalMask && currPos==1) return round(currTime*1e5)/1e5;

            if(currPos==0){ // boat is on leftSide, form grps of atmost k people to cross
                vector<int> waiting;

                for(int i=0;i<n;++i){ // checking if i'th person is still waiting for not
                    if(!(currMask&(1<<i))) waiting.push_back(i);
                }

                // out of all waiting people, we can make subsets of who can cross, without exceeding k
                for(int mask=1;mask<(1<<waiting.size());++mask){
                    if(__builtin_popcount(mask)>k) continue; // we cant choose more than k

                    double maxTime=0.0;
                    int newMask=currMask;
                    for(int i=0;i<waiting.size();++i){
                        if(mask&(1<<i)){ // ith person has been selected to cross
                            maxTime=max(maxTime,double(time[waiting[i]]));
                            newMask|=(1<<waiting[i]);
                        }
                    }

                    double tripTime=maxTime*mul[currStage]; // time taken to go to rightSide
                    int newStage=(currStage+(int)floor(tripTime))%m;
                    
                    double totalTime=currTime+tripTime;
                    if(totalTime<dist[newMask][newStage][1]){
                        dist[newMask][newStage][1]=totalTime;
                        pq.push({totalTime,newMask,newStage,1});
                    }
                }
            }
            else{ // boat is on right side, "one" person should return to left side
                for(int i=0;i<n;++i){
                    if(currMask&(1<<i)){ // this person is on right side, hence it should return to left side
                        int newMask=currMask^(1<<i);

                        double returnTime=time[i]*mul[currStage];
                        int newStage=(currStage+(int)floor(returnTime))%m;

                        double totalTime=currTime+returnTime;
                        if(totalTime<dist[newMask][newStage][0]){
                            dist[newMask][newStage][0]=totalTime;
                            pq.push({totalTime,newMask,newStage,0});
                        }
                    }
                }
            }
        }

        return -1.00;
    }
};