// AIM : Write a program to design a class to represent a matrix. The class should have the functionality to insert and retrieve the elements of the matrix

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

        // define method to display the matrix
        void displayMatrix(void) {
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


        // define method to change a single value at a specified position
        void changeValue(int row_to_change, int col_to_change, int new_value) {
            if (row_to_change >= 0 && row_to_change < rows && col_to_change >= 0 && col_to_change < columns) {
                data[row_to_change][col_to_change] = new_value;
            } else {
                cout << "ERROR : invalid index" << endl;
            }
        }

        // define method to extract a single value from the matrix
        int getSingleValue(int row_for_val, int col_for_val) {
            if (row_for_val >= 0 && row_for_val < rows && col_for_val >= 0 && col_for_val < columns) {
                return data[row_for_val][col_for_val];
            } else {
                cout << "ERROR : invalid index" << endl;
                return -1;
            }
        }

        // destructor
        ~Matrix() {
            for (int i = 0; i < rows; i++) {
                delete[] data[i];
            }
            delete[] data;
            cout << "destructor called : cleared object data" << endl;
        }
};

int main() {
    Matrix m1(2, 3);

    // populate the matrix with specified values
    m1.populateMatrix();

    // display the generated matrix
    m1.displayMatrix();

    // change value for a single location
    m1.changeValue(1, 1, 101);
    m1.displayMatrix();

    // extract a single value from the matrix
    int a = m1.getSingleValue(1, 1);
    cout << "extracted value from matrix : " << a << endl;

    return 0;
}