class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char, int> mp; // char , freq
        int size = tasks.size();
        for (int i = 0; i < size; i++) {
            mp[tasks[i]]++;
        }

        priority_queue<int> pq; // freq , ava_cycle , char

        int time = 0;
        for (auto x : mp) {
            pq.push(x.second);
        }

        while (!pq.empty()) {
            vector<int> temp;

            for (int i = 1; !pq.empty() && i <= n + 1; i++) {
                int freq = pq.top();
                pq.pop();
                freq--;

                temp.push_back(freq);
            }

            for (auto x : temp)
                if (x > 0)
                    pq.push(x);

            time += pq.empty() ? temp.size() : n + 1;
        }

        return time;
    }
};