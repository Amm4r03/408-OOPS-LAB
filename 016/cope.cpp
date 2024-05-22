// AIM : Write a program to design a class representing the information regatding digital library (books, tape: book & tape, should be separate classes having the base class as media). The class should have the functionality for adding new items, issuing, deposit, etc. the program should use the runtime polymorphism

#include <iostream>
#include <string>
using namespace std;

class Media {
protected:
    string title;
    bool isIssued;

public:
    Media(string mediaTitle) : title(mediaTitle), isIssued(false) {}

    virtual void addItem() = 0;
    virtual void issueItem() = 0;
    virtual void depositItem() = 0;
    virtual void showDetails() = 0;
    virtual ~Media() {}
};

class Book : public Media {
private:
    string author;

public:
    Book(string bookTitle, string bookAuthor) : Media(bookTitle), author(bookAuthor) {}

    void addItem()  {
        cout << "Book added: " << title << " by " << author << endl;
    }

    void issueItem()  {
        if (isIssued) {
            cout << "Book \"" << title << "\" is already issued." << endl;
        } else {
            isIssued = true;
            cout << "Book \"" << title << "\" has been issued." << endl;
        }
    }

    void depositItem()  {
        if (!isIssued) {
            cout << "Book \"" << title << "\" is not issued." << endl;
        } else {
            isIssued = false;
            cout << "Book \"" << title << "\" has been deposited." << endl;
        }
    }

    void showDetails()  {
        cout << "Book: " << title << ", Author: " << author << ", " << (isIssued ? "Issued" : "Available") << endl;
    }
};

class Tape : public Media {
private:
    double duration; 

public:
    Tape(string tapeTitle, double tapeDuration) : Media(tapeTitle), duration(tapeDuration) {}

    void addItem()  {
        cout << "Tape added: " << title << " with duration " << duration << " minutes." << endl;
    }

    void issueItem()  {
        if (isIssued) {
            cout << "Tape \"" << title << "\" is already issued." << endl;
        } else {
            isIssued = true;
            cout << "Tape \"" << title << "\" has been issued." << endl;
        }
    }

    void depositItem()  {
        if (!isIssued) {
            cout << "Tape \"" << title << "\" is not issued." << endl;
        } else {
            isIssued = false;
            cout << "Tape \"" << title << "\" has been deposited." << endl;
        }
    }

    void showDetails()  {
        cout << "Tape: " << title << ", Duration: " << duration << " minutes, " << (isIssued ? "Issued" : "Available") << endl;
    }
};

void libraryOperations(Media* library[], int size) {
    for (int i = 0; i < size; ++i) {
        library[i]->addItem();
        library[i]->showDetails();
        library[i]->issueItem();
        library[i]->showDetails();
        library[i]->depositItem();
        library[i]->showDetails();
        cout << endl;
    }
}

int main() {
    const int librarySize = 4;
    Media* library[librarySize];

    library[0] = new Book("The Great Gatsby", "F. Scott Fitzgerald");
    library[1] = new Book("1984", "George Orwell");
    library[2] = new Tape("Ken Carson", 45.5);
    library[3] = new Tape("Frank Ocean", 60.0);

    libraryOperations(library, librarySize);

    for (int i = 0; i < librarySize; ++i) {
        delete library[i];
    }

    return 0;
}
