//linear
#include<iostream>
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
        float sumx, sumy, sumxy, sumx2, del, del1, del2, a, b;
    public:
        CurveFitting()
        {
            sumx = sumy = sumxy = sumx2 = 0;
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
                sumy += c[i].y;
                sumxy += c[i].x * c[i].y;
                sumx2 += c[i].x * c[i].x;
            }
        }
        void calculate()
        {
            del = n*sumx2 - sumx * sumx;
            del1 = sumy * sumx2 - sumx *sumxy;
            del2 = n*sumxy - sumx*sumy;
            a = del1/del;
            b = del2/ del;
        }
        void displayResult()
        {
            cout<<"The equation is: y = "<<a<<" + "<<b<<"x"<<endl;
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
    c.calculate();
    c.displayResult();
    return 0;
}