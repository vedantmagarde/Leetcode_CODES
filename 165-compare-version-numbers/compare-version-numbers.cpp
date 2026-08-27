class Solution {
public:
    int compareVersion(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        int itr1 = 0, itr2 = 0;
        while (itr1 < n1 || itr2 < n2) {
            int sum1 = 0;
            while (itr1 < n1 && s1[itr1] != '.') {
                sum1 = (sum1 * 10) + (s1[itr1] - '0');
                itr1++;
            }
            int sum2 = 0;
            while (itr2 < n2 && s2[itr2] != '.') {
                sum2 = (sum2 * 10) + (s2[itr2] - '0');
                itr2++;
            }
            if (sum1 > sum2)
                return 1;
            if (sum1 < sum2)
                return -1;
            sum1 = 0;
            sum2 = 0;
            itr1++;
            itr2++;
        }

        return 0;
    }
};