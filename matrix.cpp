#include <string>
#include <fstream>
#include <sstream>
#include "matrix.h"

using namespace std;

Matrix::Matrix(int width, int height) {
    this->height = height;
    this->width = width;
    this->matrix = new int *[width];
    for (int i = 0; i < width; i++) {
        this->matrix[i] = new int[height];
    }
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            this->matrix[i][j] = 0;
        }
    }
}

Matrix::Matrix(string name) {
    string lineFromFile;
    int value;

    ifstream file(name.c_str());
    if (file.is_open()) {
        getline(file, lineFromFile);
        this->width = atoi(lineFromFile.c_str());
        getline(file, lineFromFile);
        this->height = atoi(lineFromFile.c_str());
        this->matrix = new int *[width];
        for (int i = 0; i < width; i++) {
            this->matrix[i] = new int[height];
        }
        int i = 0;
        while (!file.eof() && i < this->width) {
            getline(file, lineFromFile);
            stringstream line;
            line << lineFromFile;
            for (int j = 0; j < this->height; j++) {
                line >> value;
                this->matrix[i][j] = value;
            }
            i++;
        }
    }
    file.close();
}

void Matrix::changeValue(int width, int height, int value) {
    this->matrix[width][height] = value;
}

void Matrix::addNumber(int value) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            this->matrix[i][j] += value;
        }
    }
}

int Matrix::getCell(int width, int height) {
    return this->matrix[width][height];
}

string Matrix::getLine(int width) {
    stringstream line;
    for (int j = 0; j < this->height; j++) {
        line << this->matrix[width][j] << " ";
    }
    return line.str();
}

string Matrix::getColumn(int height) {
    stringstream column;
    for (int i = 0; i < this->width; i++) {
        column << this->matrix[i][height] << " ";
    }
    return column.str();
}

string Matrix::getMatrix() {
    stringstream matrix;
    for (int i = 0; i < this->width; i++) {
        matrix << this->getLine(i) << endl;
    }
    return matrix.str();
}

void Matrix::transpose() {
    int **newMatrix;
    newMatrix = new int *[this->height];
    for (int i = 0; i < this->height; i++) {
        newMatrix[i] = new int[this->width];
    }
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            newMatrix[j][i] = this->matrix[i][j];
        }
    }
    this->matrix = newMatrix;
    int bufor = this->height;
    this->height = this->width;
    this->width = bufor;
}

void Matrix::saveToFile(string name) {
    ofstream file(name.c_str());

    if (file.is_open()) {
        file << this->width << endl;
        file << this->height << endl;
        file << this->getMatrix();
    }

    file.close();
}