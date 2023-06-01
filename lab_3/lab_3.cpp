#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct descrete
{
    int value;
    double probability;
};

struct interval
{
    double first_value;
    double second_value;
};

struct divisionTable
{
    vector<int> X;
    vector<double> P;
    vector<interval> Interval;
};

struct frequencyTable
{
    vector<interval> Interval;
    vector<int> frequent_occasion;
    vector<double> relatively_frequent_occasion;
};

void inputNumGeneratedSequence(vector<double> &numbers)
{
    srand(time(NULL));
    for (int i = 0; i < numbers.size(); i++)
    {
        numbers[i] = (double)(rand() % 100 + 1) / 100;
    }
}

void printNumGeneratedSequence(vector<double> numbers)
{
    for (int i = 0; i < numbers.size(); i++)
    {
        cout << "Number generated with id " << i + 1 << " is " << numbers[i] << endl;
    }
}

void divisionTableInteravalSet(divisionTable& DT, int DT_size)
{
    DT.Interval.resize(DT_size);
    double previous = DT.P[0];
    DT.Interval[0].first_value = 0;
    DT.Interval[0].second_value = DT.P[0];
    for (int i = 1; i < DT_size - 1; i++)
    {
        DT.Interval[i].first_value = previous;
        DT.Interval[i].second_value = previous + DT.P[i];
        previous = DT.Interval[i].second_value;
    }
    DT.Interval[DT_size - 1].first_value = previous;
    DT.Interval[DT_size - 1].second_value = 1;
}

void divisionTableInteravalPrint(divisionTable& DT, int DT_size)
{
    for (int i = 0; i < DT_size; i++)
    {
        cout << "\n\n" << "Interval with value " << DT.X[i] << endl << "Interval first value: " << DT.Interval[i].first_value << endl;
        cout << "Interval second value: " << DT.Interval[i].second_value << endl;
    }
}

void inputDivisionTable(divisionTable &DT)
{
    int DT_size;
    cout << "Input division table size: ";
    cin >> DT_size;
    cout << endl;
    DT.P.resize(DT_size);
    DT.X.resize(DT_size);
    for (int i = 0; i < DT_size; i++)
    {
        cout << endl << endl << "Cell " << i + 1 << ", enter X value: ";
        cin >> DT.X[i];
        cout << endl << "Cell " << i + 1 << ", enter P value: ";
        cin >> DT.P[i];
    }
    cout << endl << endl;
    divisionTableInteravalSet(DT, DT_size);
    divisionTableInteravalPrint(DT, DT_size);
}

void printDivisionTable(divisionTable& DT)
{
    cout << "X:   |";
    for (int i = 0; i < DT.X.size(); i++)
    {
        cout << DT.X[i] << setw(5) << "|" << setw(5);
    }
    cout << endl;
    cout << "Y:   |";
    for (int i = 0; i < DT.P.size(); i++)
    {
        cout << DT.P[i] << setw(2) << "|" << setw(8);
    }
}

vector<descrete> dataModeling(divisionTable DT, int DT_size, vector<double> &numbers, vector<descrete> D, frequencyTable &frTable)
{
    D.resize(numbers.size());
    for (int i = 0; i < numbers.size(); i++)
    {
        for (int j = 0; j < DT_size; j++)
        {
            if (numbers[i] >= DT.Interval[j].first_value && numbers[i] < DT.Interval[j].second_value)
            {
                D[i].value = DT.X[j];
                D[i].probability = numbers[i];
                frTable.frequent_occasion[j]++;
            }
            else if(numbers[i] == 1)
            {
                D[i].value = DT.X[DT_size - 1];
                D[i].probability = 1;
            }
        }
    }
    for (int i = 0; i < DT_size; i++)
    {
        frTable.relatively_frequent_occasion[i] = (double)frTable.frequent_occasion[i] / numbers.size();
    }
    return D;
}

void printDataModeling(vector<descrete> D)
{
    for (int i = 0; i < D.size(); i++)
    {
        cout << "\n\n" << "Generated value: " << D[i].value << endl << "Given probability: " << D[i].probability;
    }
}

void frequencyTableFill(frequencyTable &frTable, divisionTable DT)
{
    frTable.Interval.resize(DT.P.size());
    frTable.frequent_occasion.resize(DT.P.size());
    frTable.relatively_frequent_occasion.resize(DT.P.size());
    for (int i = 0; i < DT.P.size(); i++)
    {
        frTable.Interval[i] = DT.Interval[i];
    }
}

void frequencyTablePrint(frequencyTable frTable)
{
    cout << "Interval:                 ";
    cout << "[" << frTable.Interval[0].first_value << ", " << frTable.Interval[0].second_value << "]" << setw(0) << "            ";
    for (int i = 1; i < frTable.Interval.size() - 1; i++)
    {
        cout << "[" << frTable.Interval[i].first_value << ", " << frTable.Interval[i].second_value << ")" << setw(0) << "            ";
    }
    cout << "[" << frTable.Interval[frTable.Interval.size() - 1].first_value << ", " << frTable.Interval[frTable.Interval.size() - 1].second_value << "]" << setw(0) << "            ";
    cout << endl;
    cout << "Frequency: ";
    for (int i = 0; i < frTable.Interval.size(); i++)
    {
        cout << "             |" << setw(5) << frTable.frequent_occasion[i] << setw(5) << "|" << setw(5);
    }
    cout << endl;
    cout << "Relative Frequency: ";
    for (int i = 0; i < frTable.Interval.size(); i++)
    {
        cout << "    |" << setw(5) << frTable.relatively_frequent_occasion[i] << setw(5) << "|" << setw(14);
    }
}

void puassonLaw(divisionTable &DT)
{
    DT.X.resize(7);
    DT.P.resize(7);
    double pValue = 0.1;
    double kCounter;
    double lambdaValue = 12;
    double randomValue;
    srand(time(NULL));
    for (int i = 0; i < 7; i++)
    {
        kCounter = 0;
        for (int j = 0; j < lambdaValue / pValue; j++)
        {
            randomValue = (double)(rand() % 100 + 0) / 100;
            if (randomValue >= 0 && randomValue <= 0.1)
            {
                kCounter++;
                DT.P[i] = randomValue;
            }
        }
        DT.X[i] = kCounter;
    }
}

double divisionTableMathematicalProbability(divisionTable DT)
{
    double X_value = 0;
    for (int i = 0; i < DT.X.size(); i++)
    {
        X_value += DT.X[i];
    }
    return X_value / DT.X.size();
}

double divisionTableDyspersion(divisionTable DT)
{
    double X_mat_prob = divisionTableMathematicalProbability(DT);
    double X_square = 0;
    double dyspersion = 0;
    for (int i = 0; i < DT.X.size(); i++)
    {
        X_square += (DT.X[i] * DT.X[i]);
    }
    X_square /= DT.X.size();
    for (int i = 0; i < DT.X.size(); i++)
    {
        dyspersion += X_square - (X_mat_prob *  X_mat_prob);
    }
    return dyspersion / DT.X.size();
}

double descreteMathematicalProbability(vector<descrete> D)
{
    double X_value = 0;
    for (int i = 0; i < D.size(); i++)
    {
        X_value += D[i].value;
    }
    return X_value / D.size();
}

double descreteDyspersion(vector<descrete> D)
{
    double X_value = descreteMathematicalProbability(D);
    double X_square = 0;
    double dyspersion = 0;
    for (int i = 0; i < D.size(); i++)
    {
        X_square += (D[i].value * D[i].value);
    }
    X_square /= D.size();
    for (int i = 0; i < D.size(); i++)
    {
        dyspersion += X_square - (X_value * X_value);
    }
    return dyspersion / D.size();
}

void main()
{
    //inputDivisionTable(DT);
    vector<double> numbers;
    vector<descrete> D;
    divisionTable DT;
    frequencyTable frTable;
    int numbers_size;
    int option;
    double avg_def = 12, dys_def = 12, avg_puas = (double)12 / 0.1, dys_puas = (double)12 / 0.1;
    double divMathprobTheor, divMathprobPuas;
    //double divMathDyspTheor, divMathprobPuas;
    cout << "Enter number of modelings: ";
    cin >> numbers_size;
    cout << endl << endl;
    numbers.resize(numbers_size);
    cout << "Enter option [0] - Division Table, [1] - Puasson Law: ";
    cin >> option;
    cout << endl << endl;
    switch (option)
    {
    case 0:
        DT.X = { 7, 16, 28, 33, 39, 46, 56 };
        DT.P = { 0.01, 0.05, 0.07, 0.1, 0.17, 0.25, 0.35 };
        break;
    case 1:
        puassonLaw(DT);
        break;
    default:
        return;
    }
    printDivisionTable(DT);
    divisionTableInteravalSet(DT, DT.P.size());
    frequencyTableFill(frTable, DT);
    divisionTableInteravalPrint(DT, DT.P.size());
    cout << "\n\n";
    inputNumGeneratedSequence(numbers);
    printNumGeneratedSequence(numbers);
    D = dataModeling(DT, DT.P.size(), numbers, D, frTable);
    printDataModeling(D);
    cout << "\n\n\n\n\n\n\n\n";
    frequencyTablePrint(frTable);
    if (option == 1)
    {
        cout << "\n\n\n";
        cout << "Average theoretical: " << avg_def << endl << "Average descrete: " << avg_puas << endl << endl;
        cout << "Dyspersion theoretical: " << dys_def << endl << "Dyspersion descrete: " << dys_puas << endl << endl;
    }
    else
    {
        cout << "\n\n\n";
        cout << "Mathematical probability theoretical: " << divisionTableMathematicalProbability(DT) << endl << "Mathematical probability descrete: " << descreteMathematicalProbability(D) << endl << endl;
        cout << "Dyspersion theoretical: " << divisionTableDyspersion(DT) << endl << "Dyspersion descrete: " << descreteDyspersion(D) << endl << endl;
    }
}