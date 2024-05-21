// AIM : Write a program for developing a matrix class which can handle integer matrices of different dimensions. Also overload the operator for addition, multiplication and comparison of matrices

#include <iostream>
using namespace std;

class Matrix {
    private:
        int rows, columns;
        int** data;
    public:
        // constructor to initialise a matrix of specified rows and columns 
        Matrix(int row_count, int column_count) {
            rows = row_count;
            columns = column_count;

            // alloc mem for rows
            data = new int*[rows];

            // alloc mem for columns
            for (int i = 0; i < rows; i++) {
                data[i] = new int[columns];
            }
            cout << "successfully created a " << rows << " x " << columns << " matrix" << endl; 
        }

        // copy constructor
        Matrix(const Matrix& other) {
            rows = other.rows;
            columns = other.columns;

            // alloc mem for rows
            data = new int*[rows];

            // alloc mem for columns and copy data
            for (int i = 0; i < rows; i++) {
                data[i] = new int[columns];
                for (int j = 0; j < columns; j++) {
                    data[i][j] = other.data[i][j];
                }
            }
        }

        // define method to display the matrix
        void displayMatrix(void) const {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++) {
                    cout << data[i][j] << "  ";
                }
                cout << endl;
            }
            cout << endl;
        }

        // define method to input all members for matrix
        void populateMatrix(void) {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++) {
                    int value;
                    cout << "enter data for (" << i << ", " << j << ") : ";
                    cin >> value;
                    data[i][j] = value;
                }
            }
            cout << "populated matrix with specified values" << endl;
        }

        // OPERATOR OVERLOADING
        // addition
        Matrix operator+(Matrix &mat1) const {
            // check if matrices are of same dimensions, else, addition cant be performed

            if (rows != mat1.rows || columns != mat1.columns) {
                cout << "ERROR : cannot add matrices with different dimensions" << endl;
                return Matrix(0,0);
            } else {
                Matrix result(mat1.rows, mat1.columns);
                for (int i = 0; i < mat1.rows; i++) {
                    for (int j = 0; j < mat1.columns; j++) {
                        result.data[i][j] = data[i][j] + mat1.data[i][j];
                    }
                }
                return result;
            }
        }

        Matrix operator=(Matrix &mat1) const {
            Matrix result(rows, columns);
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++) {
                    result.data[i][j] = mat1.data[i][j];
                }
            }
            return result;
        }

        // multiplication
        Matrix operator*(Matrix &mat1) const {
            // check if columns of first matrix are equal to rows of second matrix
            if (columns == mat1.rows) {
                // if A = MxN
                // and B = PxQ
                // C = A*B = MxQ
                Matrix result(rows, mat1.columns);
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < mat1.columns; j++) {
                        result.data[i][j] = 0;
                        for (int k = 0; k < columns; k++) {
                            result.data[i][j] += data[i][k] * mat1.data[k][j];
                        }
                    }
                }
                return result;
            } else {
                cout << "ERROR : cannot multiply matrices MxN and PxQ if N != P" << endl;
                // this keyword returns the original matrix back
                return Matrix(0, 0);
            }
        }

        bool operator==(Matrix &mat) const {
            if (rows != mat.rows || columns != mat.columns) {
                return false;
            } else {
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < columns; j++) {
                        if (data[i][j] != mat.data[i][j])
                        {
                            return false;
                        }
                    }
                }
                return true;
            }
        }

        // destructor
        ~Matrix() {
            for (int i = 0; i < rows; i++) {
                delete[] data[i];
            }
            delete[] data;
        }
};

int main() {
    Matrix m1(3, 2), m2(2, 2), m3(2, 2), m4(2, 2);

    cout << "matrix 1" << endl;
    m1.populateMatrix();
    m1.displayMatrix();

    cout << "matrix 2" << endl;
    m2.populateMatrix();
    m2.displayMatrix();

    cout << "matrix 3" << endl;
    m3.populateMatrix();
    m3.displayMatrix();

    cout << "matrix 4" << endl;
    m4.populateMatrix();
    m4.displayMatrix();

    cout << "matrix 1 * matrix 2 : " << endl;
    Matrix result = m1 * m2;
    result.displayMatrix();

    cout << "matrix 2 * matrix 3 : " << endl;
    Matrix result2 = m2 * m3;
    result2.displayMatrix();

    cout << "matrix 2 + matrix 3 : " << endl;
    Matrix result3 = m2 + m3;
    result3.displayMatrix();

    cout << "comparing matrices 2 and 4" << endl;
    if (m2 == m4) {
        cout << "matrices are equal" << endl;
    } else {
        cout << "matrices are unequal" << endl;
    }

    cout << "comparing matrices 2 and 3" << endl;
    if (m2 == m3) {
        cout << "matrices are equal" << endl;
    } else {
        cout << "matrices are unequal" << endl;
    }

    return 0;
}