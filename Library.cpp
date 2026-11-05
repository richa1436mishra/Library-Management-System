
#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    int id;
    string title, author;
    int quantity;

    void input() {
        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Book Title: ";
        getline(cin, title);

        cout << "Enter Author Name: ";
        getline(cin, author);

        cout << "Enter Quantity: ";
        cin >> quantity;
    }

    void display() {
        cout << "\nBook ID: " << id;
        cout << "\nTitle: " << title;
        cout << "\nAuthor: " << author;
        cout << "\nAvailable Copies: " << quantity;
        cout << "\n-------------------------\n";
    }
};

int main() {
    Book books[100];
    int count = 0;
    int choice, searchID;
    bool found;

    do {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Book";
        cout << "\n2. Display All Books";
        cout << "\n3. Search Book";
        cout << "\n4. Issue Book";
        cout << "\n5. Return Book";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (count < 100) {
                books[count].input();
                count++;
                cout << "Book added successfully!\n";
            } else {
                cout << "Library storage is full!\n";
            }
            break;

        case 2:
            if (count == 0) {
                cout << "No books available.\n";
            } else {
                for (int i = 0; i < count; i++) {
                    books[i].display();
                }
            }
            break;

        case 3:
            cout << "Enter Book ID to search: ";
            cin >> searchID;
            found = false;

            for (int i = 0; i < count; i++) {
                if (books[i].id == searchID) {
                    books[i].display();
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Book not found!\n";
            break;

        case 4:
            cout << "Enter Book ID to issue: ";
            cin >> searchID;
            found = false;

            for (int i = 0; i < count; i++) {
                if (books[i].id == searchID) {
                    found = true;

                    if (books[i].quantity > 0) {
                        books[i].quantity--;
                        cout << "Book issued successfully!\n";
                    } else {
                        cout << "Book is not available.\n";
                    }
                    break;
                }
            }

            if (!found)
                cout << "Book not found!\n";
            break;

        case 5:
            cout << "Enter Book ID to return: ";
            cin >> searchID;
            found = false;

            for (int i = 0; i < count; i++) {
                if (books[i].id == searchID) {
                    books[i].quantity++;
                    cout << "Book returned successfully!\n";
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Book not found!\n";
            break;

        case 6:
            cout << "Exiting Library System...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
