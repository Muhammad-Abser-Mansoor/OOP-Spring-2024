#include <iostream>

using namespace std;

class Logo {
    string content;
public:
    Logo(string content) : content(content) {}

    inline void details() const { cout << content << endl; }
};

class Server {
private:
    unsigned short port;
    string address;
public:
    Server(unsigned short port, string address) : port(port), address(address) {}

    inline void details() const { cout << address << ":" << port << endl; }
};

class Platform {
    Logo logo;
    Server server;
    string name;
public:
    Platform(string platform_name, string platform_logo, unsigned short server_port, string server_address) 
        : logo(platform_logo), server(server_port, server_address), name(platform_name) {}

    void display() {
        cout << name << endl;
        logo.details();
        server.details();
    }

    friend void changeLogo(Platform& platform, const Logo& new_logo);
};

void changeLogo(Platform& platform, const Logo& new_logo) { platform.logo = new_logo; }

int main() {
    Platform twitter("Twitter", "Default-Logo", 3000, "127.0.0.1");

    twitter.display();
    cout << endl;
    changeLogo(twitter, Logo{ "Doge-Coin" });
    twitter.display();
}
