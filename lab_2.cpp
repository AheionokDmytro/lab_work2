# include <iostream>
# include <cmath>
# include <iomanip>

using namespace std;

void checkValidInput() 
{
    if (cin.fail()) //if the last cin command failed
    {
        throw "Incorrect input";
    }
}

void checkValidParams(double a, double b, double h, int n)
{
    if ( n < 2 || n != floor(n) || h <= 0 || a > b)
    {
        throw "Input correct data";
    }
}

double calculate(double x, int n)
{
    double y = 0;
    if (x < 0)
    {
        for (int i=1; i!=n; i++)
        {
            int sum = 0;
            for (int j=1; j<=n; j++)
            {
                sum += (x-i+j);
            }
            
            y += sum;
        }   
    }
    else
    {
        for (int i=1; i!=n; i++)
        {
            y += x/i;
        }
    }
    return y;
}
    

int main(){
    try
    {
        double a;
        double b;
        double h;
        int n;
        cout << "Enter a: ";
        cin >> a;
        checkValidInput();
        cout << "Enter b: ";
        cin >> b;
        checkValidInput();
        cout << "Enter h: ";
        cin >> h;
        checkValidInput();
        cout << "Enter n: ";
        cin >> n;
        checkValidInput();
        checkValidParams(a, b, h, n);
    

        for (double x=a; x<=b; x+=h)
        {
            double y = calculate(x, n);
            cout << std::fixed << std::setprecision(5)<< "For x = " << x << ", y = " << y << endl;    
        }
    }
    catch (const char* ex)
    {
        cout << ex << endl;
        return -1;
    }
    catch (...){
        cout << "Unknown error" << endl;
        return -2;
    }
    return 0;
}
