#include<iostream>
using namespace std;

class Interpolation
{
    private:
        int n;
        float* xArray;
        float* yArray;
        float xp;
    public:
        Interpolation()
        {
            cout<<"Enter the number of data points: ";
            cin>>n;
            xArray = new float[n];
            yArray = new float[n];
        }
        void getPoints()
        {
            cout<<"Enter the x and y values"<<endl;
            for(int i =0; i<n; i++)
            {
                cout<<"x["<<i<<"] and y["<<i<<"]: ";
                cin>>xArray[i]>>yArray[i];
            }
            cout<<endl<<"Enter xp(interpolating data): ";
            cin>>xp;
        }
        void interpolateAndDisplay()
        {
            float sum = 0;
            for(int i=0; i<n; i++)
            {
                float product = 1;
                for(int j=0; j<n; j++)
                {
                    if(i!=j)
                        product *= (xp-xArray[j])/(xArray[i]-xArray[j]);
                }
                sum += product * yArray[i];
            }
            cout<<"xp = "<<xp<<endl;
            cout<<"yp = "<<sum<<endl;
        }
        ~Interpolation()
        {
            delete []xArray;
            delete []yArray;
        }
};

int main()
{
    Interpolation i;
    i.getPoints();
    i.interpolateAndDisplay();
    return 0;
}
