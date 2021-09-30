#include<bits/stdc++.h>
using namespace std;

int x = 3251;
int Random(int limit) {
    x = ((x * x) / 100) % 10000;
    return x % limit;
}

void generate_password(int len) {
    string pass = "";
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    string Alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string spchar = "$*#!%&@";
    string nums = "0123456789";

    int cnt = 0, cnt_alpha = 0, cnt_Alpha = 0, cnt_sp = 0, cnt_nums = 0;
    int temp = Random(26);
    pass += alpha[temp];
    cnt_alpha++;

    while (cnt < len - 2) {
        int turn = Random(4);
        switch (turn) {
        case 0:
            if ((cnt_Alpha == 1) && (cnt_sp < 1 || cnt_alpha < 2 || cnt_nums < 1))
                break;
            else {
                temp = Random(26);
                pass += Alpha[temp];
                cnt++;
                cnt_Alpha++;
                break;
            }
        case 1:
            if ((cnt_alpha == 2) && (cnt_sp < 1 || cnt_Alpha < 1 || cnt_nums < 1))
                break;
            else {
                temp = Random(26);
                pass += alpha[temp];
                cnt++;
                cnt_alpha++;
                break;
            }
        case 2:
            if ((cnt_nums == 1) && (cnt_Alpha < 1 || cnt_sp < 1 || cnt_alpha < 2))
                break;
            else {
                temp = Random(10);
                pass += nums[temp];
                cnt++;
                cnt_nums++;
                break;
            }
        case 3:
            if ((cnt_sp == 1) && (cnt_Alpha < 1 || cnt_alpha < 2 || cnt_nums < 1))
                break;
            else {
                temp = Random(7);
                pass += spchar[temp];
                cnt++;
                cnt_sp++;
                break;
            }
        }
    }
    temp = Random(26);
    pass += Alpha[temp];

    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "\n\t\tPASSWORD: " << pass << endl;
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\t";
    system("PAUSE");
    system("cls");
}

int main() {
    int ch, len;
    system("cls");
    do {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\t\tRANDOM PASSWROD GENERATOR\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n";
        cout << "\t1. Generate Password\n\t2. Exit\n\n\tEnter your choice(1/2): ";
        cin >> ch;

        if (ch == 1) {
            cout << "\n\tEnter Required Length: ";
            cin >> len;
            if (len < 6 || len > 32) {
                cout << "\n\t\tERROR!!\n\t(Password should contain at least 6 characters and at max 32 characters) \n\t";
                system("PAUSE");
                system("cls");
            }
            else
                generate_password(len);
        }
        else if (ch != 2) {
            cout << "\n\tINVALID CHOICE!!\n\t";
            system("PAUSE");
            system("cls");
        }

    } while (ch != 2);
}
