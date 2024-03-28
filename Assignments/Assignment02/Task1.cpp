#include <iostream>
#include <string>

using namespace std;

class SecurityTool{
    
    public:
    
    string seclevel;
    float cost;
    int numberofdevices;

    SecurityTool(string sl, float c, int nod) : seclevel(sl) , cost(c) , numberofdevices(nod) {

        if (seclevel != "High" && seclevel != "Medium" && seclevel != "Low") {

            cout << "Incorrect input enter again: ";
            cin >> seclevel;
        }

        if (cost <= 0) {

            cout << "Incorrect input enter again: ";
            cin >> cost;
        }

        if (numberofdevices > 10) {

            cout << "Load exceeded. Enter lower amount of devices ";
            cin >> numberofdevices;
        }
    }

    void performScan() {
        cout << "Security level: " << seclevel << "\nCost: " << cost << "\nNumber of Devices: " << numberofdevices;
    }
};

class FirewallTool : public SecurityTool {

    public:

    int ports[23];
    string protocols[6] = {"HTTPS", "FTP", "UDP", "ICMP", "SSH", "SNMP"};

    FirewallTool(string sl, float c, int nod) : SecurityTool(sl,c,nod) {}

    void generateList(string ID) {

        for (int i = 0;;i++) {

            if (ID[i] > '0' && ID[i] <= '9') {
                
                for (int j = 0; j < 23; j++) {

                    ports[j] = ID[i] - '0' + j + 1;
                }
                return;
            }
        }
        cout << "Invalid ID";
        return;
    }

    void performScan(int port, string prot) {

        bool portfound = false;

        if (seclevel == "High") {

            for (int i = 0; i < 23; i++) {

                if (port == ports[i]) {
                    portfound = true;
                    break;
                }
            }

            if (!portfound) {
                cout << "Incorrect port";
                return;
            }

            bool protocolfound = false;
            for (int i = 0; i < 6; i++) {

                if (prot == protocols[i]) {
                    protocolfound = true;
                    break;
                }
            }
            if (!protocolfound) {
                cout << "Incorrect protocol";
                return;
            }
        }

        if (seclevel == "Medium") {

            for (int i = 0; i < 23; i++) {

                if (port == ports[i] || port == ports[22]+1 || port == ports[22]+2) {
                    portfound = true;
                    break;
                }
            }

            if (!portfound) {
                cout << "Incorrect port";
                return;
            }

            bool protocolfound = false;
            for (int i = 0; i < 6; i++) {

                if (prot == protocols[i]) {
                    protocolfound = true;
                    break;
                }
            }
            if (!protocolfound) {
                cout << "Incorrect protocol";
                return;
            }
        }

        if (seclevel == "Low") {

            for (int i = 0; i < 23; i++) {

                if (port == ports[i] || port == ports[22]+1 || port == ports[22]+2 || port == ports[22]+3 || port == ports[22]+4 || port == ports[22]+5) {
                    portfound = true;
                    break;
                }
            }

            if (!portfound) {
                cout << "Incorrect port";
                return;
            }

            bool protocolfound = false;
            for (int i = 0; i < 6; i++) {

                if (prot == protocols[i] || prot == "TCP" || prot == "DNS") {
                    protocolfound = true;
                    break;
                }
            }
            if (!protocolfound) {
                cout << "Incorrect protocol";
                return;
            }
        }
    }

};
int main() {

    FirewallTool Tool("Medium",400,9);
    Tool.generateList("0030");
    Tool.performScan(27,"HTTPS");
}
