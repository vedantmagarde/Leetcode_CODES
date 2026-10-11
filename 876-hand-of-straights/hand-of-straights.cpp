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

            int temp = x.first;

            while (mp[temp] > 0) {

                for (int i = 0; i < groupSize; i++) {
                    int ele = temp + i;

                    if (mp[ele] == 0)
                        return false;
                    mp[ele]--;
                }
            }
        }
        return true;
    }
};