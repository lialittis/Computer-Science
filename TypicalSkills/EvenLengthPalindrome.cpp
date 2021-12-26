/* All Even Length Palindrome are Divisible by 11 */

// Intuition
// Write some example, you find all even length palindromes are divisible by 11.
// So we need to search only palindrome with odd length.

// We can prove as follow:
// 11 % 11 = 0
// 1111 % 11 = 0
// 111111 % 11 = 0
// 11111111 % 11 = 0

// So:
// 1001 % 11 = (1111 - 11 * 10) % 11 = 0
// 100001 % 11 = (111111 - 1111 * 10) % 11 = 0
// 10000001 % 11 = (11111111 - 111111 * 10) % 11 = 0

// For any palindrome with even length:
// abcddcba % 11
// = (a * 10000001 + b * 100001 * 10 + c * 1001 * 100 + d * 11 * 1000) % 11
// = 0

// All palindrome with even length is multiple of 11.
// So among them, 11 is the only one prime
// if (8 <= N <= 11) return 11

// For other cases, we consider only palindrome with odd dights.


// More Generally
// Explanation from @chuan-chih:
// A number is divisible by 11 if sum(even digits) - sum(odd digits) is divisible by 11.
// Base case: 0
// Inductive step:
// If there is no carry when we add 11 to a number, both sums +1.
// Whenever carry happens, one sum -10 and the other +1.
// The invariant holds in both cases.


// Time Complexity
// O(10000) to check all numbers 1 - 10000.
// isPrime function is O(sqrt(x)) in worst case.
// But only sqrt(N) worst cases for 1 <= x <= N
// In general it's O(logx)



#include <string>

using namespace std;

int primePalindrome(int N) {
    if (8 <= N && N <= 11) return 11;
    for (int x = 1; x < 100000; ++x) {
        string s = to_string(x), r(s.rbegin(), s.rend());
        int y = stoi(s + r.substr(1));
        if (y >= N && isPrime(y)) return y;
    }
    return -1;
}

bool isPrime(int num) {
    if (num < 2 || num % 2 == 0) return num == 2;
    for (int i = 3; i * i <= num; i += 2)
        if (num % i == 0) return false;
    return true;
}