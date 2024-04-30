/* Programmer:Muhammad Abser Mansoor
 * Date: 28/03/2024
 * Descrption: Security System
 */

#include <iostream>
#include <string>

template <typename T>

class Matrix{
    
    public:

    int rows,cols;
    T **data;

    int getrows() { return rows; }
    int getcolumns() { return cols; }
    void setrows(int r) { rows = r; }
    void setcolumns(int c) { cols = c; }

    Matrix(int r, int c) : rows(r) , cols(c) {

        for (int i = 0; i < r; i++) {

            *data = new T[cols];
        }
    }

    T get(int i, int j) const {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            std::cout << "Invalid index.";
            return 0;
        }
        return data[i][j];
    }

    void set(int i, int j, T val) {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            std::cout << "Invalid index.";
            return;
        }
        data[i][j] = val;
    }

    void virtual display() const = 0;

    Matrix<T> operator+(Matrix<T>& other) {
        
        if (rows != other.getrows() || cols != other.getcolumns()) { return nullptr; }

        Matrix<T> added(rows,cols);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                added.set(i,j, get(i,j) + other.get(i,j));
            }
        }
        return added;
    }

    Matrix<T> operator-(Matrix<T>& other) {
        if (rows != other.getrows() || cols != other.getcolumns()) { return nullptr; }

        Matrix subtracted(rows,cols);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                subtracted.set(i,j, get(i,j) - other.get(i,j));
            }
        }
        return subtracted;
    }

    Matrix<T> operator*(Matrix<T>& other) {

        if (cols != other.getrows()) { return nullptr; }

        Matrix<T> multiplied(rows,other.getcolumns());

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.getcolumns(); j++) {
                int value = 0;
                for (int k = 0; k < cols; k++) {
                    value += get(i,k) * other.get(k,j);
                }
                multiplied.set(i,j,value);
            }
        }
    }
};

class IntMatrix : public Matrix<int> {

    public:

    IntMatrix(int rows, int cols) : Matrix<int> (rows, cols) {}

    void display() const override{

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cout << "Value at index [" << i+1 << "][" << j+1 << "] is: " << get(i,j) << std::endl;
            }
        }
    }
};

class DoubleMatrix : public Matrix<double> {

    public:

    DoubleMatrix(double rows, double cols) : Matrix<double> (rows, cols) {}

    void display() const override{

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols ; j++) {
                std::cout << "Value at index [" << i+1 << "][" << j+1 << "] is: " << get(i,j) << std::endl;
            }
        }
    }
};

int main() {
    // Create instances of IntMatrix and DoubleMatrix
    Matrix<int> *intMat1 = new IntMatrix(2, 2);
    intMat1->set(0, 0, 1);
    intMat1->set(0, 1, 2);
    intMat1->set(1, 0, 3);
    intMat1->set(1, 1, 4);

    Matrix<int> *intMat2 = new IntMatrix(2, 2);
    intMat2->set(0, 0, 5);
    intMat2->set(0, 1, 6);
    intMat2->set(1, 0, 7);
    intMat2->set(1, 1, 8);

    Matrix<double> *doubleMat1 = new DoubleMatrix(2, 2);
    doubleMat1->set(0, 0, 1.1);
    doubleMat1->set(0, 1, 2.2);
    doubleMat1->set(1, 0, 3.3);
    doubleMat1->set(1, 1, 4.4);

    Matrix<double> *doubleMat2 = new DoubleMatrix(2, 2);
    doubleMat2->set(0, 0, 5.5);
    doubleMat2->set(0, 1, 6.6);
    doubleMat2->set(1, 0, 7.7);
    doubleMat2->set(1, 1, 8.8);

    // Perform matrix operations and display results
    std::cout << "IntMatrix1:\n";
    intMat1->display();
    std::cout << "IntMatrix2:\n";
    intMat2->display();

    Matrix<int> *intMatSum = intMat1 + intMat2;
    std::cout << "IntMatrix1 + IntMatrix2:\n";
    intMatSum->display();

    Matrix<int> *intMatDiff = intMat1 - intMat2;
    std::cout << "IntMatrix1 - IntMatrix2:\n";
    intMatDiff->display();

    Matrix<int> *intMatProd = intMat1 * intMat2;
    std::cout << "IntMatrix1 * IntMatrix2:\n";
    intMatProd->display();

    std::cout << "DoubleMatrix1:\n";
    doubleMat1->display();
    std::cout << "DoubleMatrix2:\n";
    doubleMat2->display();

    Matrix<double> *doubleMatSum = doubleMat1 + doubleMat2;
    std::cout << "DoubleMatrix1 + DoubleMatrix2:\n";
    doubleMatSum->display();

    Matrix<double> *doubleMatDiff = doubleMat1 - doubleMat2;
    std::cout << "DoubleMatrix1 - DoubleMatrix2:\n";
    doubleMatDiff->display();

    Matrix<double> *doubleMatProd = doubleMat1 * doubleMat2;
    std::cout << "DoubleMatrix1 * DoubleMatrix2:\n";
    doubleMatProd->display();

    return 0;
}
