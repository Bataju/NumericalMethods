#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

class Matrix
{
private:
    int n;
    float **matrix;
    float **result;

public:
    Matrix()
    {
        cout << "Enter the order of square matrix: ";
        cin >> n;
        matrix = new float *[n];
        result = new float *[n];
        for (int i = 0; i < n; i++)
        {
            matrix[i] = new float[n];
            result[i] = new float[n];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    result[i][j] = 1;
                else
                    result[i][j] = 0;
            }
        }
    }
    void getCoefficients()
    {
        cout << "Enter the coefficients" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << "a" << i + 1 << j + 1 << ": ";
                cin >> matrix[i][j];
            }
        }
    }
    void findInverse()
    {
        for (int j = 0; j < n; j++)
        {
            if (fabs(matrix[j][j]) <= 0.00005)
            {
                cout << "Error" << endl;
                exit(0);
            }
            for (int i = 0; i < n; i++)
            {
                if (i != j)
                {
                    float temp = matrix[i][j] / matrix[j][j];
                    for (int k = 0; k < n; k++)
                    {
                        matrix[i][k] = matrix[i][k] - temp * matrix[j][k];
                        result[i][k] = result[i][k] - temp * result[j][k];
                    }
                }
                else
                {
                    float temp = matrix[j][j];
                    for (int k = 0; k < n; k++)
                    {
                        matrix[i][k] = matrix[i][k] / temp;
                        result[i][k] = result[i][k] / temp;
                    }
                }
            }
        }
    }
    void displayInverse()
    {
        cout << "Inverse" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << result[i][j] << "\t";
            }
            cout << endl;
        }
    }
    ~Matrix()
    {
        for (int i = 0; i < n; i++)
        {
            delete[] matrix[i];
            delete[] result[i];
        }
        delete[] matrix;
        delete[] result;
    }
};

int main()
{
    Matrix m;
    m.getCoefficients();
    m.findInverse();
    m.displayInverse();
    return 0;
}