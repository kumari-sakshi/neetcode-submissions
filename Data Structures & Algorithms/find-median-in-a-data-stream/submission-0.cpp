class MedianFinder {
public:
  priority_queue<int> pq;
  priority_queue<int,vector<int> ,greater<int>> minpq;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
      pq.push(num);
      minpq.push(pq.top());
      pq.pop();

      if(minpq.size()>pq.size())
      {
        pq.push(minpq.top());
        minpq.pop();
      }  
    }
    
    double findMedian() {
        
        if(pq.size()==minpq.size())
        return (double)(pq.top()+minpq.top())/2.0;
        else
        return pq.top();
    }
};
