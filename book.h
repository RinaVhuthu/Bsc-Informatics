#ifndef BOOK_H
#define BOOK_H

#include "libraryitem.h"
using namespace std;

class Book : public LibraryItem {
private:
    string genre;

public:
    Book(string title, string author, int id, string genre);
    void displayInfo() const override;
};

#endif
