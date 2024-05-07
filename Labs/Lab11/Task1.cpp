#include <iostream>
#include <string>

using namespace std;

class convert {
protected:
    float val1, val2;
public:
    convert(float value) : val1(value), val2(0) {}
    virtual float compute() = 0;
};

class l_to_g : public convert {
public:
    l_to_g(float value) : convert(value) {}

    float compute() override { 
        this->val2 = this->val1 / 4.55f;
        return this->val2;
    }
};

class f_to_c : public convert {
public:
    f_to_c(float value) : convert(value) {}

    float compute() override { 
        this->val2 = (this->val1 - 32.f) * (5/9);
        return this->val2;
    }
};

int main() {
    convert *lg = new l_to_g(4);
    convert *fc = new f_to_c(70);

    cout << lg->compute() << endl;
    cout << fc->compute() << endl;

    return 0;
}
