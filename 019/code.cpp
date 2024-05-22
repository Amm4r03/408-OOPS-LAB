// AIM : Create a class Book with data members book number, book name and member function getdata() and putdata(). Create a a class Author with data members author name, publisher, and members getdata() and showdata(). Create an another class Detail with data members no of pages and year of publication. Derive detail from Book and Publisher. Display all the information by using array of objects of class Detail

#include <iostream>
using namespace std;

class Book {
    protected : 
        int book_number;
        string book_name;
    public : 
        Book(string bookName, int bookNumber) {
            book_number = bookNumber;
            book_name = bookName;
        }

        void getData(string bookName, int bookNumber) {
            book_number = bookNumber;
            book_name = bookName;
        }

        void putData(void) {
            cout << "BOOK DETAILS : " << endl;
            cout << "Book name : " << book_name << endl;
            cout << "Book number : " << book_number << endl;
            cout << endl;
        }
};

class Author {
    protected :
        string author_name;
        string publisher;
    public : 
        Author(string auth_name, string publisher_name) {
            author_name = auth_name;
            publisher = publisher_name;
        }

        void getData(string auth_name, string pub_name) {
            author_name = auth_name;
            publisher = pub_name;
        }

        void showData() {
            cout << "AUTHOR DETAILS" << endl;
            cout << "Name : " << author_name << endl;
            cout << "Publisher : " << publisher << endl;
            cout << endl;
        }
};  

class Detail : public Book, public Author {
private:
    int number_of_pages;
    int year_of_publication;

public:
    Detail(string bookName = "", int bookNumber = 0, string auth_name = "", string pub_name = "", int pages = 0, int year = 0)
        : Book(bookName, bookNumber), Author(auth_name, pub_name) {
        number_of_pages = pages;
        year_of_publication = year;
    }

    void getData(string bookName, int bookNumber, string auth_name, string pub_name, int pages, int year) {
        Book::getData(bookName, bookNumber);
        Author::getData(auth_name, pub_name);
        number_of_pages = pages;
        year_of_publication = year;
    }

    void displayData() {
        putData();
        showData();
        cout << "DETAILS" << endl;
        cout << "Number of pages : " << number_of_pages << endl;
        cout << "Year of publication : " << year_of_publication << endl;
        cout << endl;
    }
};

int main() {
    const int numBooks = 3;
    Detail library[numBooks];

    library[0].getData("The Great Gatsby", 1, "F. Scott Fitzgerald", "Charles Scribner's Sons", 218, 1925);
    library[1].getData("1984", 2, "George Orwell", "Secker & Warburg", 328, 1949);
    library[2].getData("To Kill a Mockingbird", 3, "Harper Lee", "J.B. Lippincott & Co.", 281, 1960);

    for (int i = 0; i < numBooks; ++i) {
        library[i].displayData();
    }

    return 0;
}