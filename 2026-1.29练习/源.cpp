
class Solution {
public:
    bool isValid(string s) {
        stack<char> parsed;
        for (char ch : s) {
            if (ch == '{' || ch == '[' || ch == '(') {
                parsed.push(ch);
            }
            else {
                if (parsed.empty()) {
                    return false;
                }
                char c = parsed.top();
                if ((ch == '}' && c == '{') ||
                    (ch == ']' && c == '[') ||
                    (ch == ')' && c == '(')) {
                    parsed.pop();
                }
                else {
                    return false;
                }
            }
        }
        return parsed.empty();
    }
};