#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int rollNo;
    string className;
    string division;
    string dob;
    string bloodGroup;
    string address;
    string telephoneNo;
    string drivingLicenseNo;
    static int count;

    // Default constructor
    Student() {
        count++;
    }

    // Parameterized constructor
    Student(string name, int rollNo, string className, string division, string dob, string bloodGroup, string address, string telephoneNo, string drivingLicenseNo) {
        this->name = name;
        this->rollNo = rollNo;
        this->className = className;
        this->division = division;
        this->dob = dob;
        this->bloodGroup = bloodGroup;
        this->address = address;
        this->telephoneNo = telephoneNo;
        this->drivingLicenseNo = drivingLicenseNo;
        count++;
    }

    // Copy constructor
    Student(const Student &s) {
        name = s.name;
        rollNo = s.rollNo;
        className = s.className;
        division = s.division;
        dob = s.dob;
        bloodGroup = s.bloodGroup;
        address = s.address;
        telephoneNo = s.telephoneNo;
        drivingLicenseNo = s.drivingLicenseNo;
    }

    // Destructor
    ~Student() {
        count--;
    }

    // Static function
    static int getCount() {
        return count;
    }

    // Function to display student details
    void display() {
        cout << "Name: " << name << "\nRoll No: " << rollNo << "\nClass: " << className << "\nDivision: " << division << "\nDOB: " << dob << "\nBlood Group: " << bloodGroup << "\nAddress: " << address << "\nTelephone No: " << telephoneNo << "\nDriving License No: " << drivingLicenseNo << endl;
    }
};

int Student::count = 0;

int main(){
    Student* s = nullptr;
    while (true) {
        cout << "1. Add Student\n2. Display All Students\n3. Exit\nEnter your choice: ";
        int choice;
        cin >> choice;
        cin.ignore();  // To clear the input buffer
        switch (choice) {
            case 1: {
                string name, className, division, dob, bloodGroup, address, telephoneNo, drivingLicenseNo;
                int rollNo;
                cout << "Enter Name: ";
                getline(cin, name);
                cout << "Enter Roll No: ";
                cin >> rollNo;
                cin.ignore();
                cout << "Enter Class: ";
                getline(cin, className);
                cout << "Enter Division: ";
                getline(cin, division);
                cout << "Enter DOB: ";
                getline(cin, dob);
                cout << "Enter Blood Group: ";
                getline(cin, bloodGroup);
                cout << "Enter Address: ";
                getline(cin, address);
                cout << "Enter Telephone No: ";
                getline(cin, telephoneNo);
                cout << "Enter Driving License No: ";
                getline(cin, drivingLicenseNo);
                try {
                    s = new Student(name, rollNo, className, division, dob, bloodGroup, address, telephoneNo, drivingLicenseNo);
                } catch (bad_alloc &ba) {
                    cerr << "Bad Allocation: " << ba.what() << endl;
                    return 1;
                }
                break;
            }
            case 2: {
                if (s != nullptr) {
                    s->display();
                    delete s;
                    s = nullptr;
                } else {
                    cout << "No student data available." << endl;
                }
                break;
            }
            case 3: {
                if (s != nullptr) {
                    delete s;
                }
                exit(0);
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
            }
        }
    }
    return 0;
}
