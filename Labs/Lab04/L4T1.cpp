/* Programmer: Muhammad Abser Mansoor
 * Date: 15/2/2024
 * Desc.: Book Class
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

    Book() {
        name = "Bookname";
        author = "Authorname";
        ISBN = 0;
        totalpages = 0;
        numpage = -1;
    }

    Book(std::string bookname,std::string bookauthor,int bookISBN,int booktotalpages,int booknumpage) {
        name = bookname;
        author = bookauthor;
        ISBN = bookISBN;
        totalpages = booktotalpages;
        numpage = booknumpage;
    }

    void pagesread(int n) {

        numpage = n;
        if (numpage == totalpages)
            std::cout << "You have finished the book" << std::endl;
            else {
            std::cout << "You have not finished the book" << std::endl; }
    }

};

int main() {

    Book bokoen1;

    Book bokoen2("Mein Kampf","Hitler",10322,400,0);

    bokoen1.pagesread(555);
    bokoen2.pagesread(400);
}
