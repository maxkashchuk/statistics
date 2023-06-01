#pragma once

namespace lab1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ChartWindow
	/// </summary>
	public ref class ChartWindow : public System::Windows::Forms::Form
	{
	public:
		ChartWindow(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ChartWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ randomChart10;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ randomChart100;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ randomChart1000;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ randomChart10000;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ randomChartDif1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ randomChartDif2;






	protected:

	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^ title1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^ title2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^ title3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea4 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^ title4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea5 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^ title5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea6 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^ title6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			this->randomChart10 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->randomChart100 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->randomChart1000 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->randomChart10000 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->randomChartDif1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->randomChartDif2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->randomChart10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->randomChart100))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->randomChart1000))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->randomChart10000))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->randomChartDif1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->randomChartDif2))->BeginInit();
			this->SuspendLayout();
			// 
			// randomChart10
			// 
			chartArea1->Name = L"ChartArea1";
			this->randomChart10->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->randomChart10->Legends->Add(legend1);
			this->randomChart10->Location = System::Drawing::Point(12, 12);
			this->randomChart10->Name = L"randomChart10";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->randomChart10->Series->Add(series1);
			this->randomChart10->Size = System::Drawing::Size(390, 274);
			this->randomChart10->TabIndex = 0;
			this->randomChart10->Text = L"chart1";
			title1->Name = L"Values";
			title1->Text = L"Values up to 10";
			this->randomChart10->Titles->Add(title1);
			this->randomChart10->Click += gcnew System::EventHandler(this, &ChartWindow::chart1_Click);
			// 
			// randomChart100
			// 
			chartArea2->Name = L"ChartArea1";
			this->randomChart100->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->randomChart100->Legends->Add(legend2);
			this->randomChart100->Location = System::Drawing::Point(441, 12);
			this->randomChart100->Name = L"randomChart100";
			series2->ChartArea = L"ChartArea1";
			series2->Legend = L"Legend1";
			series2->Name = L"Series1";
			this->randomChart100->Series->Add(series2);
			this->randomChart100->Size = System::Drawing::Size(390, 274);
			this->randomChart100->TabIndex = 1;
			this->randomChart100->Text = L"chart1";
			title2->Name = L"Values";
			title2->Text = L"Values up to 100";
			this->randomChart100->Titles->Add(title2);
			// 
			// randomChart1000
			// 
			chartArea3->Name = L"ChartArea1";
			this->randomChart1000->ChartAreas->Add(chartArea3);
			legend3->Name = L"Legend1";
			this->randomChart1000->Legends->Add(legend3);
			this->randomChart1000->Location = System::Drawing::Point(12, 306);
			this->randomChart1000->Name = L"randomChart1000";
			series3->ChartArea = L"ChartArea1";
			series3->Legend = L"Legend1";
			series3->Name = L"Series1";
			this->randomChart1000->Series->Add(series3);
			this->randomChart1000->Size = System::Drawing::Size(390, 274);
			this->randomChart1000->TabIndex = 2;
			this->randomChart1000->Text = L"chart2";
			title3->Name = L"Values";
			title3->Text = L"Values up to 1000";
			this->randomChart1000->Titles->Add(title3);
			// 
			// randomChart10000
			// 
			chartArea4->Name = L"ChartArea1";
			this->randomChart10000->ChartAreas->Add(chartArea4);
			legend4->Name = L"Legend1";
			this->randomChart10000->Legends->Add(legend4);
			this->randomChart10000->Location = System::Drawing::Point(441, 306);
			this->randomChart10000->Name = L"randomChart10000";
			series4->ChartArea = L"ChartArea1";
			series4->Legend = L"Legend1";
			series4->Name = L"Series1";
			this->randomChart10000->Series->Add(series4);
			this->randomChart10000->Size = System::Drawing::Size(390, 274);
			this->randomChart10000->TabIndex = 3;
			this->randomChart10000->Text = L"chart3";
			title4->Name = L"Values";
			title4->Text = L"Values up to 10000";
			this->randomChart10000->Titles->Add(title4);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(857, 159);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(124, 16);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Середній квадрат";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(857, 71);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(173, 16);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Математичне сподівання";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(857, 256);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(72, 16);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Дисперсія";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(857, 356);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(232, 16);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Середньоквадратичне відхилення";
			// 
			// randomChartDif1
			// 
			chartArea5->Name = L"ChartArea1";
			this->randomChartDif1->ChartAreas->Add(chartArea5);
			legend5->Name = L"Legend1";
			this->randomChartDif1->Legends->Add(legend5);
			this->randomChartDif1->Location = System::Drawing::Point(12, 610);
			this->randomChartDif1->Name = L"randomChartDif1";
			series5->ChartArea = L"ChartArea1";
			series5->Legend = L"Legend1";
			series5->Name = L"Series1";
			this->randomChartDif1->Series->Add(series5);
			this->randomChartDif1->Size = System::Drawing::Size(390, 274);
			this->randomChartDif1->TabIndex = 8;
			this->randomChartDif1->Text = L"chart2";
			title5->Name = L"Values";
			title5->Text = L"Values up to 1000";
			this->randomChartDif1->Titles->Add(title5);
			// 
			// randomChartDif2
			// 
			chartArea6->Name = L"ChartArea1";
			this->randomChartDif2->ChartAreas->Add(chartArea6);
			legend6->Name = L"Legend1";
			this->randomChartDif2->Legends->Add(legend6);
			this->randomChartDif2->Location = System::Drawing::Point(441, 610);
			this->randomChartDif2->Name = L"randomChartDif2";
			series6->ChartArea = L"ChartArea1";
			series6->Legend = L"Legend1";
			series6->Name = L"Series1";
			this->randomChartDif2->Series->Add(series6);
			this->randomChartDif2->Size = System::Drawing::Size(390, 274);
			this->randomChartDif2->TabIndex = 9;
			this->randomChartDif2->Text = L"chart2";
			title6->Name = L"Values";
			title6->Text = L"Values up to 1000";
			this->randomChartDif2->Titles->Add(title6);
			this->randomChartDif2->Click += gcnew System::EventHandler(this, &ChartWindow::chart2_Click);
			// 
			// ChartWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1262, 1005);
			this->Controls->Add(this->randomChartDif2);
			this->Controls->Add(this->randomChartDif1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->randomChart10000);
			this->Controls->Add(this->randomChart1000);
			this->Controls->Add(this->randomChart100);
			this->Controls->Add(this->randomChart10);
			this->Name = L"ChartWindow";
			this->Text = L"ChartWindow";
			this->Shown += gcnew System::EventHandler(this, &ChartWindow::ChartWindow_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->randomChart10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->randomChart100))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->randomChart1000))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->randomChart10000))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->randomChartDif1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->randomChartDif2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void ChartWindow_Shown(System::Object^ sender, System::EventArgs^ e);
	private: System::Void chart1_Click(System::Object^ sender, System::EventArgs^ e) { }
	private: System::Void chart2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
