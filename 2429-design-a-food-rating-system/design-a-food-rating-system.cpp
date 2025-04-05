class FoodRatings {
public:

    typedef pair<int,string> pr;

    struct cmp {
        bool operator()(pr &a, pr &b) {
            if(a.first==b.first) return a.second>b.second;
            return a.first<b.first;
        }
    };

    unordered_map<string,priority_queue<pr,vector<pr>,cmp>> mp; //{cuisine,{rating,food}}
    unordered_map<string,int> mp2; //{food,rating}
    unordered_map<string,string> mp3; //{food,cuisine}

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
        for(int i=0;i<n;++i){
            mp[cuisines[i]].push({ratings[i],foods[i]});
            mp2[foods[i]]=ratings[i];
            mp3[foods[i]]=cuisines[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        mp2[food]=newRating;
        mp[mp3[food]].push({newRating,food});
    }
    
    string highestRated(string cuisine) {
        while(mp2[mp[cuisine].top().second]!=mp[cuisine].top().first) mp[cuisine].pop(); 
        return mp[cuisine].top().second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */