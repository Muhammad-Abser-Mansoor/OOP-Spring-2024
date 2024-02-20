/* Programmer: Muhammad Abser Mansoor
 * Date: 15/2/2024
 * Desc.: Revised Book Class
 */

 #include <iostream>
 #include <string>
 #include <vector>

class Book {

    std::string name;
    std::string author;
    int ISBN;
    int totalpages;
    int numpage;

    public:

    Book() : totalpages(1000), numpage(0) {}
    
    void setname(std::string newname) {
        name = newname;
    }
    
    void setauthor(std::string newauthor) {
        author = newauthor;
    }
    
    void setISBN(int newISBN) {
        ISBN = newISBN;
    }

    void pagesread(int n) {

        numpage = n;
        if (numpage == totalpages)
            std::cout << "You have finished the book" << std::endl;
            else {
            std::cout << "You have not finished the book" << std::endl; }
    }
    
    void showbookdetails() {
        std::cout << "Book name is " << name << std::endl;
        std::cout << "Author's name is " << author << std::endl;
        std::cout << "Total pages are " << totalpages << std::endl;
        std::cout << "Number of pages read are " << numpage << std::endl;
    }
};

int main() {

    Book bokoen1;

    bokoen1.pagesread(555);
    bokoen1.setauthor("Abser");
    bokoen1.setISBN(1111);
    bokoen1.setname("HOI4 Guide");
    bokoen1.showbookdetails();
}
