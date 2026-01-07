// 9. Palindrome Number
// Easy
// Given an integer x, return true if x is a palindrome, and false otherwise.
// Constraints: -2^31 <= x <= 2^31 - 1

// Solution 1: Reverse Half
// Time Complexity: O(log_{10}(x))
// Space Complexity: O(1)
// This is the optimal solution.
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;
        int reverseHalf = 0;
        while(x > reverseHalf){
            reverseHalf = reverseHalf * 10 + x % 10;
            x /= 10;
        }
        return x == reverseHalf || x == reverseHalf / 10;
    }
};

// Solution 2: Using Stack
// Time Complexity: O(log_{10}(x))
// Space Complexity: O(log_{10}(x))
// This solution uses extra space for the stack and is less optimal than Solution 1.
class Stack {
    private:
        int arr[11];
        int topIndex;
    public:
    Stack(){
        topIndex = -1;
    }
    void push(int x){
        topIndex++;
        arr[topIndex] = x;
    }
    void pop(){
        topIndex--;
    }
    int top(){
        return arr[topIndex];
    }
    bool empty(){
        return topIndex == -1;
    }
};

class SolutionStack {
public:
    bool isPalindrome(int x) {
      if(x < 0) return false;
      Stack st;
      int temp = x;
      while(temp > 0){
        st.push(temp % 10);
        temp /= 10;
      }
      temp = x;
      while(temp > 0){
        int digit = temp % 10;
        if(st.top() != digit) return false;
        st.pop();
        temp /= 10;
      }
      return st.empty();
    }
};
