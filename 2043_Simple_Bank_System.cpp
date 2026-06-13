// 2043. Simple Bank System
// link -> https://leetcode.com/problems/simple-bank-system/

// t.c -> O(1);
// s.c -> O(n);

#include<bits/stdc++.h>
using namespace std;

class Bank {
public:
    vector<long long >balance;                      //initialized a balance array
    int n;
    Bank(vector<long long>& balance) {              //this is a constructor called only once whenever Bank object is created [O(n)]
        n = balance.size();
        this->balance  = balance ;                  //copying the input balance array 
    }
    
    bool transfer(int account1, int account2, long long money) {           //O(1)
        if (account1 >n || account2 >n || balance[account1-1] < money){     //valid condition checks
            return false;
        }
        balance[account1-1]-=money;                  //money debited from account1 
        balance[account2-1]+=money;                  //money credited to  account2
        return true;
    }
    
    bool deposit(int account, long long money) {              //O(1)
        if (account <1 || account>n) return false;             //valid condition checks
        else {
            balance[account-1]+= money;                       //money credited to account
            return true;
        } 
    }
    
    bool withdraw(int account, long long money) {            //O(1)
        if (account <1 || account>n || balance[account-1] <money) return false;        //valid condition checks
        else {
            balance[account-1]-= money;                    //money debited from account
            return true;
        } 
    }



    void displayBalances() {         
        cout << "\nCurrent Balances:\n";
        for (int i = 0; i < n; i++) {
            cout << "Account " << i + 1
                 << " : " << balance[i] << endl;
        }
    }
};


//More data secured way -> 
// class Bank {
// private:
//     vector<long long> balance;
//     int n;

//     bool valid(int account) {
//         return account > 0 && account <= n;
//     }

// public:
//     Bank(vector<long long>& balance) {
//         this -> balance = balance;
//         n = balance.size();
//     }

//     bool transfer(int account1, int account2, long long money) {
//         if (!valid(account1) || !valid(account2) || balance[account1 - 1] < money) return false;
//         balance[account1 - 1] -= money;
//         balance[account2 - 1] += money;
//         return true;
//     }

//     bool deposit(int account, long long money) {
//         if (!valid(account)) return false;
//         balance[account - 1] += money;
//         return true;
//     }

//     bool withdraw(int acc, long long amt) {
//         if (!valid(acc) || balance[acc - 1] < amt) return false;
//         balance[acc - 1] -= amt;
//         return true;
//     }
//     
// };



/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */

int main(){
    int n;
    cout << "Enter number of accounts: ";
    cin >> n;

    vector<long long> balances(n);

    cout << "Enter initial balances:\n";
    for (int i = 0; i < n; i++) {
        cin >> balances[i];
    }

    Bank bank(balances);

    int choice;

    do {
        cout << "\n===== BANK MENU =====\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Transfer\n";
        cout << "4. Display Balances\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int acc;
            long long amt;

            cout << "Enter account number: ";
            cin >> acc;

            cout << "Enter amount: ";
            cin >> amt;

            if (bank.deposit(acc, amt))
                cout << "Deposit Successful\n";
            else
                cout << "Deposit Failed\n";
        }

        else if (choice == 2) {
            int acc;
            long long amt;

            cout << "Enter account number: ";
            cin >> acc;

            cout << "Enter amount: ";
            cin >> amt;

            if (bank.withdraw(acc, amt))
                cout << "Withdrawal Successful\n";
            else
                cout << "Withdrawal Failed\n";
        }

        else if (choice == 3) {
            int acc1, acc2;
            long long amt;

            cout << "From Account: ";
            cin >> acc1;

            cout << "To Account: ";
            cin >> acc2;

            cout << "Amount: ";
            cin >> amt;

            if (bank.transfer(acc1, acc2, amt))
                cout << "Transfer Successful\n";
            else
                cout << "Transfer Failed\n";
        }

        else if (choice == 4) {
            bank.displayBalances();
        }

    } while (choice != 5);

    cout << "\nThank You!\n";
    return 0;
}
