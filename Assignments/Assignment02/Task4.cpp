#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

void Header() {

    std::cout << "Muhammad Abser Mansoor 23K-0030\n\n\n";
}

class User{

    std::string username,email,password;

    protected:

    char type;

    public:

    User(std::string name, std::string mail, std::string pass, char type) : username(name) , email(mail) , password(pass), type(type) {}

    bool verify(const User& user) { return user.username == this->username && user.email == this->email && user.password == this->password; }

    std::string Encryption(std::string password) {

        std::string encrypted = "";
        for (char letter : password) {

            encrypted += letter + 1;
        }
        return encrypted;

    }

    std::string getname() {return username;}
    std::string getemail() {return email;}

};

class Comment {

    int commentId;
    std::string content;

    static int totalComments;
public:
    Comment(std::string content = "") : content(content), commentId(totalComments+1) {}

    void display() { 
        std::cout << "\t[" << commentId << "]: " << content << '\n'; 
    }
};

int Comment::totalComments = 0;

class Post {

    int id, likes, views;
    std::string content;

    Comment *comments;
    int count;
    static int totalPosts;

public:
    Post(std::string content = "")
        : content(content), id(totalPosts+1), likes(0), count(0), views(0), comments(new Comment[10]) {}

    int getid() { return id; }
    int getlikes() { return likes; }
    int getviews() { return views; }

    void setlikes(int likes) {
        this->likes = likes;
    }
    void setviews(int views) {
        this->views = views;
    }
    void addcomment(const Comment& comment) {
        if (count > 10) { return; }
        comments[count++] = comment;
    }

    void display() {
        std::cout << "[" << id << "]: " << content << std::endl;
        std::cout << "Likes: " << likes << std::endl;
        std::cout << "Views: " << views << std::endl;
        std::cout << "Comments: " << count << std::endl;
        for (int i = 0; i < count; i++)
            comments[i].display();
        std::cout << std::endl;
        views++;
    }
};

int Post::totalPosts = 0;

class RegularUser : public User{

    Post *feed;
    int count;
    static const int MAX_FEED_SIZE = 10;

    public:

    RegularUser(std::string name, std::string email, std::string password) : User(name, email, password, 'r'), count(0), feed(new Post[MAX_FEED_SIZE]) {}

    void addTofeed(Post& post) {
        if (count > 5) {
            std::cout << "Max post limit reached!" << std::endl;
            return;
        }
        feed[count++] = post;
    }

    void viewFeed() {
        std::cout << "Feed of " << this->getname() << std::endl;
        std::cout << "Posts [" << count << "]\n\n";
        for (short i = 0; i < count; i++)
            feed[i].display();
        std::cout << std::endl;
    }
};

void sortPosts(Post *posts, int count) {
    std::sort(posts, posts+count, [&](Post& a, Post& b) { return a.getlikes() > b.getlikes(); });
    std::sort(posts, posts+count, [&](Post& a, Post& b) { return a.getviews() > b.getviews(); });
}

class BusinessUser : public User {

    int const limit = 10;
    int count;

    public:

    BusinessUser(std::string name, std::string email, std::string password) : User(name, email, password, 'b'), count(0) {}

    void promotePost(Post& post, Post *posts, int count) {

        if (type != 'b') { return; }

        if (this->count > limit) {

            std::cout << "Post cannot be promoted any further!" << std::endl;
            return;
        }

        for (int i = 0; i < count; i++) {

            if (posts[i].getid() == post.getid()) {

                int likes = post.getlikes(), views = post.getviews();
                posts[i].setlikes(likes*2);
                posts[i].setviews(views*3);
                break;
            }
        }
        sortPosts(posts, count);
        this->count++;
    }
};

int main() {
    Post posts[] = {
        Post("Hello World!"),
        Post("Promotional Content"),
        Post("Interesting")
    };

    posts[0].addcomment({ "Hello" });
    posts[0].addcomment({ "World "});
    posts[0].addcomment({ "!" });

    posts[1].setlikes(2);
    posts[1].setlikes(1);
    posts[1].addcomment({ "Promote King" });

    posts[2].addcomment({ "Could this be wheat" });

    RegularUser regular("Abser", "abs", "000");
    BusinessUser business("Ali", "ali", "001");
    business.promotePost(posts[1], posts, 2);

    regular.addTofeed(posts[0]);
    regular.addTofeed(posts[1]);
    regular.addTofeed(posts[2]);
    regular.viewFeed();

    return 0;
}
