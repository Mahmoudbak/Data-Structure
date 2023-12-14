#include <iostream>
#include <cmath>
#include <string>
// #include "muParser.h"
#include <muParser.h>
using namespace std;
using namespace mu;
// trapezpoidal methods--->

double func(const string &value_x, double x)
{
    Parser parser;
    parser.DefineConst("e", 2.72);
    parser.DefineVar("x", &x);
    parser.SetExpr(value_x);
    return parser.Eval();
}

double trap(const string &value_x, double a, double b, int n)
{
    double h = (b - a) / (n - 1);
    double sum_fx = 0, equA = 0, x_value = 0, func_result, sum_fxx = 0, final = 0, sum_fx1 = 0;
    for (double i = 0; i <= n - 1; i++)
    {
        x_value = a + i * ((b - a) / (n - 1));
        sum_fx += func_result = func(value_x, x_value);
    }
    sum_fx1 = sum_fx - ((func(value_x, a)) + (func(value_x, b)));
    equA = (h / 2) * ((func(value_x, a)) + (func(value_x, b)));
    sum_fxx = (h / 2) * (2 * sum_fx1);
    final = equA + sum_fxx;
    return final;
}

double sim(const string &value_x, double a, double b, int n)
{
    double h = (b - a) / (n - 1);
    double sum_fx = 0, equA = 0, x_value = 0, func_result, sum_fxx = 0, final = 0, sum_fx1 = 0;
    for (double i = 0; i <= n - 1; i++)
    {
        x_value = a + i * ((b - a) / (n - 1));
        sum_fx += func_result = func(value_x, x_value);
    }
    if (n == 4)
    {
        sum_fx1 = sum_fx - ((func(value_x, a)) + (func(value_x, b)));
        equA = (3 * h / 8) * ((func(value_x, a)) + (func(value_x, b)));
        sum_fxx = (h / 2) * (3 * sum_fx1);
        final = equA + sum_fxx;
        //return final;
    }
    else if ((n >= 3 && n % 2 != 0))
    {
        double sum_fx = 0, equA = 0, x_value = 0, func_result, sum_fxx = 0, final = 0, sum_fx1 = 0;
        for (double i = 0; i <= n - 1; i++)
        {

            x_value = a + i * ((b - a) / (n - 1));
            sum_fx += func_result = func(value_x, x_value);
            double xx = sum_fx - ((func(value_x, a)) + (func(value_x, b)));
            sum_fx1 = sum_fx - ((func(value_x, a)) + (func(value_x, b)));
            equA = (h / 3) * ((func(value_x, a)) + (func(value_x, b)));
            sum_fxx = (h / 3) * (3 * sum_fx1);
            final = equA + sum_fxx;
           // return final;
        }
    }
    
}

int main()
{
    string string_fun;
    double a, b, n;

    cout << "Enter a mathematical expression: ";
    cin.clear();
    getline(cin, string_fun);

    cout << "plz enter the limiting integration frit a,scand b:\n";
    cin >> a;
    cin >> b;

    cout << "Enter number of space coulom (n): ";
    cin >> n;

    double result = trap(string_fun, a, b, n);
    // double result2=sim (string_fun ,a ,b, n);
    cout << "The integral of the function " << string_fun << " from " << a << " to " << b << " is: " << result << endl;
    // cout << "The integral of the function " << string_fun << " from " << a << " to " << b << " is: " << result2<< endl;

    cout << "x\tf(x)" << endl;
    for (int i = 0; i <= n - 1; i++)
    {
        double x_value = a + i * ((b - a) / (n - 1));
        double func_result = func(string_fun, x_value);
        cout << x_value << "\t" << func_result << endl;
    }

    return 0;
}
