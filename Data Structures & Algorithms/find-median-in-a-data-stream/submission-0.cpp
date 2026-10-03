class MedianFinder {
public:
    priority_queue<int>pq;
    priority_queue<int,vector<int>,greater<int>>hq;
    MedianFinder() {
    }
    
    void addNum(int num) {
        pq.push(num);
        if(pq.size()==(hq.size()+2)){
            auto it = pq.top();pq.pop();
            hq.push(it);
        }
       
       if(!pq.empty() && !hq.empty() && pq.top()>hq.top()){
          auto e1 = pq.top();pq.pop();
          auto e2 = hq.top();hq.pop();
          pq.push(e2);
          hq.push(e1);
       }

    }
    
    double findMedian() {
        if(pq.size()==hq.size()+1){
            return (double)pq.top();
        }
        return (pq.top() + hq.top()) / 2.0;;
    }
};
