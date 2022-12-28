#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

class NewtonRaphson
{
    private:
        float x0;
        float xn;
        float error;
    public:
        float function(float x)
        {
            //return (5*pow(x, 3)+6);
            //return(sin(x)+x*cos(x));
            //return (pow(x, 2)+3);
            //return (x*(1-x)); //at initial guess 0.5 maxima
            //return (1-pow(x, 2)); //at 0 derivative 0 so error
            return (exp(x)-6);
            //return (log(pow(x, 3))-5);
        }
        float derivative(float x)
        {
            //return (15*pow(x, 2));
            //return(cos(x)-x*sin(x)+cos(x));
            //return(2*x);
            //return(1-2*x);
            //return(-2*x);
            return (exp(x));
            //return(3/x);
        }
        void getInitialGuess()
        {
            cout<<"Enter initial guess x0: ";
            cin>>x0;
        }
        void solve()
        {
            int count=0;
            error=0.00005;
            while(fabs(function(x0))>=error)
            {
                count++;
                if(count==500)
                {
                    cout<<"No solution found."<<endl;
                    exit(0);
                }
                if(fabs(derivative(x0))<=error)
                {
                    cout<<"Error"<<endl;
                    exit(0);
                }
                xn = x0 - (function(x0)/derivative(x0));
                x0=xn;
            }
            cout<<"SOLUTION : "<<xn<<endl;
        }
};

int main()
{
    NewtonRaphson n;
    n.getInitialGuess();
    n.solve();
    return 0;
}
