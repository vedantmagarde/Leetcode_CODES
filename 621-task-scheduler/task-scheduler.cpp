class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char, int> mp; // char , freq
        int size = tasks.size();
        for (int i = 0; i < size; i++) {
            mp[tasks[i]]++;
        }

        priority_queue<int> pq; // freq , ava_cycle , char
        stack<int> st;

        int cycle = 0;
        for (auto x : mp) {
            pq.push(x.second);
        }

        while (!pq.empty()) {
            int task_comp = 0;

            for (int i = 1; !pq.empty() &&i <= n + 1; i++) {
                int freq = pq.top();
                pq.pop();

                if (freq - 1 > 0)
                    st.push(freq - 1);

                task_comp++;
            }

            while(!st.empty()){
                pq.push(st.top());
                st.pop();
            }

            cycle += pq.empty() ? task_comp : n + 1;
        }

        return cycle;
    }
};