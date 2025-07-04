#include "book.h"
#include <iostream>
using namespace std;

Book::Book(string title, string author, int id, string genre)
    : LibraryItem(title, author, id), genre(genre) {}

void Book::displayInfo() const {
    cout << "[Book] ID: " << id
         << " | Title: " << title
         << " | Author: " << author
         << " | Genre: " << genre
         << " | Status: " << (isBorrowed ? "Borrowed" : "Available") << endl;
}
