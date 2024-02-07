/*
 * Programmer: Muhammad Abser Mansoor
 * Date: 4/2/24
 * Desc: Library Book inventory management
 */

#include <iostream>
#include <string>

using namespace std;

struct book {
    string title;
    string author;
    int dop; // dop is day of publication and mop is month and yop is year
    int mop;
    int yop;
    string genre;
};

void input(book books[], int num) {
    books = new book[num];
    for (int i = 0; i < num; i++) {
        cout << "Enter the title: ";
        getline(cin,books[i].title);
        cout << "Enter the author's name: ";
        getline(cin,books[i].author);
        cout << "Enter the day of publication";
        cin >> books[i].dop;
        cout << "Enter the month of publication";
        cin >> books[i].mop;
        cout << "Enter the year of publication";
        cin >> books[i].yop;
        cout << "Enter the Genre: ";
        getline(cin,books[i].genre);
    }
    cout << "Inputs taken" << endl;
}

book *find(book books[], string query, string thing) {
    switch (query) {
        case "title":
        for (int i = 0; i < sizeof(books)/sizeof(book);i++) {
            if (thing == books[i].title) {
                return books[i];
            }
        }
        return NULL;
        break;
        case "author":
         for (int i = 0; i < sizeof(books)/sizeof(book);i++) {
            if (thing == books[i].author) {
                return books[i];
            }
        }
        return NULL;
        break;
        case "genre":
         for (int i = 0; i < sizeof(books)/sizeof(book);i++) {
            if (thing == books[i].genre) {
                return books[i];
            }
        }
        return NULL;
        break;
        default:
        return NULL;
    }
}

book find(book books[], string query,int date) {
    switch (query) {
        case "day":
        for (int i = 0; i < sizeof(books)/sizeof(book);i++) {
            if (date == books[i].day) {
                return books[i];
            }
        }
        return NULL;
        break;
        case "month":
         for (int i = 0; i < sizeof(books)/sizeof(book);i++) {
            if (date == books[i].month) {
                return books[i];
            }
        }
        return NULL;
        break;
        case "year":
         for (int i = 0; i < sizeof(books)/sizeof(book);i++) {
            if (date == books[i].year) {
                return books[i];
            }
        }
        return NULL;
        break;
        default:
        return NULL;
    }
}

void modify(book books[], string title,string auth,int day,int month,int year,string genre) {
    for (int i = 0;i < sizeof(books)/sizeof(book);i++) {
        if (title == books[i].title && auth == books[i].author && day == books[i].day && month == books[i].month && year == books[i].year && genre == books[i].genre) {
        cout << "Enter the title: ";
        getline(cin,books[i].title);
        cout << "Enter the author's name: ";
        getline(cin,books[i].author);
        cout << "Enter the day of publication";
        cin >> books[i].dop;
        cout << "Enter the month of publication";
        cin >> books[i].mop;
        cout << "Enter the year of publication";
        cin >> books[i].yop;
        cout << "Enter the Genre: ";
        getline(cin,books[i].genre);
        cout << "Inputs taken" << endl;
        return;
        }
    }
    cout << "No record found";
    return;
}

int main() {
    book books = new book[1];
    char choice;
    cout << "For new book input press i; For Modification of book press m; For finding a book press f" << endl;
    switch (choice) {
        case 'i':
        int num;
        cout << "Enter number of books to be stored";
        cin >> num;
        input(books,num);
        break;
        case 'm':
        int day,month,year;
        string auth,title,genre;
        cout << "Enter the title of book to be modified: ";
        getline(cin,title);
        cout << "Enter the author of book to be modified: ";
        getline(cin,auth);
        cout << "Enter the day of publication of book to be modified: ";
        cin >> day;
        cout << "Enter the month of publication of book to be modified: ";
        cin >> month;
        cout << "Enter the year of publication of book to be modified: ";
        cin >> year;
        cout << "Enter the genre of book to be modified: ";
        getline(cin,genre);
        modify(books,title,auth,day,month,year,genre);
        break;
        case 'f':
        string auth,title,ch;
        cout << "Do you want to find a book by author name or title (enter 'author' or 'title')";
        cin >> ch;
        if (ch == "title") {
            cout << "Enter the title of book to be found: ";
            getline(cin,title);
        }
        else {
            cout << "Enter the author of book to be found: ";
            getline(cin,auth);
        }
    }
    return 0;
}
