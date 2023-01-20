#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

class CurveFitting
{
    private:
        int n, d;
        float** matrix;
        float* result;
    public:
        CurveFitting()
        {
            cout<<"Enter the degree of polynomial: ";
            cin>>d;
            cout<<"Enter the number of points: ";
            cin>>n;
            if(n<=d)
            {
                cout<<"Number of points has to be greater than the degree of polynomial."<<endl;
                exit(0);
            }
            if(d<=0)
            {
                cout<<"The degree of polynomial has to be greater than zero."<<endl;
                exit(0);
            }
            matrix = new float* [d+1];
            for(int i=0; i<d+1; i++)
            {
                matrix[i] = new float[d+2];
            }
            result = new float[d+1];
        }
        void initializeMatrix()
        {
            for(int i=0; i<d+1; i++)
            {
                for(int j=0; j<d+2; j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        void getPoints()
        {
            initializeMatrix();
            float x, y;
            cout<<"Enter x and y"<<endl;
            for(int i=0; i<n; i++)
            {
                cout<<"x and y: ";
                cin>>x>>y;
                for(int i=0; i<d+1; i++)
                {
                    for(int j=0; j<d+1; j++)
                    {
                        matrix[i][j] = matrix[i][j] + pow(x, i+j);
                    }
                }
                for(int i=0; i<d+1; i++)
                {
                    matrix[i][d+1] = matrix[i][d+1] + pow(x, i)*y;
                }
            }
        }
        void solveJordan()
        {
            for(int j = 0; j<d+1; j++)//0 to d
            {
                if(fabs(matrix[j][j])<=0.00005)
                {
                    cout<<"Error"<<endl;
                    exit(0);
                }
                for(int i=0; i<d+1; i++)//0 to d
                {
                    if(i!=j)
                    {
                        float temp = matrix[i][j]/matrix[j][j];
                        for(int k=0; k<d+2; k++)//0 to d+1
                        {
                            matrix[i][k] = matrix[i][k] - temp * matrix[j][k];
                        }
                    }

                }
            }
            for(int i=0; i<d+1; i++)//0 to d
            {
                result[i] = matrix[i][d+1] / matrix[i][i];
            }
        }
        void display()
        {
            for(int i=0; i<d+1; i++)
            {
                cout<<result[i]<<"x^"<<i<<"+";
            }
        }
        ~CurveFitting()
        {
            for(int i=0; i<d+1; i++)
            {
                delete []matrix[i];
            }
            delete []matrix;
            delete []result;
        }
};

int main()
{
    CurveFitting c;
    c.getPoints();
    c.solveJordan();
    c.display();
    return 0;
}
