class Solution {
public:
    string reverseWords(string s) {

        int p = s.length() - 1;
        string answer = "";

        while (p >= 0) {

            while (p >= 0 && s[p] == ' ') {
                p--;
            }

            string temp;
            while (p >= 0 && s[p] != ' ') {
                temp.push_back(s[p]);
                p--;
            }

            reverse(temp.begin(), temp.end());

            answer += answer.empty() ? temp : " " + temp;
        }

        while (answer.back() == ' ') {
            answer.pop_back();
        }

        return answer;
    }
};