class FoodRatings {
public:
    struct cmp{
        bool operator()(pair<int,string>l,pair<int,string> r){
            if(l.first!=r.first)
                return l.first<r.first;
            return l.second>r.second;
        }
    };

    unordered_map<string,pair<int,string>> mp1;
    unordered_map<string,priority_queue<pair<int,string>,vector<pair<int,string>>,cmp>>mp2;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
            mp1[foods[i]]={ratings[i],cuisines[i]};
            mp2[cuisines[i]].push({ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        mp1[food].first=newRating;
        string cuisine=mp1[food].second;
        mp2[cuisine].push({newRating,food});
    }
    
    string highestRated(string cuisine) {
        pair<int,string> highestRated = mp2[cuisine].top();
        while(mp2[cuisine].top().first!=mp1[highestRated.second].first) {
            mp2[cuisine].pop();
            highestRated = mp2[cuisine].top();
        }
        return highestRated.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */