// 1189. Maximum Number of Balloons
// link -> https://leetcode.com/problems/maximum-number-of-balloons/description/?envType=daily-question&envId=2026-06-22

#include<bits/stdc++.h>
using namespace std;

// t.c -> O(n^2)
// s.c -> O(1)

// Approach->
// 1.We try to form the word "balloon" again and again from the given string.
// 2.For each attempt, we search every required character one by one and mark it as used.
// 3.If at any point a required character is missing, we stop.
// 4.It’s straightforward but inefficient because we repeatedly scan the string.

// class Solution {
// public:
//     int maxNumberOfBalloons(string text) {
//         int ans = 0;

//         while (true) {
//             string word = "balloon";

//             for (char &c : word) {
//                 bool found = false;

//                 for (char &ch : text) {
//                     if (ch == c) {
//                         ch = '#';
//                         found = true;
//                         break;
//                     }
//                 }

//                 if (!found) return ans;
//             }

//             ans++;
//         }
//     }
// };

// t.c -> O(n)
// s.c -> O(1)

// Approach -> 
// 1.keep tracking no of desired elements in variable 
// 2.return minimum of desired character.

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b = 0, a = 0, l = 0, o = 0, n = 0;

        for (char c : text) {
            if (c == 'b') b++;
            else if (c == 'a') a++;
            else if (c == 'l') l++;
            else if (c == 'o') o++;
            else if (c == 'n') n++;
        }

        return min({b, a, l / 2, o / 2, n});
    }
};

// t.c -> O(n)
// s.c -> O(1)

//Approach 
// 1.Mark freq of each word in hash array of 26 size
// 2.Return minimun freq out of all desired characters b,a,l/2,o/2,n

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> count(26, 0);

        for (char c : text) {
            count[c - 'a']++;
        }

        return min({count['b' - 'a'],count['a' - 'a'],count['l' - 'a'] / 2,count['o' - 'a'] / 2,count['n' - 'a']});
    }
};

int main(){
    string text;
    cin>>text;

    Solution obj;
    cout<<obj.maxNumberOfBalloons(text);
    return 0;
}
