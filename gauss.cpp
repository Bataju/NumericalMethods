#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

class Gauss
{
    private:
        int n;
        float** array;
        float* resultArray;
    public:
        Gauss()
        {
            cout<<"Enter the number of unknowns: ";
            cin>>n;
            array = new float* [n];
            for(int i=0; i<n;i++)
            {
                array[i] = new float[n+1];
            }
            resultArray = new float[n];
        }
        void getCoefficients()
        {
            cout<<"Enter the coefficients"<<endl;
            for(int i=0; i<n; i++)
            {
                for(int j=0;j<n+1; j++)
                {
                    cout<<"a"<<i+1<<j+1<<": ";
                    cin>>array[i][j];
                }
            }
        }
        void solveJordan()
        {
            //diagonalize
            for(int j = 0; j<n; j++)
            {
                if(fabs(array[j][j])<=0.00005)
                {
                    cout<<"Error"<<endl;
                    exit(0);
                }
                for(int i=0; i<n; i++)
                {
                    if(i!=j)
                    {
                        float temp = array[i][j]/array[j][j];
                        for(int k=0; k<n+1; k++)
                        {
                            array[i][k] = array[i][k] - temp * array[j][k];
                        }
                    }
                }
            }
            //results
            for(int i=0; i<n; i++)
            {
                resultArray[i] = array[i][n] / array[i][i];
            }
        }
        void solveElimination()
        {
            //uppertriangular
            for(int j = 0; j<n; j++)
            {
                if(fabs(array[j][j])<=0.00005)
                {
                    cout<<"Error"<<endl;
                    exit(0);
                }
                for(int i=j+1; i<n; i++)
                {
                    float temp = array[i][j]/array[j][j];
                    for(int k=0; k<n+1; k++)
                    {
                        array[i][k] = array[i][k] - temp * array[j][k];
                    }
                }
            }

            //back substitution
            resultArray[n-1] = array[n-1][n]/array[n-1][n-1];
            for(int i = n-2; i >= 0  ; i--)
            {
                float res=0;
                for(int j=i+1; j<=n-1; j++)
                {
                    res = res + array[i][j]*resultArray[j];
                }
                resultArray[i] = (array[i][n]-res)/array[i][i];
            }
        }
        void display()
        {
            for(int i=0; i<n; i++)
            {
                cout<<"x"<<i<<" = "<<resultArray[i]<<endl;
            }
        }
        ~Gauss()
        {
            for(int i=0; i<n; i++)
                delete []array[i];
            delete []array;
            delete []resultArray;
        }
};

int main()
{
    Gauss g;
    g.getCoefficients();
    g.solveJordan();
    //g.solveElimination();
    g.display();
    return 0;
}
