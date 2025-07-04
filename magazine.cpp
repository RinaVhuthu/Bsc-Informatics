#include "magazine.h"
#include <iostream>
using namespace std;

Magazine::Magazine(string title, string author, int id, int issueNumber)
    : LibraryItem(title, author, id), issueNumber(issueNumber) {}

void Magazine::displayInfo() const {
    cout << "[Magazine] ID: " << id
         << " | Title: " << title
         << " | Author: " << author
         << " | Issue: " << issueNumber
         << " | Status: " << (isBorrowed ? "Borrowed" : "Available") << endl;
}
