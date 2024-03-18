/* Programmer:Muhammad Abser Mansoor
 * Date: 18/03/2024
 * Descrption: Library management
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Book {

    std::string title,author,publisher;

    public:

    Book(std::string title, std::string author, std::string publisher) : title(title) , author(author) , publisher(publisher) {}

    void display() {

        std::cout << "Title: " << title << "\nAuthor: " << author << "\nPublisher: " << publisher << std::endl; 
    }
};

class FictionBook : public Book {

    std::string genre, protagonist;

    public:

    FictionBook(std::string title, std::string author, std::string publisher, std::string genre, std::string protagonist)
    : Book(title,author,publisher) , genre(genre) , protagonist(protagonist) {}

    void display() {

        Book::display();
        std::cout << "Genre: " << genre << "\nProtagonist: " << protagonist << std::endl;
    }
};

int main() {

    FictionBook fiction("The Great Gatsby", "F. Scott Fitzgerald", "Scribner", "Fiction", "Jay Gatsby");
    fiction.display();
}
