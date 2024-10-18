#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <cstring>

using namespace std;

fstream file, ffile;
ifstream fin;
ofstream fout;

const int n = 50; // Number of cabs
char newWName[50] = "abcd", newWPass[50] = "abcd"; // for new worker registration
char adminName[50] = "admin";
char workerName[50] = "customer";
char adminPass[50] = "admin";
char workerPass[50] = "customer";

class Cab {
public:
    char pickup[80], drop[80], name[20]; // for booking initials
    float charges, dist; // for booking initials
    int cabno[n]; // for cab number
    int cabstats[n]; // for cab status

    Cab() { // to initialize Cab number & Status
        for (int i = 0; i < n; i++) {
            cabno[i] = i + 1; // Cab numbers start from 1
            cabstats[i] = 1; // initially all cabs are free
        }
        fout.open("CabStatus.txt", ios::app);
        for (int i = 0; i < n; i++) {
            fout << cabno[i] << "\t" << cabstats[i] << "\n";
        }
        fout.close();
    }

    void showCabStatus() {
        system("CLS");
        cout << "\t\t\t\t\tCAB STATUS\n" << endl;
        for (int i = 0; i < n; i++) {
            cout << "Cab " << cabno[i] << (cabstats[i] == 1 ? " IS FREE" : " IS NOT FREE") << "\t";
            if ((i + 1) % 10 == 0) cout << endl; // New line after every 10 cabs
        }
        cout << endl;
    }

    void book(int mod, int dis) {
        int availableCab = -1;
        for (int i = 0; i < n; i++) {
            if (cabstats[i] == 1) {
                availableCab = i;
                break;
            }
        }

        if (availableCab == -1) {
            cout << "All The Cabs Are Booked" << endl;
            return;
        }

        cout << "Enter your Name: ";
        cin >> name;
        cout << "Enter the PickUp point: ";
        cin >> pickup;
        cout << "Enter the Drop Point: ";
        cin >> drop;
        charges = (dis * 13) + mod;
        cout << "Calculating Your Total Fare:";
        Sleep(200);
        cout << endl << "Charges: Rs " << charges << endl;

        char bk; // to store customer's book request
        cout << "Do You Want to Book the Cab (Y/N): ";
        cin >> bk;

        if (bk == 'Y' || bk == 'y') {
            ffile.open("CabStatus.txt", ios::app);
            file.open("CustomerRecord.txt", ios::app); // File Open
            cout << "Cab id Num " << cabno[availableCab] << " is Booked For You\n";
            cout << "Your Booking Has Been Done\n";
            file << "\t\tCustomer Record\n";
            file << "Name: " << name << "\nPick: " << pickup << "\nDrop: " << drop
                 << "\nCharges: Rs." << charges << "\nCab No. Booked: " << cabno[availableCab] << endl;
            file.close();
            cabstats[availableCab] = 0; // Mark cab as booked
            ffile.close();
            Sleep(1000);
        } else {
            cout << "Your Booking has been cancelled." << endl;
            file.open("CancelBooking.txt", ios::app); // File Open
            file << "\t\tBooking Cancelled\nName: " << name << "\nPick: " << pickup
                 << "\nDrop: " << drop << "\nCharges: Rs " << charges << endl;
            file.close(); // File Close
        }
        Sleep(1000);
    }
};

class Admin {
public:
    void checkBookingRecord() {
        system("CLS");
        char ch;
        fin.open("CustomerRecord.txt"); // File open
        while (fin.get(ch)) {
            cout << ch;
        }
        fin.close(); // File close
        cout << endl;
    }

    void showDriverRecord() {
        system
