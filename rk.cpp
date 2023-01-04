#include<iostream>
#include<cmath>
using namespace std;

class RK
{
    private:
        float x0_global, y0_global, xn_global, h_global;
    public:
        void getData()
        {
            cout<<"Enter x0: ";
            cin>>x0_global;
            cout<<"Enter y0: ";
            cin>>y0_global;
            cout<<"Enter step size (h): ";
            cin>>h_global;
            cout<<"Enter xn(where yn is to be evaluated): ";
            cin>>xn_global;
        }
        float slope(float x, float y)
        {
            return 3*x*x*y;
        }
        void solveRk1()
        {
            float x0=x0_global, y0 = y0_global, h = h_global, xn = xn_global, yn;
            cout<<"Euler's method.."<<endl;
            while(x0 < (xn+h))
            {
                cout<<x0<<"\t"<<y0<<endl;
                yn = y0 + h * slope(x0, y0);
                x0 += h;
                y0 = yn;
            }
        }
        void solveRk2()
        {
             float x0=x0_global, y0 = y0_global, h = h_global, xn = xn_global, yn;
            float k1, k2, k;
            cout<<"RK 2.."<<endl;
            while(x0 < (xn+h))
            {
                cout<<x0<<"\t"<<y0<<endl;
                k1 = h * slope(x0, y0);
                k2 = h*slope(x0+h, y0+k1);
                k=(k1+k2)/2;
                yn = y0 +k;
                x0 += h;
                y0 = yn;
            }
        }
        void solveRk4()
        {
            float x0=x0_global, y0 = y0_global, h = h_global, xn = xn_global, yn;
            float k1, k2, k3, k4, k;
            cout<<"RK 4.."<<endl;
            while(x0 < (xn+h))
            {
                cout<<x0<<"\t"<<y0<<endl;
                k1 = h * slope(x0, y0);
                k2 = h* slope(x0 + h/2, y0+k1/2);
                k3=h*slope(x0+h/2, y0+k2/2);
                k4 = h*slope(x0+h, y0+k3);
                k=(k1+2*k2+2*k3+k4)/6;
                yn = y0+k;
                x0+=h;
                y0 = yn;
            }
        }
};

int main()
{
    RK r;
    r.getData();
    r.solveRk1();
    r.solveRk2();
    r.solveRk4();
    return 0;
}