#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
#include "book.h"
#include "magazine.h"
using namespace std;

vector<LibraryItem*> items;
int nextId = 1;

void showMenu();
void addBook();
void addMagazine();
void displayItems();
void borrowItem();
void returnItem();
void searchItem();
void saveToFile();
void loadFromFile();

int main() {
    loadFromFile();
    int choice;

    do {
        showMenu();
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: addBook(); break;
            case 2: addMagazine(); break;
            case 3: searchItem(); break;
            case 4: borrowItem(); break;
            case 5: returnItem(); break;
            case 6: displayItems(); break;
            case 0: saveToFile(); cout << "Exiting...\n"; break;
            default: cout << "Invalid option.\n";
        }
    } while (choice != 0);

    return 0;
}

void showMenu() {
    cout << "\n--- Library Menu ---\n"
         << "1. Add Book\n"
         << "2. Add Magazine\n"
         << "3. Search Item by ID\n"
         << "4. Borrow Item\n"
         << "5. Return Item\n"
         << "6. Display All Items\n"
         << "0. Exit and Save\n"
         << "Choose an option: ";
}

void addBook() {
    string title, author, genre;
    cout << "Enter title, author, genre: ";
    getline(cin, title);
    getline(cin, author);
    getline(cin, genre);
    items.push_back(new Book(title, author, nextId++, genre));
    cout << "Book added!\n";
}

void addMagazine() {
    string title, author;
    int issue;
    cout << "Enter title, author, issue number: ";
    getline(cin, title);
    getline(cin, author);
    cin >> issue;
    cin.ignore();
    items.push_back(new Magazine(title, author, nextId++, issue));
    cout << "Magazine added!\n";
}

void displayItems() {
    for (auto* item : items)
        item->displayInfo();
}

void searchItem() {
    int id;
    cout << "Enter ID to search: ";
    cin >> id;
    for (auto* item : items)
        if (item->getId() == id)
            return item->displayInfo();
    cout << "Item not found.\n";
}

void borrowItem() {
    int id;
    cout << "Enter ID to borrow: ";
    cin >> id;
    for (auto* item : items)
        if (item->getId() == id) {
            if (!item->getIsBorrowed()) {
                item->borrowItem();
                cout << "Item borrowed!\n";
            } else cout << "Already borrowed.\n";
            return;
        }
    cout << "Item not found.\n";
}

void returnItem() {
    int id;
    cout << "Enter ID to return: ";
    cin >> id;
    for (auto* item : items)
        if (item->getId() == id) {
            if (item->getIsBorrowed()) {
                item->returnItem();
                cout << "Item returned!\n";
            } else cout << "Not currently borrowed.\n";
            return;
        }
    cout << "Item not found.\n";
}

void saveToFile() {
    ofstream file("library_data.txt");
    for (auto* item : items) {
        if (auto* b = dynamic_cast<Book*>(item)) {
            file << "Book," << b->getId() << "," << b->getIsBorrowed() << "," << b->title << "," << b->author << "," << b->genre << endl;
        } else if (auto* m = dynamic_cast<Magazine*>(item)) {
            file << "Magazine," << m->getId() << "," << m->getIsBorrowed() << "," << m->title << "," << m->author << "," << m->issueNumber << endl;
        }
    }
}

void loadFromFile() {
    ifstream file("library_data.txt");
    string type, title, author, genre;
    int id, borrowed, issue;

    while (getline(file, type, ',')) {
        file >> id;
        file.ignore();
        file >> borrowed;
        file.ignore();
        getline(file, title, ',');
        getline(file, author, ',');
        if (type == "Book") {
            getline(file, genre);
            Book* b = new Book(title, author, id, genre);
            if (borrowed) b->borrowItem();
            items.push_back(b);
        } else if (type == "Magazine") {
            file >> issue;
            Magazine* m = new Magazine(title, author, id, issue);
            if (borrowed) m->borrowItem();
            items.push_back(m);
        }
        nextId = max(nextId, id + 1);
    }
}
