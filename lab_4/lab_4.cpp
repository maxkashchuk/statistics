#include <iostream>
#include <vector>
#include <iomanip>
#include<cmath>

using namespace std;

double mathematical_probability_indicator = 0, dyspersion_indicator = 0;
double mathematical_probability_normal = 0, dyspersion_normal = 0;

double functionInterval(double x)
{
    if (x <= 2)
    {
        return (((x / 4.0) * (-1.0)) + 0.5);
    }
    else if (x > 2 && x <= 4)
    {
        return (((x / 8.0) * (-1.0)) + 0.5);
    }
    else
    {
        return (((x / 8.0) * (-1.0)) + 0.75);
    }
    //return (((x / 4.0) * (-1.0)) + 0.5) + (((x / 8.0) * (-1.0)) + 0.5) + (((x / 8.0) * (-1.0)) + 0.75);
}

void outputXNeyman(vector<double> X)
{
    double intervals[6][2] = { { 0, 1 }, { 1, 2 }, { 2, 3 }, { 3, 4 }, { 4, 5 }, { 5, 6 } };
    double intervalsCounter[6] = { 0, 0, 0, 0, 0, 0 };
    for (int i = 0; i < X.size(); i++)
    {
        for (int j = 0; j < sizeof(intervals) / sizeof(intervals[0]); j++)
        {
            if (X[i] >= intervals[j][0] && X[i] < intervals[j][1])
            {
                intervalsCounter[j]++;
            }
        }
    }

    cout << "Values interval:" << endl
        << "[0, 1)" << setw(10) << "[1, 2)" << setw(10) << "[2, 3)" << setw(10)
        << "[3, 4)" << setw(10) << "[4, 5)" << setw(10) << "[5, 6)" << endl;

    for (int i = 0; i < sizeof(intervalsCounter) / sizeof(double); i++)
    {
        cout << "  " << intervalsCounter[i] / X.size() << setw(8);
    }
}

void outputXIndicator(vector<double> X)
{
    double intervals[6][2] = { {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6} };
    double intervalsCounter[6] = { 0, 0, 0, 0, 0, 0 };
    for (int i = 0; i < X.size(); i++)
    {
        for (int j = 0; j < sizeof(intervals) / sizeof(intervals[0]); j++)
        {
            if (X[i] >= intervals[j][0] && X[i] < intervals[j][1])
            {
                intervalsCounter[j]++;
            }
        }
    }

    cout << "Values interval:" << endl
        << "[0, 1)" << setw(10) << "[1, 2)" << setw(10) << "[2, 3)" << setw(10)
        << "[3, 4)" << setw(10) << "[4, 5)" << setw(10) << "[5, 6)" << endl;

    for (int i = 0; i < sizeof(intervalsCounter) / sizeof(double); i++)
    {
        cout << "  " << intervalsCounter[i] << setw(8);
    }
}

void outputXNormal(vector<double> X)
{
    double intervals[7][2] = { {0, 6}, {6, 8}, {8, 10}, {10, 12}, {12, 14}, {14, 16}, {16, 18} };
    double intervalsCounter[7] = { 0, 0, 0, 0, 0, 0, 0 };
    for (int i = 0; i < X.size(); i++)
    {
        for (int j = 0; j < sizeof(intervals) / sizeof(intervals[0]); j++)
        {
            if (X[i] >= intervals[j][0] && X[i] < intervals[j][1])
            {
                intervalsCounter[j]++;
            }
        }
    }

    cout << "Values interval:" << endl
        << "[0, 6)" << setw(10) << "[6, 8)" << setw(10) << "[8, 10)" << setw(10)
        << "[10, 12)" << setw(10) << "[12, 14)" << setw(10) << "[14, 16)" << setw(10) << "[16, 18)" << endl;

    for (int i = 0; i < sizeof(intervalsCounter) / sizeof(double); i++)
    {
        cout << "  " << intervalsCounter[i] << setw(8);
    }
}

vector<double> modellingNeyman(int arrX_size)
{
    srand(time(0));

    vector<double> arrX;

    double r1, r2, x, teta, temp;

    while (arrX.size() != arrX_size)
    {
        r1 = ((double)rand()) / RAND_MAX;
        r2 = ((double)rand()) / RAND_MAX;
        x = 0 + r1 * (6 - 0);
        if (x <= 6)
        {
            teta = r2 * 0.5;
        }
        else
        {
            teta = r2 * 0.25;
        }
        temp = functionInterval(x);
        if (teta <= temp)
        {
            arrX.push_back(x);
            //arrX.insert(arrX.begin(), x);
        }
    }

    return arrX;
}

vector<double> indicatorLaw(int arrX_size, double lambda)
{
    vector<double> arrX;

    double r, x, temp = 0;

    while (arrX.size() != arrX_size)
    {
        r = ((double)rand()) / RAND_MAX;
        x = (log(r) * (-1)) / lambda;
        mathematical_probability_indicator += x * r;
        temp += x * x * r;
        arrX.insert(arrX.begin(), x);
    }

    dyspersion_indicator = (mathematical_probability_indicator * mathematical_probability_indicator) - temp;

    return arrX;
}

vector<double> normalLaw(int arrX_size, double m, double sigma)
{
    vector<double> arrX;

    double r_sum = 0, x, temp = 0;

    while (arrX.size() != arrX_size)
    {
        for (int i = 0; i < 12; i++)
        {
            r_sum += ((double)rand()) / RAND_MAX;
        }
        x = m + sigma * (r_sum - 6);
        mathematical_probability_normal += x;
        temp += x * x;
        arrX.insert(arrX.begin(), x);
        r_sum = 0;
    }

    dyspersion_normal = (mathematical_probability_normal * mathematical_probability_normal) - temp;

    return arrX;
}

int main()
{

    vector<double> X;
    double lambda = (double)12 / 10;
    double m = 12;
    double sigma = 12 % 5;
    cout << "Neyman method: " << endl << endl;
    cout << "For 100 values: " << endl;
    X = modellingNeyman(100);
    outputXNeyman(X);
    cout << endl << endl;
    cout << "For 1000 values: " << endl;
    X = modellingNeyman(1000);
    outputXNeyman(X);
    cout << endl << endl << endl << endl;
    cout << "Indicator Law: " << endl << endl;
    cout << "For 100 values: " << endl;
    X = indicatorLaw(100, lambda);
    outputXIndicator(X);
    cout << endl << "Mathematical expectation calculated: " << mathematical_probability_indicator << endl;
    cout << "Dyspersion calculated: " << dyspersion_indicator << endl;
    cout << endl << endl;
    cout << "For 1000 values: " << endl;
    X = indicatorLaw(1000, lambda);
    outputXIndicator(X);
    cout << endl << "Mathematical expectation calculated: " << mathematical_probability_indicator << endl;
    cout << "Dyspersion calculated: " << dyspersion_indicator << endl;
    cout << endl << endl;
    cout << "Mathematical expectation theoretical: " << (double)1 / lambda << endl;
    cout << "Dyspersion theoretical: " << (double)1 / (lambda * lambda) << endl;
    cout << endl << endl << endl << endl;
    cout << "Normal Law: " << endl << endl;
    cout << "For 100 values: " << endl;
    X = normalLaw(100, m, sigma);
    outputXNormal(X);
    cout << endl << "Mathematical expectation calculated: " << mathematical_probability_indicator << endl;
    cout << "Dyspersion calculated: " << dyspersion_indicator << endl;
    cout << endl << endl;
    cout << "For 1000 values: " << endl;
    X = normalLaw(1000, m, sigma);
    outputXNormal(X);
    cout << endl << "Mathematical expectation calculated: " << mathematical_probability_normal << endl;
    cout << "Dyspersion calculated: " << dyspersion_normal << endl;
    cout << endl << endl;
    cout << "Mathematical expectation theoretical: " << m << endl;
    cout << "Dyspersion theoretical: " << sigma * sigma << endl;
}