#include <iostream>
#include<iomanip>
using namespace std;

class Integration
{
private:
    int n;
    float h;
    float x0, xn;
    float *yArray;

public:
    Integration()
    {
        cout << "Enter x0 and xn: ";
        cin >> x0 >> xn;
        cout << "Enter the number of intervals: ";
        cin >> n;
        h = (xn - x0) / n;
        yArray = new float[n + 1];
    }
    void getYvalues()
    {
        cout << "Enter the functional values at different values of x" << endl;
        for (int i = 0; i <= n; i++)
        {
            cout << "x" << i << " = " <<setw(6)<< x0 << " y" << i << " = ";
            cin >> yArray[i];
            x0 += h;
        }
    }
    void solveAndDisplay()
    {
        float sum1, sum2, sum3, sum4, sum5, sum6, resultTrapezoidal, result1by8, result3by8;
        sum1 = sum2 = sum3 = sum4 = sum5 = sum6 = 0;
        sum1 = yArray[0] + yArray[n];
        for (int i = 1; i <= n - 1; i++)
        {
            sum2 += yArray[i];
            if (i % 2 == 0)
                sum3 += yArray[i];
            else
                sum4 += yArray[i];
            if (i % 3 == 0)
                sum5 += yArray[i];
            else
                sum6 += yArray[i];
        }
        //trapezoidal
        resultTrapezoidal = (h/2) * (sum1 + 2 * sum2);
        //1/8
        result1by8 = (h/3) * (sum1 + 4 * sum4 + 2*sum3);
        //3/8
        result3by8 = (3*h/8) * (sum1 + 3 * sum6 + 2*sum5);
        //display
        cout<<"Trapezoidal: "<<resultTrapezoidal<<endl<<"Simpson's 1/8: "<<result1by8
            <<endl<<"Simpson's 3/8: "<<result3by8<<endl;
    }
    ~Integration()
    {
        delete[] yArray;
    }
};

int main()
{
    Integration i;
    i.getYvalues();
    i.solveAndDisplay();
    return 0;
}