#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct ReturnRes
{
	vector<long double> startProbability;
	vector<bool> nullCheck;
};

ReturnRes certainNumber(vector<long double> startProbability, int value, vector<vector<int>> dices, vector<bool> nullCheck)
{
	
	vector<long double> numberDropProbability;
	vector<long double> numberCommonProbability;
	vector<long double> numberEndProbability;
	vector<long double> numberPrevious;
	double tempSum = 0;
	numberDropProbability.resize(dices.size());
	numberCommonProbability.resize(dices.size());
	numberEndProbability.resize(dices.size());
	numberPrevious.resize(dices.size());
	nullCheck.resize(dices.size());
	
	for (int i = 0; i < dices.size(); i++)
	{
		numberDropProbability[i] = (value <= dices[i].size()) ? 1.0 / dices[i].size() : 0;
	}

	for (int i = 0; i < dices.size(); i++)
	{
		numberCommonProbability[i] = startProbability[i] * numberDropProbability[i];
	}

	for (int i = 0; i < dices.size(); i++)
	{
		tempSum += numberCommonProbability[i];
	}

	for (int i = 0; i < dices.size(); i++)
	{
		numberEndProbability[i] = (value <= dices[i].size()) ? (numberCommonProbability[i] * (1.0 / dices.size())) / ((1.0 / dices.size()) * tempSum) : startProbability[i];
	}

	cout << "Dice\t" << setw(10) << "St Pr\t" << setw(10) << "Num drop pr\t"
		<< setw(10) << "Num common pr\t" << setw(10) << "Num end pr\t" << endl;

	for (int i = 0; i < dices.size(); i++)
	{
		if (nullCheck[i] == true)
		{
			cout << dices[i].size() << '\t' << setw(10) << 0;
		}
		else
		{
			cout << dices[i].size() << '\t' << setw(10) << startProbability[i];
		}

		cout << '\t' << setw(10) << numberDropProbability[i] << '\t' << setw(10);

		if (nullCheck[i] == true)
		{
			numberCommonProbability[i] = 0;
			cout << numberCommonProbability[i] << '\t';
		}
		else
		{
			cout << numberCommonProbability[i] << '\t';
		}

		if (numberCommonProbability[i] == 0)
		{
			cout << setw(10) << 0 << endl;
			numberPrevious[i] = 0;
			nullCheck[i] = true;
		}
		else
		{
			cout << setw(10) << numberEndProbability[i] << endl;
			numberPrevious[i] = numberEndProbability[i];
			nullCheck[i] = false;
		}
	}

	startProbability = numberEndProbability;

	ReturnRes RR;
	RR.startProbability = startProbability;
	RR.nullCheck = nullCheck;

	return RR;
}

ReturnRes certainChainNumbers(vector<long double> startProbability, vector<vector<int>> dices, vector<bool> nullCheck)
{
	ReturnRes RR;
	RR.startProbability = startProbability;
	RR.nullCheck = nullCheck;
	cout << "\n\n" << "Number 2 sequence" << "\n";
	RR = certainNumber(RR.startProbability, 2, dices, RR.nullCheck);
	cout << "\n\n" << "Number 5 sequence" << "\n";
	RR = certainNumber(RR.startProbability, 5, dices, RR.nullCheck);
	cout << "\n\n" << "Number 4 sequence" << "\n";
	RR = certainNumber(RR.startProbability, 4, dices, RR.nullCheck);
	return RR;
}

void randomArrayNumbers(int value, vector<vector<int>> dices, vector<bool> nullCheck, vector<long double> startProbability)
{
	srand(time(NULL));
	int max = value;
	int number;
	ReturnRes RR;
	RR.nullCheck = nullCheck;
	RR.startProbability = startProbability;

	for (int i = 0; i < 10; i++)
	{
		number = rand() % max + 1;
		cout << "\n\n" << "Attempt " << i + 1 << " with picked dice " << value << ", number " << number << " generated" << "\n";
		RR = certainNumber(RR.startProbability, number, dices, RR.nullCheck);
	}
}

int main()
{
	int dicesAmount, diceDimensionTemp;
	vector<vector<int>> dices;
	vector<long double> startProbability;
	vector<bool> nullCheck;

	//
	//Certain numbers
	//

	cout << endl << endl << "Certain numbers" << endl << endl;

	cout << "Enter amount of dices: ";
	cin >> dicesAmount;
	cout << endl;
	dices.resize(dicesAmount);
	for (int i = 0; i < dicesAmount; i++)
	{
		cout << "Enter dice " << i + 1 << " dimensions: ";
		cin >> diceDimensionTemp;
		cout << endl;
		dices[i].resize(diceDimensionTemp);
	}

	cout << endl << endl << endl;

	startProbability.resize(dices.size());
	nullCheck.resize(dices.size());

	for (int i = 0; i < dices.size(); i++)
	{
		startProbability[i] = 1.0 / dices.size();
		nullCheck[i] = false;
	}

	cout << "Number 5" << endl;

	//Certain number 5

	certainNumber(startProbability, 5, dices, nullCheck);

	cout << endl << "Number 2" << endl;

	//Certain number 2

	certainNumber(startProbability, 2, dices, nullCheck);

	//
	//Certain numbers chain sequence
	//

	cout << endl << endl << endl << endl << endl << endl << "Certain numbers chain sequnce" << endl << endl;

	cout << "Enter amount of dices: ";
	cin >> dicesAmount;
	cout << endl;
	dices.resize(dicesAmount);
	for (int i = 0; i < dicesAmount; i++)
	{
		cout << "Enter dice " << i + 1 << " dimensions: ";
		cin >> diceDimensionTemp;
		cout << endl;
		dices[i].resize(diceDimensionTemp);
	}

	cout << endl << endl << endl;
	
	startProbability.resize(dices.size());

	for (int i = 0; i < dices.size(); i++)
	{
		startProbability[i] = 1.0 / dices.size();
	}
	certainChainNumbers(startProbability, dices, nullCheck);

	//
	//Random numbers chain sequence of 10
	//

	cout << endl << endl << endl << endl << endl << endl << "Random numbers chain sequence of 10" << endl << endl;

	cout << "Enter amount of dices: ";
	cin >> dicesAmount;
	cout << endl;
	dices.resize(dicesAmount);
	for (int i = 0; i < dicesAmount; i++)
	{
		cout << "Enter dice " << i + 1 << " dimensions: ";
		cin >> diceDimensionTemp;
		cout << endl;
		dices[i].resize(diceDimensionTemp);
	}

	cout << endl << endl << endl;

	startProbability.resize(dices.size());

	for (int i = 0; i < dices.size(); i++)
	{
		startProbability[i] = 1.0 / dices.size();
	}

	srand(time(NULL));

	int number = dices[rand() % dices.size()].size();

	randomArrayNumbers(number, dices, nullCheck, startProbability);
}