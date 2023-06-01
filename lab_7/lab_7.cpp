#include <iostream>
#include <vector>

using namespace std;

struct Graph
{
    int currentVertex = 0;
    vector<vector<int>> AdjMatrix =
    {
        { 0, 1, 1, 1},
        { 1, 0, 1, 0},
        { 0, 1, 1, 0},
        { 0, 0, 1, 0}
    };
};

int calculateProbability(Graph &MarkovChain)
{
    vector<double> Probabilities, Result;
    vector<int> quitRes = { 1, 0 }, currRes;
    double PreviousSum, temp;
    int indVertexCurr = 0, indVertexPrev = 0, indProb;
    Probabilities.resize(4);
    currRes.resize(2);
    while (quitRes != currRes)
    {
        currRes.clear();
        currRes.resize(2);
        PreviousSum = 0;
        indProb = 0;
        indVertexPrev = indVertexCurr;
        currRes[0] = indVertexPrev;
        for (int j = 0; j < 4; j++)
        {
            if (MarkovChain.AdjMatrix[MarkovChain.currentVertex][j] != 0)
            {
                if (PreviousSum < 1)
                {
                    temp = ceil(((double)rand() / ((double)RAND_MAX + (double)1 - PreviousSum)) * 100.0) / 100.0;
                }
                else
                {

                    temp = 0;
                }
                Probabilities[j] = temp;
                PreviousSum += temp;
                indProb = j;
            }
            else
            {
                Probabilities[j] = 0;
            }
        }
        PreviousSum = 0;
        if (Probabilities.size() > 1)
        {
            for (int j = 0; j < Probabilities.size(); j++)
            {
                if (j != indProb)
                {
                    PreviousSum += Probabilities[j];
                }
            }
            Probabilities[indProb] = (double)1 - PreviousSum;
        }
        else
        {
            Probabilities[indProb] = (double)1;
        }
        indVertexCurr = 0;
        for (int j = 0; j < 4; j++)
        {
            if (Probabilities[j] > Probabilities[indVertexCurr])
            {
                temp = Probabilities[j];
                indVertexCurr = j;
            }
        }
        Result.push_back(temp);
        MarkovChain.currentVertex = indVertexCurr;
        currRes[1] = indVertexCurr;
    }
    return Result.size();
}

void calculateProbabilityCycled(Graph& MarkovChain, int time)
{
    vector<double> Probabilities, tauValues, Result, timeArray, timeRes;
    vector<int> quitRes = { 1, 0 }, currRes;
    double PreviousSum, temp, deltaT, timeGeneral = 0, tempVer;
    int indVertexCurr = 0, indVertexPrev = 0, indProb;
    Probabilities.resize(4);
    currRes.resize(2);
    timeRes.resize(2);
    timeRes[0] = 0;
    while (time > timeGeneral)
    {
        timeRes.clear();
        currRes.clear();
        timeRes.resize(2);
        currRes.resize(2);
        PreviousSum = 0;
        indProb = 0;
        indVertexPrev = indVertexCurr;
        currRes[0] = indVertexPrev;
        timeRes[0] = Probabilities[indVertexCurr];
        Probabilities.clear();
        Probabilities.resize(4);
        for (int j = 0; j < 4; j++)
        {
            if (MarkovChain.AdjMatrix[MarkovChain.currentVertex][j] != 0)
            {
                if (PreviousSum < 1)
                {
                    temp = ceil(((double)rand() / ((double)RAND_MAX + (double)1 - PreviousSum)) * 100.0) / 100.0;
                }
                else
                {

                    temp = 0;
                }
                Probabilities[j] = temp;
                PreviousSum += temp;
                indProb = j;
            }
            else
            {
                Probabilities[j] = 0;
            }
        }
        PreviousSum = 0;
        if (Probabilities.size() > 1)
        {
            for (int j = 0; j < Probabilities.size(); j++)
            {
                if (j != indProb)
                {
                    PreviousSum += Probabilities[j];
                }
            }
            Probabilities[indProb] = (double)1 - PreviousSum;
        }
        else
        {
            Probabilities[indProb] = (double)1;
        }
        for (int j = 0; j <= 3; j++)
        {
            if (Probabilities[j] != 0)
            {
                deltaT = ceil(((double)rand() / ((double)RAND_MAX + (double)1)) * 100.0) / 100.0;
                Probabilities[j] /= deltaT;
                Probabilities[j] = -1 / Probabilities[j] * log(ceil(((double)rand() / ((double)RAND_MAX + (double)1)) * 100.0) / 100.0);
            }
        }
        indVertexCurr = 0;
        for (int j = 0; j <= 3; j++)
        {
            if (Probabilities[j] != 0)
            {
                tempVer = Probabilities[j];
                temp = Probabilities[j];
                indVertexCurr = j;
                for (int k = 0; k <= 3; k++)
                {
                    if (Probabilities[k] != 0 && Probabilities[k] < tempVer)
                    {
                        temp = Probabilities[j];
                        indVertexCurr = k;
                    }
                }
            }
        }
        timeGeneral += Probabilities[indVertexCurr];
        timeArray.push_back(timeGeneral);
        Result.push_back(temp);
        MarkovChain.currentVertex = indVertexCurr;
        cout << "Time Interval [" << timeRes[0] << ", " << Probabilities[indVertexCurr] << "] : ";
        cout << "from " << currRes[0] << " to " << indVertexCurr << endl;
        currRes[1] = indVertexCurr;
    }
    cout << endl << endl << "Percentage: " << endl; 
    for (int i = 0; i < timeArray.size(); i++)
    {
        cout << i << " Transition is " << ((timeGeneral / 100) * timeArray[i]) * 100 << endl;
    }
}

double avg(vector<double> ModellingQuantity)
{
    double average = 0;
    for (int i = 0; i < ModellingQuantity.size(); i++)
    {
        average += ModellingQuantity[i];
    }
    return ceil((average / ModellingQuantity.size()) * 100.0) / 100.0;
}

int main()
{
    srand(time(NULL));
    Graph MarkovChain;
    vector<double> ModellingQuantity;
    int modellingNumber, time, temp;

    cout << "Enter number of modellings: ";
    cin >> modellingNumber;
    cout << endl;

    for (int i = 0; i < modellingNumber; i++)
    {
        temp = calculateProbability(MarkovChain);
        ModellingQuantity.push_back(temp);
        cout << "Modelling " << i + 1 << " | avg |:" << avg(ModellingQuantity) << " | quantity |: " << temp << endl;
    }

    MarkovChain.currentVertex = 0;

    cout << endl << endl;
    cout << "Enter time interval of system: ";
    cin >> time;
    cout << endl;
    cout << "General time of system: " << time << endl << endl;

    calculateProbabilityCycled(MarkovChain, time);
}