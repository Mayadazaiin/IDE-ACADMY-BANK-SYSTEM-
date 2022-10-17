#include <iostream>
#include<string>
using namespace std;
class account {
private:
    int account_number;
    char name[100];
    float balance;
public:
    void OpenMyAccount() {
        cout << "Please, enter your account number:";
        cin >> account_number;
        cout << "Please, enter your name:";
        cin >> name;
        cout << "Please, enter your balance:";
        cin >> balance;
    }
    void ShowMyAccount() {
        cout << "Account number:" << account_number << endl;
        cout << "The name:" << name << endl;
        cout << "The balance:" << balance << endl;
    }
    void Deposite() {
        float amount;
        cout << "Please, enter the amount do you want to deposite:";
        cin >> amount;
        balance += amount;
    }
    void withdraw() {
        float amount;
        cout << "Please, enter the amount do you want to withdraw:";
        cin >> amount;
        if (amount <= balance)
            balance -= amount;
        else
            cout << "Your balance is not enough!" << endl;
    }

    int account :: Search(int a)
    {
        if (account_number == a) {
            ShowMyAccount();
            return (1);
        }
        return (0);
    }

    // main code
    int main()
    {
        account C[3];

        int found = 0, a, ch, i;
        for (i = 0; i <= 2; i++) {
            C[i].OpenMyAccount();
        }

        do {
            // display options
            cout << "\n\n1:Display All\n2:By Account No\n3:Deposit\n4:Withdraw\n5:Exit" << endl;

            // user input
            cout << "Please input your choice: ";
            cin >> ch;

            switch (ch) {
            case 1: // displating account info
                for (i = 0; i <= 2; i++) {
                    C[i].ShowMyAccount();
                }
                break;
            case 2: // searching the record
                cout << "Account Number? ";
                cin >> a;
                for (i = 0; i <= 2; i++) {
                    found = C[i].Search(a);
                    if (found)
                        break;
                }
                if (!found)
                    cout << "Record Not Found" << endl;
                break;
            case 3: // deposit operation
                cout << "Account Number To Deposit Amount? ";
                cin >> a;
                for (i = 0; i <= 2; i++) {
                    found = C[i].Search(a);
                    if (found) {
                        C[i].Deposite();
                        break;
                    }
                }
                if (!found)
                    cout << "Record Not Found" << endl;
                break;
            case 4: // withdraw operation
                cout << "Account Number To Withdraw Amount? ";
                cin >> a;
                for (i = 0; i <= 2; i++) {
                    found = C[i].Search(a);
                    if (found) {
                        C[i].withdraw();
                        break;
                    }
                }
                if (!found)
                    cout << "Record Not Found" << endl;
                break;
            case 5: // exit
                cout << "Have a nice day" << endl;
                break;
            default:
                cout << "Wrong Option" << endl;
            }
        } while (ch != 5);
        return 0;
    }
};