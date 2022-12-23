#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

class Secant
{
    private:
        float a;
        float b;
        float c;
    public:
        float function(float x)
        {
            return (5*pow(x, 3)+6);
            //return (x*sin(x));
        }
        void getInitialGuesses()
        {
            cout<<"Enter a: ";
            cin>>a;
            cout<<"Enter b: ";
            cin>>b;
        }
        void solve()
        {
            int count=0;
            float error = 0.00005;
            do
            {
                count++;
                if(count == 500)
                {
                    cout<<"No solution found."<<endl;
                    exit(0);
                }
                if(fabs(function(b)-function(a))<=error)
                {
                    cout<<"Error."<<endl;
                    exit(0);
                }
                c=(a*function(b)-b*function(a))/(function(b)-function(a));
                a=b;
                b=c;
            }while(fabs(function(c))>=error);
            cout<<"SOLUTION: "<<c<<endl;
        }
};

int main()
{
    Secant s;
    s.getInitialGuesses();
    s.solve();
    return 0;
}
