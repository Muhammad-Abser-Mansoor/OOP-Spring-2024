/* Programmer:Muhammad Abser Mansoor
 * Date: 18/03/2024
 * Descrption: Image handling
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Image {

    int width;
    int height;
    int* image_data;

    public:

    Image(int wid, int hei) : width(wid) , height(hei) {

        image_data = new int[2];
        image_data[0] = width;
        image_data[1] = height;
    }

    Image(Image &obj) : width(obj.width) , height(obj.height) {

        image_data = new int[2];
        image_data[0] = width;
        image_data[1] = height;
    }

    ~Image() {
        delete[] image_data;
    }

    void display() {

        std::cout << "Image Width: " << image_data[0] << std::endl <<
        "Image Height: " << image_data[1] << std::endl << std::endl;     
    }

    void updateData() {

        for (int i = 0; i < 2; i++) {

            if (image_data[i] < 1) {
                image_data[i] = std::rand() % 255 + 1;
            }
        }
    }
};

int main() {

    std::srand(std::time(NULL));
    Image object1(2,3);
    Image object2(object1);
    object1.display();
    object2.display();
    object1.updateData();
    object1.display();
    object2.display();
}
