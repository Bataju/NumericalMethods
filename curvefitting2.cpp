//exponential
#include<iostream>
#include<cmath>
using namespace std;

class Coordinate
{
    public:
        float x, y;
};

class CurveFitting
{
    private:
        int n;
        Coordinate *c;
        float sumx, sumY, sumxY, sumx2, del, del1, del2, A, b;
    public:
        CurveFitting()
        {
            sumx = sumY = sumxY = sumx2 = 0;
            cout<<"Enter number of points: ";
            cin>>n;
            c = new Coordinate[n];
        }
        void getData()
        {
            for(int i=0; i<n; i++)
            {
                cout<<"Enter x"<<i<<": ";
                cin>>c[i].x;
                cout<<"Enter y"<<i<<": ";
                cin>>c[i].y;
                sumx += c[i].x;
                sumY += log(c[i].y);
                sumxY += c[i].x * log(c[i].y);
                sumx2 += c[i].x * c[i].x;
            }
            del = n*sumx2 - sumx * sumx;
            del1 = sumY * sumx2 - sumx *sumxY;
            del2 = n*sumxY - sumx*sumY;
        }
        void displayResult()
        {
            A = del1/del;
            b = del2/ del;
            cout<<"The equation is: y = "<<exp(A)<<" e ^ ("<<b<<"x)"<<endl;
        }
        ~CurveFitting()
        {
            delete[] c;
        }
};

int main()
{
    CurveFitting c;
    c.getData();
    c.displayResult();
    return 0;
}