#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include <string>
using namespace std;

class LibraryItem {
protected:
    string title;
    string author;
    int id;
    bool isBorrowed;

public:
    LibraryItem(string title, string author, int id);
    virtual ~LibraryItem() = default;

    int getId() const;
    bool getIsBorrowed() const;
    void borrowItem();
    void returnItem();

    virtual void displayInfo() const = 0;
};

#endif
