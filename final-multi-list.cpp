#include <iostream>
using namespace std;

struct stud {
    int SID;
    stud* next;
    int COID;
};

struct course {
    int CID;
    course* next;
    stud* start;
};

course* head = NULL;

void insertCourse() {
    course* ptr = new course;
    cout << "Enter course ID: ";
    cin >> ptr->CID;
    ptr->next = NULL;
    ptr->start = NULL;
    if (head == NULL) {
        head = ptr;
    } else {
        course* curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = ptr;
    }
}

void insertStudent() {
    stud* ptr = new stud;
    cout << "Enter Student ID: ";
    cin >> ptr->SID;
    ptr->next = NULL;
    cout << "Enter Course ID you want to be enrolled: ";
    cin >> ptr->COID;
    course* check = head;
    while (check != NULL) {
        if (ptr->COID == check->CID) {
            break;
        } else {
            check = check->next;
        }
    }
    if (check == NULL) {
        cout << "Enter valid course ID\n";
        delete ptr; // Free allocated memory
    } else if (check->start == NULL) {
        check->start = ptr;
        cout << "Enrolled\n";
    } else {
        stud* temp = check->start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = ptr;
        cout << "Enrolled and added\n";
    }
}

void printCourse() {
    if (head == NULL) {
        cout << "List is empty\n";
    } else {
        course* curr = head;
        while (curr != NULL) {
            cout << "Course ID: " << curr->CID << "\n";
            stud* temp = curr->start;
            while (temp != NULL) {
                cout << "Enrolled Student IDs: " << temp->SID << "\n";
                temp = temp->next;
            }
            curr = curr->next;
        }
    }
}

int main() {
    int a;
    cout << "1. Enter Course ID\n";
    cout << "2. Enter Student ID\n";
    cout << "3. Print Courses\n";
    cout << "4. End\n";
    cin >> a;
    while (a >= 1 && a <= 4) {
        switch (a) {
            case 1:
                insertCourse();
                break;
            case 2:
                insertStudent();
                break;
            case 3:
                printCourse();
                break;
            case 4:
                cout << "Thanks for working\nRate my work out of 5: ";
                int c = 0;
                cin >> c;
                cout << "Ratings: " << c;
                break;
        }
        cout << "\n1. Enter Course ID\n";
        cout << "2. Enter Student ID\n";
        cout << "3. Print Courses\n";
        cout << "4. End\n";
        cin >> a;
    }
    return 0;
}
