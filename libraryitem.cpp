#include "libraryitem.h"
#include <iostream>
using namespace std;

LibraryItem::LibraryItem(string title, string author, int id)
    : title(title), author(author), id(id), isBorrowed(false) {}

int LibraryItem::getId() const {
    return id;
}

bool LibraryItem::getIsBorrowed() const {
    return isBorrowed;
}

void LibraryItem::borrowItem() {
    isBorrowed = true;
}

void LibraryItem::returnItem() {
    isBorrowed = false;
}
