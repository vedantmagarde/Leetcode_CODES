class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int siz;
    KthLargest(int k, vector<int>& nums) {
         siz = k;
        for (int i = 0; i < nums.size(); i++) {
            if (minHeap.size() < siz) {
                minHeap.push(nums[i]);
            } else {
                if (nums[i] > minHeap.top()) {
                    minHeap.push(nums[i]);
                    minHeap.pop();
                }
            }
        }
    }

    int add(int val) {
        if(minHeap.size()<siz){
            minHeap.push(val);
            return minHeap.top();
        }
        if (val > minHeap.top()) {
            minHeap.push(val);
            minHeap.pop();
        }
        return minHeap.top();
    }
};