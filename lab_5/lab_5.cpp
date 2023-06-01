#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct AFDiagramFnxValue
{
    double Fnx;
    vector<int> X_values;
};

struct Interval
{
    double start_value;
    double end_value;
};

struct HistogramValue
{
    Interval interval;
    vector<int> X_values;
    double Nm;
    double relative_frequencey;
};

void set(vector<int> &X)
{
    srand(time(NULL));
    for (int i = 0; i < X.size(); i++)
    {
        X[i] = 1 + (rand() % 100);
    }
}

void variationSeries(vector<int> X, vector<int> &VSX)
{
    int temp;
    VSX = X;
    for (int i = 0; i < VSX.size(); i++)
    {
        for (int j = 0; j < VSX.size(); j++)
        {
            if (VSX[i] < VSX[j])
            {
                temp = VSX[i];
                VSX[i] = VSX[j];
                VSX[j] = temp;
            }
        }
    }
}

void outputVSX(vector<int> VSX)
{
    for (int i = 0; i < VSX.size(); i++)
    {
        if (i != VSX.size() - 1)
        {
            cout << VSX[i] << " < ";
        }
        else
        {
            cout << VSX[i];
        }
        
    }
    cout << endl << endl;
}

void generateFnx(vector<AFDiagramFnxValue>&Fnx, int VSX_size)
{
    Fnx.resize(VSX_size + 1);
    Fnx[0].Fnx = 0;
    for (int i = 1; i < Fnx.size(); i++)
    {
        Fnx[i].Fnx = (double)i / (Fnx.size() - 1);
    }
}

void outputFnx(vector<AFDiagramFnxValue>& Fnx)
{
    cout << endl << endl << "Fnx values: " << endl << endl;
    for (int i = 0; i < Fnx.size(); i++)
    {
        cout << Fnx[i].Fnx << endl;
    }
}

void outputAFD(vector<AFDiagramFnxValue> AFDFnx)
{
    for (int i = 0; i < AFDFnx.size(); i++)
    {
        AFDFnx[i].Fnx;
        cout << "Fnx value: " << AFDFnx[i].Fnx << "; Attached values: ";
        for (int j = 0; j < AFDFnx[i].X_values.size(); j++)
        {
            if (j != AFDFnx[i].X_values.size() - 1)
            {
                cout << AFDFnx[i].X_values[j] << ", ";
            }
            else
            {
                cout << AFDFnx[i].X_values[j];
            }
        }
        cout << endl << endl;
    }
}

void accumulatedFrequencies(vector<int> VSX)
{
    vector<AFDiagramFnxValue> AFDFnx;
    int temp = 1;
    generateFnx(AFDFnx, VSX.size());
    outputFnx(AFDFnx);
    for (int i = 0; i < VSX.size(); i++)
    {
        for (int j = temp; j <= 100; j++)
        {
            if (VSX[i] <= j)
            {
                temp = j;
                break;
            }
            AFDFnx[i].X_values.push_back(j);
        }
    }
    if (temp != 100)
    {
        for (int i = temp; i <= 100; i++)
        {
            AFDFnx[VSX.size()].X_values.push_back(i);
        }
    }
    cout << endl << endl << "Table values: " << endl << endl;
    outputAFD(AFDFnx);
}

void IntervalSet(vector<HistogramValue> &Histogram, vector<int> VSX, int delta_x, double middle)
{
    double counter, sum;
    HistogramValue value;
    value.interval.end_value = middle + ((double)delta_x / 2);
    value.interval.start_value = middle - ((double)delta_x / 2);
    Histogram.push_back(value);
    counter = Histogram[0].interval.start_value;
    while (counter - delta_x >= 0)
    {
        HistogramValue insert_front;
        insert_front.interval.end_value = Histogram[0].interval.start_value;
        insert_front.interval.start_value = Histogram[0].interval.start_value - delta_x;
        Histogram.insert(Histogram.begin(), insert_front);
        counter -= delta_x;
    }
    counter = Histogram[Histogram.size() - 1].interval.end_value;
    while (counter + delta_x <= 100)
    {
        HistogramValue insert_front;
        insert_front.interval.start_value = Histogram[Histogram.size() - 1].interval.end_value;
        insert_front.interval.end_value = Histogram[Histogram.size() - 1].interval.end_value + delta_x;
        Histogram.push_back(insert_front);
        counter += delta_x;
    }
    for (int i = 0; i < Histogram.size(); i++)
    {
        sum = 0;
        for (int j = 0; j < VSX.size(); j++)
        {
            if (VSX[j] >= Histogram[i].interval.start_value && VSX[j] < Histogram[i].interval.end_value)
            {
                Histogram[i].X_values.push_back(VSX[j]);
                sum += VSX[j];
            }
        }
        Histogram[i].Nm = sum;
        Histogram[i].relative_frequencey = sum / VSX.size();
    }
}

void sampleHistogram(vector<int> VSX, vector<HistogramValue> &Histogram)
{
    double res = 1 + 3.2 * log(VSX.size());
    int K = ceil(res), delta_x;
    res = (VSX[0] + VSX[VSX.size() - 1]) / 2;
    delta_x = ceil(((double)(VSX[0] + VSX[VSX.size() - 1]) / K));
    IntervalSet(Histogram, VSX, delta_x, res);
}

void outputHistogram(vector<HistogramValue> Histogram)
{
    for (int i = 0; i < Histogram.size() - 1; i++)
    {
        cout << "Interval [" << ceil(Histogram[i].interval.start_value * 100.0) / 100.0 << "-" <<
            ceil(Histogram[i].interval.end_value * 100.0) / 100.0 << "] with value " << Histogram[i].relative_frequencey << endl;
    }
}

double mathematicalProbability(vector<int> VSX)
{
    int sum = 0;
    double N = VSX.size();
    for (int i = 0; i < VSX.size() - 1; i++)
    {
        sum += VSX[i];
    }
    return ((double)1 / N) * sum;
}

double dyspersion(vector<int> VSX)
{
    int sum = 0;
    double N = VSX.size(), avg;
    for (int i = 0; i < VSX.size() - 1; i++)
    {
        sum += VSX[i];
    }
    avg = (double)sum / VSX.size();
    sum = 0;
    for (int i = 0; i < VSX.size() - 1; i++)
    {
        sum += pow((double)VSX[i] - avg, 2);
    }
    return ((double)1 / (N - 1)) * sum;
}

double squareDeviation(vector<int> VSX)
{
    return sqrt(dyspersion(VSX));
}

double correlationCoefficient(vector<int> X1, vector<int> Y1)
{
    int sum = 0, size;
    double avgX, avgY;
    for (int i = 0; i < X1.size() - 1; i++)
    {
        sum += X1[i];
    }
    avgX = (double)sum / X1.size();
    sum = 0;
    for (int i = 0; i < Y1.size() - 1; i++)
    {
        sum += Y1[i];
    }
    avgY = (double)sum / Y1.size();
    sum = 0;
    size = (X1.size() > Y1.size()) ? X1.size() : Y1.size();
    for (int i = 0; i < size - 1; i++)
    {
        sum += ((X1[i] - avgX) * (Y1[i] - avgY));
    }
    return ((double)1 / ((size - 1) * squareDeviation(X1) * squareDeviation(Y1))) * sum;
}

int main()
{
    int numVal;
    vector<int> X, VSX, X1, Y1, x, y;
    vector<HistogramValue> Histogram, HistogramX1, HistogramY1;
    cout << "Enter number of values to be generated: ";
    cin >> numVal;
    cout << endl << endl;
    X.resize(numVal);
    VSX.resize(numVal);
    set(X);
    variationSeries(X, VSX);
    outputVSX(VSX);
    accumulatedFrequencies(VSX);
    sampleHistogram(VSX, Histogram);
    outputHistogram(Histogram);

    cout << endl << endl << "Mathematical probability: " << mathematicalProbability(VSX);

    cout << endl << endl << "Dyspersion: " << dyspersion(VSX);

    cout << endl << endl << "Square deviation: " << squareDeviation(VSX) << endl << endl << endl;

    srand(time(NULL));

    cout << "Enter number of elements in sample: ";
    cin >> numVal;
    X1.resize(numVal);
    Y1.resize(numVal);
    cout << endl;
   
    for (int i = 0; i < X1.size() - 1; i++)
    {
        X1[i] = 1 + (rand() % 100);
    }

    for (int i = 0; i < Y1.size() - 1; i++)
    {
        Y1[i] = 1 + (rand() % 100);
    }

    variationSeries(X1, X1);
    x = X1;

    variationSeries(Y1, Y1);
    y = Y1;

    cout << "First sample X1: ";
    outputVSX(X1);
    cout << endl;
    cout << "Second sample Y1: ";
    outputVSX(Y1);
    cout << endl;

    sampleHistogram(X1, HistogramX1);
    sampleHistogram(Y1, HistogramY1);
    cout << endl << endl << "Histogram X1: " << endl << endl;
    outputHistogram(HistogramX1);
    cout << endl << endl << "Histogram Y1: " << endl << endl;
    outputHistogram(HistogramY1);
    cout << endl << endl << "Correlation coefficient: " << correlationCoefficient(x, y) << endl << endl;
}