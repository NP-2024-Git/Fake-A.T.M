#include <iostream>
#include <fstream>
#include "Variables.h"
using namespace std;

void loadData() {
    ifstream file("data.txt");
    if (file.is_open()) {
        file >> user_amount >> password;
        file.close();
    } else {
        user_amount = 85928206;
        password = 1111;
    }
}

void saveData() {
    ofstream file("data.txt");
    file << user_amount << " " << password;
    file.close();
}

int main() {
    loadData();

    cout << "-----Welcome to the Fake A.T.M-----" << endl;
    cout << "Please enter the language [1-English 2-Persian]: ";
    cin >> language;

    if (language == 1) {
        cout << "Please enter your password: ";
        cin >> password_input;

        if (password_input == password) {
            cout << "Welcome Miss./Mr. [" << username << "]." << endl;
            cout << "Your account balance is: [" << user_amount << "T]." << endl;
            cout << "[1 - Charge phone | 2 - Move amount | 3 - Pay bill | 4 - Change password]: ";
            cin >> Work;

            if (Work == 1) {
                cout << "Enter your phone number: ";
                cin >> number;
                cout << "How much would you like to charge the number [" << number << "]: ";
                cin >> phone_charge;
                if (phone_charge > user_amount) {
                    cout << "Your account balance is too small. The payment cannot be done." << endl;
                } else {
                    user_amount -= phone_charge;
                    cout << "The payment is done." << endl;
                    cout << "Your new account balance is: [" << user_amount << "T]." << endl;
                }
            } else if (Work == 2) {
                cout << "Enter the credit card number: ";
                cin >> card;
                cout << "How much would you like to charge the credit card [" << card << "]: ";
                cin >> charge_card;
                if (charge_card > user_amount) {
                    cout << "Your account balance is too small. The payment cannot be done." << endl;
                } else {
                    user_amount -= charge_card;
                    cout << "The payment is done." << endl;
                    cout << "Your new account balance is: [" << user_amount << "T]." << endl;
                }
            } else if (Work == 3) {
                cout << "Enter the bill type: [1-electric | 2-gas | 3-water]: ";
                cin >> bill;
                int bill_number;
                if (bill == 1) {
                    cout << "Enter the electric bill number: ";
                    cin >> bill_number;
                } else if (bill == 2) {
                    cout << "Enter the gas bill number: ";
                    cin >> bill_number;
                } else if (bill == 3) {
                    cout << "Enter the water bill number: ";
                    cin >> bill_number;
                } else {
                    cout << "Invalid bill type." << endl;
                    return 1;
                }

                cout << "You have to pay: [" << bill_random << "T] for bill: [" << bill_number << "]" << endl;
                cout << "Do you want to pay? [1 - Yes | 2 - No]: ";
                cin >> bill_accept;

                if (bill_accept == 1) {
                    if (bill_random > user_amount) {
                        cout << "Your account balance is too small. The payment cannot be done." << endl;
                    } else {
                        user_amount -= bill_random;
                        cout << "The payment is done." << endl;
                        cout << "Your new account balance is: [" << user_amount << "T]." << endl;
                    }
                } else if (bill_accept == 2) {
                    cout << "The payment is canceled." << endl;
                } else {
                    cout << "Invalid input." << endl;
                }

            } else if (Work == 4) {
                int new_password;
                cout << "Enter new password: ";
                cin >> new_password;
                password = new_password;
                cout << "Your new password is: " << password << endl;
            } else {
                cout << "Invalid option selected." << endl;
            }

            saveData();
        } else {
            cout << "The password is incorrect." << endl;
            cout << "Your card has been terminated." << endl;
        }
    } else if (language == 2) {
        cout << "This language named [فارسی] is not supported." << endl;
    } else {
        cout << "Invalid input." << endl;
    }

    return 0;
}
