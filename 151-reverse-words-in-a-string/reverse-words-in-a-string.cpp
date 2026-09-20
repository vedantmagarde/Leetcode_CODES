class Solution {
public:
    string reverseWords(string s) {

        int p = s.length() - 1;
        string answer = "";
        
        while (p >= 0) {
            while (p >= 0 && s[p] == ' ') {
                p--;
            }
            int end = p;
            while (p >= 0 && s[p] != ' ') {
                p--;
            }

            if (!answer.empty()) {
                answer += " ";
            }
            answer += s.substr(p + 1, end - p);
        }
        while (answer.back() == ' ') {
            answer.pop_back();
        }

        return answer;
    }
};