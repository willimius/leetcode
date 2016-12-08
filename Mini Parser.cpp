/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s.empty()) return NestedInteger();
        if (s[0] != '[') return NestedInteger(stoi(s));
        stack<NestedInteger> ns;
        for (size_t i = 0; i < s.size(); i++) {
            if (s[i] == '[') {
                ns.emplace(NestedInteger());
            }
            else if (s[i] == ']') {
                if (ns.size() <= 1) continue;
                auto nest = ns.top();
                ns.pop();
                ns.top().add(nest);
            }
            else if (s[i] == ',') continue;
            else {
                int num;
                if (s[i] == '-') num = -(s[++i] - '0');
                else num = (s[i] - '0');
                while (isdigit(s[++i])) 
                    num = num*10 + (num < 0 ? -(s[i]-'0') : s[i]-'0');
                ns.top().add(NestedInteger(num));
                i--;
            }
        }
        return ns.top();
    }
};