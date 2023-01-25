#include<iostream>
using namespace std;
//y''=xy'+y

class RK4
{
    private:
        float x0, y0, z0, h, xn;
    public:
        void getData()
        {
            cout<<"Enter x0, y0 and z0: ";
            cin>>x0>>y0>>z0;
            cout<<"Enter the step size(h): ";
            cin>>h;
            cout<<"Enter xn: ";
            cin>>xn;
            //y(x0) = y0 and y'(x0) = z0 (z = y')
        }
        float funcf(float x, float y, float z)//dy/dx (z=dy/dx, z=y')
        {
            return z;
        }
        float funcg(float x, float y, float z)//dz/dx = x*z+y
        {
            //return (6*x+z*z)/-10;
            return 1+2*x*y-x*x*z;
        }
        void solveAndDisplay()
        {
            float k1, k2, k3, k4, l1, l2, l3, l4, k, l;
            for(x0; x0<=xn; x0 = x0+h)
            {
                cout<<x0<<"\t"<<y0<<"\t"<<z0<<endl;
                k1 = h*funcf(x0, y0, z0);
                l1 = h*funcg(x0, y0, z0);

                k2 = h*funcf(x0 + h/2, y0 + k1/2, z0+l1/2);
                l2 = h*funcg(x0+h/2, y0+k1/2, z0+l1/2);

                k3 = h*funcf(x0 + h/2, y0 + k2/2, z0+l2/2);
                l3 = h*funcg(x0+h/2, y0+k2/2, z0+l2/2);

                k4 = h*funcf(x0 + h, y0 + k3, z0+l3);
                l4 = h*funcg(x0+h, y0+k3, z0+l3);

                k = (k1 + 2*k2 + 2*k3 + k4)/6;
                l = (l1 + 2*l2 + 2*l3 + l4)/6;
                y0 += k;
                z0 += l;
            }
        }
};

int main()
{
    RK4 r;
    r.getData();
    r.solveAndDisplay();
    return 0;
}
