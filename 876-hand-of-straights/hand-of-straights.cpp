class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        int n = hand.size();
        if (n % groupSize != 0)
            return false;
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[hand[i]]++;
        }

        for (auto x : mp) {

            int ele = x.first;
            while (mp[ele] > 0) {
                for (int i = 0; i < groupSize; i++) {
                    int temp = ele + i;

                    if (mp[temp] == 0)
                        return false;

                    mp[temp]--;
                }
            }
        }
        return true;
    }
};