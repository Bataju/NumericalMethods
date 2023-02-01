#include<iostream>
#include<cmath>
using namespace std;

class PowerMethod
{
    private:
        int n;
        float e;
        float Zmaxormin;
        float Dmax;
        float** A;
        float* X;
        float* Z;
        float* D;
        float* Y;
    public:
        PowerMethod()
        {
            e = 0.00005;//tolerable error
            cout<<"Enter the order of square matrix: ";
            cin>>n;
            A = new float* [n];
            for(int i=0; i<n; i++)
            {
                A[i] = new float[n];
            }
            X = new float[n];
            Z = new float[n];
            Y = new float[n];
            D = new float[n];
        }
        void getData()
        {
            cout<<"Enter the matrix elements"<<endl;
            for(int i= 0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    cout<<"A["<<i<<"]["<<j<<"]: ";
                    cin>>A[i][j];
                }
            }
            cout<<"Enter the initial column vector "<<endl;
            for(int i=0; i<n; i++)
            {
                cout<<"X["<<i<<"]: ";
                cin>>X[i];
            }
        }
        void multiplyAandX(float** A, float* X, float* Z)
        {
            for(int i=0; i<n ;i++)
            {
                float sum = 0;
                for(int j=0; j<n; j++)
                {
                    sum += A[i][j] * X[j];
                }
                Z[i] = sum;
            }
        }
        void fillDifferenceVector(float* X, float* Y, float* D)
        {
            for(int i=0; i<n; i++)
            {
                D[i] = abs(Y[i]-X[i]);
            }
        }
        float findMax(float* D)
        {
            float max=0;
            for(int i=0; i<n; i++)
            {
                if(abs(D[i])>max)
                    max = abs(D[i]);
            }
            return max;
        }
        float findMaxAbsolutevalue(float* vector)
        {
            float max=0;
            for(int i=0; i<n; i++)
            {
                if(abs(vector[i])>max)
                    max = vector[i];
            }
            return max;
        }
        float findMinAbsolutevalue(float* vector)
        {
            float min=vector[0];
            for(int i=0; i<n; i++)
            {
                if(abs(vector[i])<min)
                    min = vector[i];
            }
            return min;
        }
        void divideZByLargest(float* Z, float l, float* Y)
        {
            for(int i=0; i<n; i++)
            {
                Y[i] = Z[i] / l;
            }
        }
        void divideZBySmallest(float* Z, float s, float* Y)
        {
            for(int i=0; i<n; i++)
            {
                Y[i] = Z[i] / s;
            }
        }
        void copyVector(float* X, float* Y)
        {
            for(int i =0; i<n; i++)
            {
                X[i] = Y[i];
            }
        }
        void solveDividingByLargest()
        {
            do
            {
                multiplyAandX(A, X, Z);//z = x*y
                Zmaxormin = findMaxAbsolutevalue(Z);
                divideZByLargest(Z, Zmaxormin, Y);//y = z /zmax
                fillDifferenceVector(X, Y, D);//d = abs(y-x)
                Dmax = findMax(D);
                copyVector(X, Y);
            } while (Dmax>e);
        }   
        void solveDividingBySmallest()
        {
            do
            {
                multiplyAandX(A, X, Z);//z = x*y
                Zmaxormin = findMinAbsolutevalue(Z);
                divideZBySmallest(Z, Zmaxormin, Y);//Y = Z/Zmin
                fillDifferenceVector(X, Y, D);//d = abs(y-x)
                Dmax = findMax(D);
                copyVector(X, Y);
            } while (Dmax>e);
        }  
        void displayEigenValueAndVector()
        {
            cout<<"Eigen value: "<<Zmaxormin<<endl;
            cout<<"Eigen vector"<<endl;
            for(int i=0; i<n; i++)
            {
                cout<<X[i]<<endl;
            }
        }
        void displayNormalForm()
        {
            float k=0;
            for(int i=0 ; i<n; i++)
            {
                k+=X[i]*X[i];
            }
            k = sqrt(k);
            cout<<"In normal form"<<endl;
            for(int i=0; i<n; i++)
            {
                cout<<X[i]/k<<endl;
            }
        }
        ~PowerMethod()
        {
            for(int i=0; i<n; i++)
            {
                delete []A[i];
            }
            delete []A;
            delete []X;
            delete []Z;
            delete []Y;
            delete []D;
        }
};

int main()
{
    PowerMethod p;
    p.getData();
    //p.solveDividingByLargest();
    p.solveDividingBySmallest();
    p.displayEigenValueAndVector();
    p.displayNormalForm();
    return 0;
}
