#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "libraryitem.h"
using namespace std;

class Magazine : public LibraryItem {
private:
    int issueNumber;

public:
    Magazine(string title, string author, int id, int issueNumber);
    void displayInfo() const override;
};

#endif
