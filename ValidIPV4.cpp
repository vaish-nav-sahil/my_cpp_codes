// Write a program to check whether a given string is a valid IPv4 address or not.

// Example 1

// Input: "192.168.1.1"
// Output: Valid

// Example 2

// Input: "256.100.1.1"
// Output: Invalid


//valid -> 192.168.1.1
// 0.0.0.0
// 255.255.255.255

// Invalid -> 256.1.1.1      -> number > 255
// 192.168.01.1   -> leading zero
// 192..1.1       -> empty part
// abc.1.1.1      -> non-digit character


#include<bits/stdc++.h>
using namespace std;

class Solution {
public : 
    bool isValid(string ip){
        int dots =0;
        for (char ch : ip){
            if (ch == '.') dots++; //counting dots
        }

        if (dots != 3) return false; //dots should be 3

        stringstream ss(ip); //choping input into pieces
        string part ;

        while(getline(ss,part,'.')){
            if (part.size() == 0) return false;  //empty digit 
            if (part.size()>1 && part[0]=='0') return false; //leading zeroes 
            for (char ch : part){
                if (!isdigit(ch)){  //not - digit
                    return false;   
                }
            }
            int num = stoi(part);

            if (num<0 || num>255) return false;  //0 - 255        i.e 256 
        }
        return true;
    }
};
int main(){
    Solution obj;

    string ip;
    cin >> ip;

    bool result = obj.isValid(ip);

    cout << (result ? "Valid IPv4" : "Invalid IPv4");


    return 0;
}
