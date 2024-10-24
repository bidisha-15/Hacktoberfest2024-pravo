#include <iostream>
#include <stack>
#include <unordered_map>

bool isValid(const std::string& s) {
    std::stack<char> stk;
    std::unordered_map<char, char> mapping = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    for (char ch : s) {
        // If the character is a closing bracket
        if (mapping.find(ch) != mapping.end()) {
            // Pop the top element from the stack if it's not empty, else assign a dummy value
            char topElement = stk.empty() ? '#' : stk.top();
            // If the top element doesn't match the mapping, return false
            if (topElement != mapping[ch]) {
                return false;
            }
            stk.pop(); // Pop the matched opening bracket
        } else {
            // If it's an opening bracket, push it onto the stack
            stk.push(ch);
        }
    }

    // If the stack is empty, all opening brackets were matched
    return stk.empty();
}

int main() {
    std::string input;
    std::cout << "Enter a string of parentheses: ";
    std::cin >> input;

    if (isValid(input)) {
        std::cout << "The parentheses are valid." << std::endl;
    } else {
        std::cout << "The parentheses are not valid." << std::endl;
    }

    return 0;
}
