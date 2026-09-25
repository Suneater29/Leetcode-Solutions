#include <string>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
    // Helper to compute Cartesian product (Concatenation) of two sets
    set<string> concatenate(const set<string>& set1, const set<string>& set2) {
        set<string> result;
        for (const string& s1 : set1) {
            for (const string& s2 : set2) {
                result.insert(s1 + s2);
            }
        }
        return result;
    }

    // Helper to compute Union of two sets
    set<string> setUnion(const set<string>& set1, const set<string>& set2) {
        set<string> result = set1;
        result.insert(set2.begin(), set2.end());
        return result;
    }

public:
    vector<string> braceExpansionII(string expression) {
        stack<set<string>> operandStack;
        stack<char> operatorStack;
        
        int n = expression.length();
        
        for (int i = 0; i < n; ++i) {
            char ch = expression[i];
            
            if (isalpha(ch)) {
                // Parse consecutive letters into a single string
                string word = "";
                while (i < n && isalpha(expression[i])) {
                    word += expression[i];
                    i++;
                }
                i--; // Step back to balance loop increment
                
                // If the previous character forms a sequence like 'a{...' or 'a b', apply concatenation
                if (i - (int)word.length() >= 0) {
                    char prev = expression[i - word.length()];
                    if (isalpha(prev) || prev == '}') {
                        operatorStack.push('*'); // '*' denotes concatenation
                    }
                }
                
                operandStack.push({word});
            } 
            else if (ch == '{') {
                if (i > 0) {
                    char prev = expression[i - 1];
                    if (isalpha(prev) || prev == '}') {
                        operatorStack.push('*'); // Implicit concatenation before '{'
                    }
                }
                operatorStack.push('{');
            } 
            else if (ch == ',') {
                // Process higher precedence operators (concatenation) before union
                while (!operatorStack.empty() && operatorStack.top() == '*') {
                    operatorStack.pop();
                    set<string> right = operandStack.top(); operandStack.pop();
                    set<string> left = operandStack.top(); operandStack.pop();
                    operandStack.push(concatenate(left, right));
                }
                operatorStack.push(',');
            } 
            else if (ch == '}') {
                // Evaluate inside braces
                while (!operatorStack.empty() && operatorStack.top() != '{') {
                    char op = operatorStack.top();
                    operatorStack.pop();
                    
                    set<string> right = operandStack.top(); operandStack.pop();
                    set<string> left = operandStack.top(); operandStack.pop();
                    
                    if (op == '*') {
                        operandStack.push(concatenate(left, right));
                    } else if (op == ',') {
                        operandStack.push(setUnion(left, right));
                    }
                }
                operatorStack.pop(); // Remove matching '{'
            }
        }
        
        // Evaluate any remaining operators in stack
        while (!operatorStack.empty()) {
            char op = operatorStack.top();
            operatorStack.pop();
            
            set<string> right = operandStack.top(); operandStack.pop();
            set<string> left = operandStack.top(); operandStack.pop();
            
            if (op == '*') {
                operandStack.push(concatenate(left, right));
            } else if (op == ',') {
                operandStack.push(setUnion(left, right));
            }
        }
        
        // Result is in lexicographical sorted order due to std::set
        set<string> resultSet = operandStack.top();
        return vector<string>(resultSet.begin(), resultSet.end());
    }
};