#include <iostream>
#include <sstream>
#include "matrix.h"

using namespace std;

int main() {
    time_t t = time(0);
    tm *now = localtime(&t);

    stringstream firstName, secondName, thirdName;
    string name;

    Matrix matrix("matrix.txt");
    matrix.changeValue(0, 1, 5);
    matrix.changeValue(1, 0, 7);
    matrix.changeValue(2, 2, 9);
    matrix.changeValue(3, 2, 6);
    firstName << "matrix_1_" << now->tm_hour << now->tm_min << now->tm_sec << ".txt";
    matrix.saveToFile(firstName.str());

    Matrix matrixSecond(firstName.str());
    matrixSecond.transpose();
    secondName << "matrix_2_" << now->tm_hour << now->tm_min << now->tm_sec << ".txt";
    matrixSecond.saveToFile(secondName.str());

    Matrix matrixThird(secondName.str());
    matrixThird.addNumber(10);
    thirdName << "matrix_3_" << now->tm_hour << now->tm_min << now->tm_sec << ".txt";
    matrixThird.saveToFile(thirdName.str());
}
