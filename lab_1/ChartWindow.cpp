#include "ChartWindow.h"
#include <vector>
#include <iostream>

using namespace System;
using namespace System::Windows::Forms;
using namespace std;

std::vector<int> calc(int N);

void show_arr(std::vector<int> arr);

std::vector<int> random;

const int N10 = 10;

const int N100 = 100;

const int N1000 = 1000;

const int N10000 = 10000;

double matematychne_spodivannya = (1.0 / 4.0) * (1 + 2 + 3 + 4);

double seredniy_kvadrat = (1.0 / 4.0) * ((1 * 1) + (2 * 2) + (3 * 3) + (4 * 4));

double dyspersiya = seredniy_kvadrat - (matematychne_spodivannya * matematychne_spodivannya);

double seredniokvadratychne_vidhylenya = sqrt(dyspersiya);

double vybirkove_matematychne_spodivannyaFunc(std::vector<int> numbers)
{
	double numbersSum = 0;
	for (int i = 0; i < numbers.size(); i++)
	{
		numbersSum += numbers[i];
	}
	return (1.0 / (double)numbers.size()) * numbersSum;
}

double vybirkove_seredniy_kvadratFunc(std::vector<int> numbers)
{
	double numbersSum = 0;
	for (int i = 0; i < numbers.size(); i++)
	{
		numbersSum += (numbers[i] * numbers[i]);
	}
	return (1.0 / (double)numbers.size()) * numbersSum;
}

double vybirkove_dyspersiyaFunc(std::vector<int> numbers)
{
	return vybirkove_seredniy_kvadratFunc(numbers) - (vybirkove_matematychne_spodivannyaFunc(numbers) * vybirkove_matematychne_spodivannyaFunc(numbers));
}

double vybirkove_seredniokvadratychne_vidhylenyaFunc(std::vector<int> numbers)
{
	return sqrt(vybirkove_dyspersiyaFunc(numbers));
}

[STAThreadAttribute]
void main()
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	lab1::ChartWindow form;
	Application::Run(% form);
	
}

std::vector<int> calc(int N)
{
	srand(time(0));
	std::vector<int> arrayNumbers;
	for (int i = 0; i < N; i++)
	{
		arrayNumbers.insert(arrayNumbers.begin(), rand() % 4 + 1);
	}
	return arrayNumbers;
}

void show_arr(std::vector<int> arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		std::cout << i << " element of array is" << arr[i] << "\n";
	}
}

std::vector<int> elem_filter(std::vector<int> count)
{
	for (int i = 0; i < 4; i++)
	{
		count.insert(count.begin(), 0);
	}

	for (int i = 0; i < random.size(); i++)
	{
		switch (random[i])
		{
		case 1:
			count[0]++;
			break;
		case 2:
			count[1]++;
			break;
		case 3:
			count[2]++;
			break;
		case 4:
			count[3]++;
			break;
		}
	}
	return count;
}

System::Void lab1::ChartWindow::ChartWindow_Shown(System::Object^ sender, System::EventArgs^ e)
{
	/*this->randomChart10->Series["Values"]->Color = Color::Pink;

	this->randomChart10->Series["Values"]->Color = Color::Yellow;*/

	this->label1->Text += " " + matematychne_spodivannya.ToString();

	this->label2->Text += " " + seredniy_kvadrat.ToString();

	this->label3->Text += " " + dyspersiya.ToString();

	this->label4->Text += " " + seredniokvadratychne_vidhylenya.ToString();

	random = calc(N10);

	std::vector<int> count;

	count = elem_filter(count);

	this->randomChart10->Series->Clear();

	this->randomChart10->Series->Add("Values");

	this->randomChart10->Series["Values"]->Color = Color::Blue;

	this->randomChart10->Series["Values"]->Points->AddXY("1", count[0].ToString());
	this->randomChart10->Series["Values"]->Points->AddXY("2", count[1].ToString());
	this->randomChart10->Series["Values"]->Points->AddXY("3", count[2].ToString());
	this->randomChart10->Series["Values"]->Points->AddXY("4", count[3].ToString());

	std::cout << "Values up to 10:\n";
	std::cout << "\nvybirkove_matematychne_spodivannya: ";
	std::cout << vybirkove_matematychne_spodivannyaFunc(random);

	std::cout << "\nvybirkove_seredniy_kvadrat: ";
	std::cout << vybirkove_seredniy_kvadratFunc(random);

	std::cout << "\nvybirkove_dyspersiya: ";
	std::cout << vybirkove_dyspersiyaFunc(random);

	std::cout << "\nvybirkove_seredniokvadratychne_vidhylenya: ";
	std::cout << vybirkove_seredniokvadratychne_vidhylenyaFunc(random) << "\n\n\n\n\n\n\n";

	random.clear();

	count.clear();

	random = calc(N100);

	count = elem_filter(count);

	this->randomChart100->Series->Clear();

	this->randomChart100->Series->Add("Values");

	this->randomChart100->Series["Values"]->Color = Color::Red;

	this->randomChart100->Series["Values"]->Points->AddXY("1", count[0].ToString());
	this->randomChart100->Series["Values"]->Points->AddXY("2", count[1].ToString());
	this->randomChart100->Series["Values"]->Points->AddXY("3", count[2].ToString());
	this->randomChart100->Series["Values"]->Points->AddXY("4", count[3].ToString());

	std::cout << "Values up to 100:\n";
	std::cout << "\nvybirkove_matematychne_spodivannya: ";
	std::cout << vybirkove_matematychne_spodivannyaFunc(random);

	std::cout << "\nvybirkove_seredniy_kvadrat: ";
	std::cout << vybirkove_seredniy_kvadratFunc(random);

	std::cout << "\nvybirkove_dyspersiya: ";
	std::cout << vybirkove_dyspersiyaFunc(random);

	std::cout << "\nvybirkove_seredniokvadratychne_vidhylenya: ";
	std::cout << vybirkove_seredniokvadratychne_vidhylenyaFunc(random) << "\n\n\n\n\n\n\n";

	random.clear();

	count.clear();

	random = calc(N1000);

	count = elem_filter(count);

	this->randomChart1000->Series->Clear();

	this->randomChart1000->Series->Add("Values");

	this->randomChart1000->Series["Values"]->Color = Color::Green;

	this->randomChart1000->Series["Values"]->Points->AddXY("1", count[0].ToString());
	this->randomChart1000->Series["Values"]->Points->AddXY("2", count[1].ToString());
	this->randomChart1000->Series["Values"]->Points->AddXY("3", count[2].ToString());
	this->randomChart1000->Series["Values"]->Points->AddXY("4", count[3].ToString());

	std::cout << "Values up to 1000:\n";
	std::cout << "\nvybirkove_matematychne_spodivannya: ";
	std::cout << vybirkove_matematychne_spodivannyaFunc(random);

	std::cout << "\nvybirkove_seredniy_kvadrat: ";
	std::cout << vybirkove_seredniy_kvadratFunc(random);

	std::cout << "\nvybirkove_dyspersiya: ";
	std::cout << vybirkove_dyspersiyaFunc(random);

	std::cout << "\nvybirkove_seredniokvadratychne_vidhylenya: ";
	std::cout << vybirkove_seredniokvadratychne_vidhylenyaFunc(random) << "\n\n\n\n\n\n\n";

	random.clear();

	count.clear();

	random = calc(N10000);

	count = elem_filter(count);

	this->randomChart10000->Series->Clear();

	this->randomChart10000->Series->Add("Values");

	this->randomChart10000->Series["Values"]->Color = Color::Orange;

	this->randomChart10000->Series["Values"]->Points->AddXY("1", count[0].ToString());
	this->randomChart10000->Series["Values"]->Points->AddXY("2", count[1].ToString());
	this->randomChart10000->Series["Values"]->Points->AddXY("3", count[2].ToString());
	this->randomChart10000->Series["Values"]->Points->AddXY("4", count[3].ToString());

	std::cout << "Values up to 10000:\n";
	std::cout << "\nvybirkove_matematychne_spodivannya: ";
	std::cout << vybirkove_matematychne_spodivannyaFunc(random);

	std::cout << "\nvybirkove_matematychne_spodivannya: ";
	std::cout << vybirkove_seredniy_kvadratFunc(random);

	std::cout << "\nvybirkove_dyspersiya: ";
	std::cout << vybirkove_dyspersiyaFunc(random);

	std::cout << "\nvybirkove_seredniokvadratychne_vidhylenya: ";
	std::cout << vybirkove_seredniokvadratychne_vidhylenyaFunc(random) << "\n\n\n\n\n\n\n";
	return System::Void();
}
