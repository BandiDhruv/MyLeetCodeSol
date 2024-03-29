class MedianFinder {
public:
    priority_queue<int> maxpq;
    priority_queue<int,vector<int>,greater<int>> minpq;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxpq.empty() || maxpq.top()>num)
            maxpq.push(num);
        else minpq.push(num);
        if(maxpq.size()>minpq.size()+1){
            minpq.push(maxpq.top());
            maxpq.pop();
        }
        else if(maxpq.size()+1<minpq.size()){
            maxpq.push(minpq.top());
            minpq.pop();
        }
    }
    
    double findMedian() {
        double ans=0;
        if(minpq.size()==maxpq.size()){
            if(!minpq.empty()) ans=(minpq.top()+maxpq.top())/2.0;
        }
        else{
            ans=(maxpq.size()>minpq.size())?maxpq.top():minpq.top();
        }
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */