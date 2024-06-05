// class UndergroundSystem {
// public:
//     unordered_map<string,vector<pair<int,int>>> mp1,mp2;
//     UndergroundSystem() {
        
//     }
    
//     void checkIn(int id, string sn, int t) {    
//         mp1[sn].push_back({id,t});
//     }
    
//     void checkOut(int id, string sn, int t) {
//         mp2[sn].push_back({id,t});
//     }
    
//     double getAverageTime(string ss, string es) {
//         double cnt=0.0;
//         vector<pair<int,int>> a1,a2;
//         for(auto it:mp1[ss]){
//             a1.push_back(it);
//         }
//         for(auto it:mp2[es]){
//             a2.push_back(it);
//         }
//         sort(a1.begin(),a1.end());
//         sort(a2.begin(),a2.end());
//         int i=0,j=0;
//         double dist=0.0;
//         while(i<a1.size() && j<a2.size()){
//             if(a1[i].first==a2[j].first){
//                 dist+=(double)((double)a2[j].second-(double)a1[i].second);
//                 cnt+=1.0;
//                 i++;j++;
//             }
//             else if(a1[i].first<a2[j].first)i++;
//             else j++;
//         }
//         return dist/cnt;
//     }
// };

// /**
//  * Your UndergroundSystem object will be instantiated and called as such:
//  * UndergroundSystem* obj = new UndergroundSystem();
//  * obj->checkIn(id,stationName,t);
//  * obj->checkOut(id,stationName,t);
//  * double param_3 = obj->getAverageTime(startStation,endStation);
//  */
class UndergroundSystem {
public:
    // Maps to store check-in information and travel times.
    unordered_map<int, pair<string, int>> checkInMap; // Maps ID to {stationName, time}
    unordered_map<string, pair<long long, int>> travelTimeMap; // Maps "startStation->endStation" to {totalTime, count}

    UndergroundSystem() {}

    void checkIn(int id, string stationName, int t) {
        checkInMap[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        auto checkInInfo = checkInMap[id];
        string startStation = checkInInfo.first;
        int startTime = checkInInfo.second;
        
        // Create the key for the travel time map
        string routeKey = startStation + "->" + stationName;
        
        // Calculate the travel time for this trip
        int travelTime = t - startTime;
        
        // Update the travel time map
        travelTimeMap[routeKey].first += travelTime;
        travelTimeMap[routeKey].second += 1;
        
        // Remove the check-in information as it's no longer needed
        checkInMap.erase(id);
    }

    double getAverageTime(string startStation, string endStation) {
        string routeKey = startStation + "->" + endStation;
        auto travelInfo = travelTimeMap[routeKey];
        
        // Calculate and return the average travel time
        return (double)travelInfo.first / travelInfo.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
