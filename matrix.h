using namespace std;

#ifndef Z6_MATRIX_H
#define Z6_MATRIX_H

class Matrix {
public:
    Matrix(int, int);

    Matrix(string);

    void changeValue(int, int, int);

    void addNumber(int);

    int getCell(int, int);

    string getLine(int);

    string getColumn(int);

    string getMatrix();

    void transpose();

    void saveToFile(string);

private:
    int **matrix;
    int width;
    int height;
};

#endif //Z6_MATRIX_H
