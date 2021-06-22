#pragma once
#include <iostream>
#include <string>
#include <msclr\marshal_cppstd.h>
#include <cmath>
#include <algorithm>
#include <thread>
#include <chrono>
#include <fstream>



namespace BallisticMovement 
{
	using namespace msclr::interop;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace System::Drawing::Drawing2D;
	using namespace System::Windows::Forms::DataVisualization::Charting;
	/// <summary>
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(bool admin, String^ lang)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//

			//������������� �������� �����
			//������������ ������� marshal_as ��� �������� �� std::string � String^

			this->lang = lang;

			lang_combobox->Items->Add("�������");
			lang_combobox->Items->Add("English");
			lang_combobox->Items->Add("����������");

			block = false;

			lang_combobox->SelectedItem = lang;
			change_language();

			g_textbox->Text = marshal_as<String^>(std::to_string(g));
			if (!admin)
			{
				g_label->Visible = false;
				g_textbox->Visible = false;
				g_measure->Visible = false;				
			}

			//������� ��� ���������� ��������� �������, ������� ���� ��������
			//� ������ ������ ������� � ������ ������� ����� ���� �� ����� ������ true
			last_changed1 = new bool[5]{ false,false,false,false,false };
			last_changed2 = new bool[5]{ false,false,false,false,false };
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			Application::Exit();
		}

	private: System::String^ lang;
	private: System::String^ error_msg;
	private: System::String^ invalid_format_msg;
	private: bool* last_changed1;//��������� ��������� ��������
	private: bool* last_changed2;//������������� ��������� ��������
	private: bool block; //��� ���������� �����, ����� ����������� �������� ������ TextBoxChanged,
		   //����� �� ������ ����� �� ����



	private: double g = 9.8;
	private: const double pi = 3.14159;
	
	private: System::Windows::Forms::Label^ lang_label;


	private: System::Windows::Forms::ComboBox^ lang_combobox;
	private: System::Windows::Forms::Button^ change_bgcolor_button;
	private: System::Windows::Forms::Label^ input_data_label;

	private: System::Windows::Forms::Label^ settings_label;

	private: System::Windows::Forms::Label^ start_speed_label;

	private: System::Windows::Forms::Label^ angle_label;
	private: System::Windows::Forms::Label^ fly_time_label;


	private: System::Windows::Forms::Label^ distance_label;
	private: System::Windows::Forms::Label^ max_height_label;


	private: System::Windows::Forms::TextBox^ start_speed_textbox;
	private: System::Windows::Forms::TextBox^ angle_textbox;
	private: System::Windows::Forms::TextBox^ fly_time_textbox;
	private: System::Windows::Forms::TextBox^ max_height_textbox;




	private: System::Windows::Forms::TextBox^ distance_textbox;

	private: System::Windows::Forms::Button^ calculate_button;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::Button^ clear_button;
	private: System::Windows::Forms::Label^ start_speed_measure;
	private: System::Windows::Forms::Label^ angle_measure;
	private: System::Windows::Forms::Label^ distance_measure;
	private: System::Windows::Forms::Label^ fly_time_measure;
	private: System::Windows::Forms::Label^ max_height_measure;
	private: System::Windows::Forms::Button^ clear_graph;
	private: System::Windows::Forms::CheckBox^ real_time_mode_checkbox;
	private: System::Windows::Forms::Button^ save_button;
	private: System::Windows::Forms::Label^ g_measure;
	private: System::Windows::Forms::TextBox^ g_textbox;
	private: System::Windows::Forms::Label^ g_label;
	private: System::Windows::Forms::Button^ information_button;
private: System::Windows::Forms::Button^ get_max_distance_button;
private: System::Windows::Forms::Button^ get_max_height_button;
private: System::Windows::Forms::Button^ save_chart_button;





	protected:


	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->lang_label = (gcnew System::Windows::Forms::Label());
			this->lang_combobox = (gcnew System::Windows::Forms::ComboBox());
			this->change_bgcolor_button = (gcnew System::Windows::Forms::Button());
			this->input_data_label = (gcnew System::Windows::Forms::Label());
			this->settings_label = (gcnew System::Windows::Forms::Label());
			this->start_speed_label = (gcnew System::Windows::Forms::Label());
			this->angle_label = (gcnew System::Windows::Forms::Label());
			this->fly_time_label = (gcnew System::Windows::Forms::Label());
			this->distance_label = (gcnew System::Windows::Forms::Label());
			this->max_height_label = (gcnew System::Windows::Forms::Label());
			this->start_speed_textbox = (gcnew System::Windows::Forms::TextBox());
			this->angle_textbox = (gcnew System::Windows::Forms::TextBox());
			this->fly_time_textbox = (gcnew System::Windows::Forms::TextBox());
			this->max_height_textbox = (gcnew System::Windows::Forms::TextBox());
			this->distance_textbox = (gcnew System::Windows::Forms::TextBox());
			this->calculate_button = (gcnew System::Windows::Forms::Button());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->clear_button = (gcnew System::Windows::Forms::Button());
			this->start_speed_measure = (gcnew System::Windows::Forms::Label());
			this->angle_measure = (gcnew System::Windows::Forms::Label());
			this->distance_measure = (gcnew System::Windows::Forms::Label());
			this->fly_time_measure = (gcnew System::Windows::Forms::Label());
			this->max_height_measure = (gcnew System::Windows::Forms::Label());
			this->clear_graph = (gcnew System::Windows::Forms::Button());
			this->real_time_mode_checkbox = (gcnew System::Windows::Forms::CheckBox());
			this->save_button = (gcnew System::Windows::Forms::Button());
			this->g_measure = (gcnew System::Windows::Forms::Label());
			this->g_textbox = (gcnew System::Windows::Forms::TextBox());
			this->g_label = (gcnew System::Windows::Forms::Label());
			this->information_button = (gcnew System::Windows::Forms::Button());
			this->get_max_distance_button = (gcnew System::Windows::Forms::Button());
			this->get_max_height_button = (gcnew System::Windows::Forms::Button());
			this->save_chart_button = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// lang_label
			// 
			this->lang_label->AutoSize = true;
			this->lang_label->Location = System::Drawing::Point(53, 37);
			this->lang_label->Name = L"lang_label";
			this->lang_label->Size = System::Drawing::Size(42, 17);
			this->lang_label->TabIndex = 0;
			this->lang_label->Text = L"����";
			// 
			// lang_combobox
			// 
			this->lang_combobox->FormattingEnabled = true;
			this->lang_combobox->Location = System::Drawing::Point(53, 58);
			this->lang_combobox->Name = L"lang_combobox";
			this->lang_combobox->Size = System::Drawing::Size(121, 24);
			this->lang_combobox->TabIndex = 1;
			this->lang_combobox->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::lang_combobox_SelectedIndexChanged);
			// 
			// change_bgcolor_button
			// 
			this->change_bgcolor_button->Location = System::Drawing::Point(196, 58);
			this->change_bgcolor_button->Name = L"change_bgcolor_button";
			this->change_bgcolor_button->Size = System::Drawing::Size(221, 30);
			this->change_bgcolor_button->TabIndex = 3;
			this->change_bgcolor_button->Text = L"�������� ���� ����";
			this->change_bgcolor_button->UseVisualStyleBackColor = true;
			this->change_bgcolor_button->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// input_data_label
			// 
			this->input_data_label->AutoSize = true;
			this->input_data_label->Location = System::Drawing::Point(12, 104);
			this->input_data_label->Name = L"input_data_label";
			this->input_data_label->Size = System::Drawing::Size(163, 17);
			this->input_data_label->TabIndex = 4;
			this->input_data_label->Text = L"���� ������ � �������";
			this->input_data_label->Click += gcnew System::EventHandler(this, &MyForm::input_data_label_Click);
			// 
			// settings_label
			// 
			this->settings_label->AutoSize = true;
			this->settings_label->Location = System::Drawing::Point(12, 9);
			this->settings_label->Name = L"settings_label";
			this->settings_label->Size = System::Drawing::Size(79, 17);
			this->settings_label->TabIndex = 5;
			this->settings_label->Text = L"���������";
			// 
			// start_speed_label
			// 
			this->start_speed_label->AutoSize = true;
			this->start_speed_label->Location = System::Drawing::Point(50, 149);
			this->start_speed_label->Name = L"start_speed_label";
			this->start_speed_label->Size = System::Drawing::Size(144, 17);
			this->start_speed_label->TabIndex = 6;
			this->start_speed_label->Text = L"��������� ��������";
			// 
			// angle_label
			// 
			this->angle_label->AutoSize = true;
			this->angle_label->Location = System::Drawing::Point(50, 182);
			this->angle_label->Name = L"angle_label";
			this->angle_label->Size = System::Drawing::Size(88, 17);
			this->angle_label->TabIndex = 7;
			this->angle_label->Text = L"���� ������";
			this->angle_label->Click += gcnew System::EventHandler(this, &MyForm::label4_Click);
			// 
			// fly_time_label
			// 
			this->fly_time_label->AutoSize = true;
			this->fly_time_label->Location = System::Drawing::Point(50, 248);
			this->fly_time_label->Name = L"fly_time_label";
			this->fly_time_label->Size = System::Drawing::Size(101, 17);
			this->fly_time_label->TabIndex = 9;
			this->fly_time_label->Text = L"����� ������";
			this->fly_time_label->Click += gcnew System::EventHandler(this, &MyForm::label5_Click);
			// 
			// distance_label
			// 
			this->distance_label->AutoSize = true;
			this->distance_label->Location = System::Drawing::Point(50, 215);
			this->distance_label->Name = L"distance_label";
			this->distance_label->Size = System::Drawing::Size(130, 17);
			this->distance_label->TabIndex = 8;
			this->distance_label->Text = L"��������� ������";
			this->distance_label->Click += gcnew System::EventHandler(this, &MyForm::label6_Click);
			// 
			// max_height_label
			// 
			this->max_height_label->AutoSize = true;
			this->max_height_label->Location = System::Drawing::Point(53, 278);
			this->max_height_label->Name = L"max_height_label";
			this->max_height_label->Size = System::Drawing::Size(156, 17);
			this->max_height_label->TabIndex = 10;
			this->max_height_label->Text = L"������������ ������";
			// 
			// start_speed_textbox
			// 
			this->start_speed_textbox->Location = System::Drawing::Point(220, 149);
			this->start_speed_textbox->Name = L"start_speed_textbox";
			this->start_speed_textbox->Size = System::Drawing::Size(100, 22);
			this->start_speed_textbox->TabIndex = 11;
			this->start_speed_textbox->TextChanged += gcnew System::EventHandler(this, &MyForm::start_speed_textbox_TextChanged);
			// 
			// angle_textbox
			// 
			this->angle_textbox->Location = System::Drawing::Point(220, 182);
			this->angle_textbox->Name = L"angle_textbox";
			this->angle_textbox->Size = System::Drawing::Size(100, 22);
			this->angle_textbox->TabIndex = 12;
			this->angle_textbox->TextChanged += gcnew System::EventHandler(this, &MyForm::angle_textbox_TextChanged);
			// 
			// fly_time_textbox
			// 
			this->fly_time_textbox->Location = System::Drawing::Point(220, 243);
			this->fly_time_textbox->Name = L"fly_time_textbox";
			this->fly_time_textbox->Size = System::Drawing::Size(100, 22);
			this->fly_time_textbox->TabIndex = 13;
			this->fly_time_textbox->TextChanged += gcnew System::EventHandler(this, &MyForm::fly_time_textbox_TextChanged);
			// 
			// max_height_textbox
			// 
			this->max_height_textbox->Location = System::Drawing::Point(220, 275);
			this->max_height_textbox->Name = L"max_height_textbox";
			this->max_height_textbox->Size = System::Drawing::Size(100, 22);
			this->max_height_textbox->TabIndex = 14;
			this->max_height_textbox->TextChanged += gcnew System::EventHandler(this, &MyForm::max_height_textbox_TextChanged);
			// 
			// distance_textbox
			// 
			this->distance_textbox->Location = System::Drawing::Point(220, 210);
			this->distance_textbox->Name = L"distance_textbox";
			this->distance_textbox->Size = System::Drawing::Size(100, 22);
			this->distance_textbox->TabIndex = 15;
			this->distance_textbox->TextChanged += gcnew System::EventHandler(this, &MyForm::distance_textbox_TextChanged);
			// 
			// calculate_button
			// 
			this->calculate_button->Location = System::Drawing::Point(132, 314);
			this->calculate_button->Name = L"calculate_button";
			this->calculate_button->Size = System::Drawing::Size(188, 37);
			this->calculate_button->TabIndex = 16;
			this->calculate_button->Text = L"����������";
			this->calculate_button->UseVisualStyleBackColor = true;
			this->calculate_button->Click += gcnew System::EventHandler(this, &MyForm::calculate_button_Click);
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(449, 58);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(899, 293);
			this->chart1->TabIndex = 17;
			this->chart1->Text = L"chart1";
			this->chart1->Visible = false;
			// 
			// clear_button
			// 
			this->clear_button->Location = System::Drawing::Point(36, 314);
			this->clear_button->Name = L"clear_button";
			this->clear_button->Size = System::Drawing::Size(90, 37);
			this->clear_button->TabIndex = 18;
			this->clear_button->Text = L"��������";
			this->clear_button->UseVisualStyleBackColor = true;
			this->clear_button->Click += gcnew System::EventHandler(this, &MyForm::clear_button_Click);
			// 
			// start_speed_measure
			// 
			this->start_speed_measure->AutoSize = true;
			this->start_speed_measure->Location = System::Drawing::Point(326, 154);
			this->start_speed_measure->Name = L"start_speed_measure";
			this->start_speed_measure->Size = System::Drawing::Size(119, 17);
			this->start_speed_measure->TabIndex = 19;
			this->start_speed_measure->Text = L"������ / �������";
			// 
			// angle_measure
			// 
			this->angle_measure->AutoSize = true;
			this->angle_measure->Location = System::Drawing::Point(326, 187);
			this->angle_measure->Name = L"angle_measure";
			this->angle_measure->Size = System::Drawing::Size(66, 17);
			this->angle_measure->TabIndex = 20;
			this->angle_measure->Text = L"��������";
			// 
			// distance_measure
			// 
			this->distance_measure->AutoSize = true;
			this->distance_measure->Location = System::Drawing::Point(326, 215);
			this->distance_measure->Name = L"distance_measure";
			this->distance_measure->Size = System::Drawing::Size(55, 17);
			this->distance_measure->TabIndex = 21;
			this->distance_measure->Text = L"������";
			// 
			// fly_time_measure
			// 
			this->fly_time_measure->AutoSize = true;
			this->fly_time_measure->Location = System::Drawing::Point(326, 248);
			this->fly_time_measure->Name = L"fly_time_measure";
			this->fly_time_measure->Size = System::Drawing::Size(53, 17);
			this->fly_time_measure->TabIndex = 22;
			this->fly_time_measure->Text = L"������";
			// 
			// max_height_measure
			// 
			this->max_height_measure->AutoSize = true;
			this->max_height_measure->Location = System::Drawing::Point(326, 280);
			this->max_height_measure->Name = L"max_height_measure";
			this->max_height_measure->Size = System::Drawing::Size(55, 17);
			this->max_height_measure->TabIndex = 23;
			this->max_height_measure->Text = L"������";
			// 
			// clear_graph
			// 
			this->clear_graph->Location = System::Drawing::Point(449, 13);
			this->clear_graph->Name = L"clear_graph";
			this->clear_graph->Size = System::Drawing::Size(264, 39);
			this->clear_graph->TabIndex = 24;
			this->clear_graph->Text = L"�������� ������";
			this->clear_graph->UseVisualStyleBackColor = true;
			this->clear_graph->Visible = false;
			this->clear_graph->Click += gcnew System::EventHandler(this, &MyForm::clear_graph_Click);
			// 
			// real_time_mode_checkbox
			// 
			this->real_time_mode_checkbox->AutoSize = true;
			this->real_time_mode_checkbox->Location = System::Drawing::Point(730, 30);
			this->real_time_mode_checkbox->Name = L"real_time_mode_checkbox";
			this->real_time_mode_checkbox->Size = System::Drawing::Size(275, 21);
			this->real_time_mode_checkbox->TabIndex = 25;
			this->real_time_mode_checkbox->Text = L"�������� � ������������ � ��������";
			this->real_time_mode_checkbox->UseVisualStyleBackColor = true;
			this->real_time_mode_checkbox->CheckedChanged += gcnew System::EventHandler(this, &MyForm::real_time_mode_checkbox_CheckedChanged);
			// 
			// save_button
			// 
			this->save_button->Location = System::Drawing::Point(36, 443);
			this->save_button->Name = L"save_button";
			this->save_button->Size = System::Drawing::Size(284, 37);
			this->save_button->TabIndex = 26;
			this->save_button->Text = L"��������� � ����";
			this->save_button->UseVisualStyleBackColor = true;
			this->save_button->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// g_measure
			// 
			this->g_measure->AutoSize = true;
			this->g_measure->Location = System::Drawing::Point(335, 24);
			this->g_measure->Name = L"g_measure";
			this->g_measure->Size = System::Drawing::Size(82, 17);
			this->g_measure->TabIndex = 29;
			this->g_measure->Text = L"������ / c2";
			// 
			// g_textbox
			// 
			this->g_textbox->Location = System::Drawing::Point(229, 24);
			this->g_textbox->Name = L"g_textbox";
			this->g_textbox->Size = System::Drawing::Size(100, 22);
			this->g_textbox->TabIndex = 28;
			this->g_textbox->TextChanged += gcnew System::EventHandler(this, &MyForm::g_textbox_TextChanged);
			// 
			// g_label
			// 
			this->g_label->AutoSize = true;
			this->g_label->Location = System::Drawing::Point(201, 27);
			this->g_label->Name = L"g_label";
			this->g_label->Size = System::Drawing::Size(19, 17);
			this->g_label->TabIndex = 27;
			this->g_label->Text = L"G";
			// 
			// information_button
			// 
			this->information_button->Location = System::Drawing::Point(338, 443);
			this->information_button->Name = L"information_button";
			this->information_button->Size = System::Drawing::Size(90, 37);
			this->information_button->TabIndex = 30;
			this->information_button->Text = L"�������";
			this->information_button->UseVisualStyleBackColor = true;
			this->information_button->Click += gcnew System::EventHandler(this, &MyForm::information_button_Click);
			// 
			// get_max_distance_button
			// 
			this->get_max_distance_button->Location = System::Drawing::Point(36, 357);
			this->get_max_distance_button->Name = L"get_max_distance_button";
			this->get_max_distance_button->Size = System::Drawing::Size(284, 37);
			this->get_max_distance_button->TabIndex = 31;
			this->get_max_distance_button->Text = L"�������� ������������ �������������";
			this->get_max_distance_button->UseVisualStyleBackColor = true;
			this->get_max_distance_button->Click += gcnew System::EventHandler(this, &MyForm::get_max_distance_button_Click);
			// 
			// get_max_height_button
			// 
			this->get_max_height_button->Location = System::Drawing::Point(36, 400);
			this->get_max_height_button->Name = L"get_max_height_button";
			this->get_max_height_button->Size = System::Drawing::Size(284, 37);
			this->get_max_height_button->TabIndex = 32;
			this->get_max_height_button->Text = L"�������� ������������ ������";
			this->get_max_height_button->UseVisualStyleBackColor = true;
			this->get_max_height_button->Click += gcnew System::EventHandler(this, &MyForm::get_max_height_button_Click);
			// 
			// save_chart_button
			// 
			this->save_chart_button->Location = System::Drawing::Point(449, 378);
			this->save_chart_button->Name = L"save_chart_button";
			this->save_chart_button->Size = System::Drawing::Size(284, 37);
			this->save_chart_button->TabIndex = 33;
			this->save_chart_button->Text = L"��������� ������ � ����";
			this->save_chart_button->UseVisualStyleBackColor = true;
			this->save_chart_button->Click += gcnew System::EventHandler(this, &MyForm::save_chart_button_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1383, 489);
			this->Controls->Add(this->save_chart_button);
			this->Controls->Add(this->get_max_height_button);
			this->Controls->Add(this->get_max_distance_button);
			this->Controls->Add(this->information_button);
			this->Controls->Add(this->g_measure);
			this->Controls->Add(this->g_textbox);
			this->Controls->Add(this->g_label);
			this->Controls->Add(this->save_button);
			this->Controls->Add(this->real_time_mode_checkbox);
			this->Controls->Add(this->clear_graph);
			this->Controls->Add(this->max_height_measure);
			this->Controls->Add(this->fly_time_measure);
			this->Controls->Add(this->distance_measure);
			this->Controls->Add(this->angle_measure);
			this->Controls->Add(this->start_speed_measure);
			this->Controls->Add(this->clear_button);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->calculate_button);
			this->Controls->Add(this->distance_textbox);
			this->Controls->Add(this->max_height_textbox);
			this->Controls->Add(this->fly_time_textbox);
			this->Controls->Add(this->angle_textbox);
			this->Controls->Add(this->start_speed_textbox);
			this->Controls->Add(this->max_height_label);
			this->Controls->Add(this->fly_time_label);
			this->Controls->Add(this->distance_label);
			this->Controls->Add(this->angle_label);
			this->Controls->Add(this->start_speed_label);
			this->Controls->Add(this->settings_label);
			this->Controls->Add(this->input_data_label);
			this->Controls->Add(this->change_bgcolor_button);
			this->Controls->Add(this->lang_combobox);
			this->Controls->Add(this->lang_label);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"  ";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void lang_combobox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
			change_language();
		}

		   //������� ��� ����� �����
	private: System::Void change_language()
	{
		this->lang = lang_combobox->SelectedItem->ToString();

		if (lang == "�������")
		{
			this->Text = "�������������� ��������";

			settings_label->Text = "���������";

			lang_label->Text = "����";
			change_bgcolor_button->Text = "�������� ���� ����";
			g_measure->Text = "������ / �2";

			input_data_label->Text = "���� ������ � �������";

			start_speed_label->Text = "��������� ��������";
			angle_label->Text = "���� ������";
			distance_label->Text = "��������� ������";
			fly_time_label->Text = "����� ������";
			max_height_label->Text = "������������ ������";

			start_speed_measure->Text = "������ / �������";
			angle_measure->Text = "��������";
			distance_measure->Text = "������";
			fly_time_measure->Text = "������";
			max_height_measure->Text = "������";

			clear_button->Text = "��������";
			clear_graph->Text = "�������� ������";
			real_time_mode_checkbox->Text = "�������� � ������������ � �������� ��������";
			calculate_button->Text = "����������";
			save_button->Text = "��������� � ����";
			get_max_distance_button->Text = "�������� ������������ ����������";
			get_max_height_button->Text = "�������� ������������ ������";


			chart1->Series[0]->LegendText = "���������� ������ �������";
			chart1->ChartAreas[0]->AxisX->Title = "����������";
			chart1->ChartAreas[0]->AxisY->Title = "������";


			error_msg = "������";
			invalid_format_msg = "������������ ������";
			information_button->Text = "�������";

			save_chart_button->Text = "��������� ������ ���";
		}
		else if (lang == "English")
		{
			this->Text = "Projectile movement";

			settings_label->Text = "Settings";

			lang_label->Text = "Language";
			change_bgcolor_button->Text = "Change background color";
			g_measure->Text = "meters / s2";


			input_data_label->Text = "Entering projectile data";

			start_speed_label->Text = "Start speed";
			angle_label->Text = "Throw angle";
			distance_label->Text = "Flight distance";
			fly_time_label->Text = "Flight time";
			max_height_label->Text = "Max height";

			start_speed_measure->Text = "meters / second";
			angle_measure->Text = "degrees";
			distance_measure->Text = "meters";
			fly_time_measure->Text = "seconds";
			max_height_measure->Text = "meters";

			clear_button->Text = "Clear";
			clear_graph->Text = "Clear graph";
			real_time_mode_checkbox->Text = "Draw in real time";
			calculate_button->Text = "Calculate";
			save_button->Text = "Save into file";
			get_max_distance_button->Text = "Get max distance";
			get_max_height_button->Text = "Get max height";

			chart1->Series[0]->LegendText = "Projectile trajectory";
			chart1->ChartAreas[0]->AxisX->Title = "Distance";
			chart1->ChartAreas[0]->AxisY->Title = "Height";

			error_msg = "Error";
			invalid_format_msg = "Invalid format";
			information_button->Text = "Reference";

			save_chart_button->Text = "Save graph as image";

		}
		else if (lang == "����������")
		{
			this->Text = "���������� ���";


			settings_label->Text = "������";

			lang_label->Text = "����";
			change_bgcolor_button->Text = "������ ����� ����";
			g_measure->Text = "����� / �2";


			input_data_label->Text = "���� �������� �� ��������";

			start_speed_label->Text = "���������� ��������";
			angle_label->Text = "��� ����";
			distance_label->Text = "�������� �����";
			fly_time_label->Text = "������ �����";
			max_height_label->Text = "����������� ������";

			start_speed_measure->Text = "����� / �������";
			angle_measure->Text = "�������";
			distance_measure->Text = "�����";
			fly_time_measure->Text = "������";
			max_height_measure->Text = "�����";

			clear_button->Text = "��������";
			clear_graph->Text = "�������� ������";
			real_time_mode_checkbox->Text = "�������� � ������������ � �������� �����";
			calculate_button->Text = "��������";
			save_button->Text = "�������� � ����";
			get_max_distance_button->Text = "�������� ����������� ����������";
			get_max_height_button->Text = "�������� ����������� ������";

			chart1->Series[0]->LegendText = "���������� ����� �������";
			chart1->ChartAreas[0]->AxisX->Title = "����������";
			chart1->ChartAreas[0]->AxisY->Title = "������";

			error_msg = "�������";
			invalid_format_msg = "���������� ������";
			information_button->Text = "�������";

			save_chart_button->Text = "�������� ���� ��";

		}
	}

		   //������ ��� ����� ����� ����
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		ColorDialog^ MyDialog = gcnew ColorDialog(); //����� ����, ��� ����� ������� ����
		MyDialog->Color = this->BackColor; // �������� ������� ����

		if (MyDialog->ShowDialog().ToString() == "OK") //���� ������������ ����� ��, �� ������� ���� ���� �� ��������� ����
			this->BackColor = MyDialog->Color;
	}
	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void calculate_button_Click(System::Object^ sender, System::EventArgs^ e) {
		double start_speed = 0;
		double angle = 0;
		double distance = 0;
		double fly_time = 0;
		double max_height = 0;
		//��� ���������� ����� ��� �������� ������������� 
		bool start_speed_init = false, angle_init = false, distance_init = false, fly_time_init = false, max_height_init = false;

		//������� ��� ������ � ������� ��� std::string, �������������� ����� ��� "���������" �������
		std::string start_speed_str = marshal_as<std::string>(start_speed_textbox->Text->Replace(" ", ""));
		std::string angle_str = marshal_as<std::string>(angle_textbox->Text->Replace(" ", ""));
		std::string distance_str = marshal_as<std::string>(distance_textbox->Text->Replace(" ", ""));
		std::string fly_time_str = marshal_as<std::string>(fly_time_textbox->Text->Replace(" ", ""));
		std::string max_height_str = marshal_as<std::string>(max_height_textbox->Text->Replace(" ", ""));

		bool error_called = false;//��� ����, ����� ���� � ������� �� ���������� ����� ���

		//�������� �����

		if (start_speed_str != "")
		{
			try {
				//���������� ������� std::stod ��� �������� std::string � double
				start_speed = std::stod(start_speed_str);
				start_speed_init = true;
			}
			catch (...) {
				start_speed_textbox->BackColor = System::Drawing::Color::Red;

				MessageBox::Show(this, invalid_format_msg, error_msg, MessageBoxButtons::OK, MessageBoxIcon::Error);
				error_called = true;
			}
		}
		if (angle_str != "")
		{
			try {
				//���������� ������� std::stod ��� �������� std::string � double
				angle = std::stod(angle_str);
				angle_init = true;
			}
			catch (...) {
				angle_textbox->BackColor = System::Drawing::Color::Red;

				if (!error_called)
					MessageBox::Show(this, invalid_format_msg, error_msg, MessageBoxButtons::OK, MessageBoxIcon::Error);
				error_called = true;
			}
		}
		if (distance_str != "")
		{
			try {
				//���������� ������� std::stod ��� �������� std::string � double
				distance = std::stod(distance_str);
				distance_init = true;
			}
			catch (...) {
				distance_textbox->BackColor = System::Drawing::Color::Red;

				if (!error_called)
					MessageBox::Show(this, invalid_format_msg, error_msg, MessageBoxButtons::OK, MessageBoxIcon::Error);
				error_called = true;
			}
		}
		if (fly_time_str != "")
		{
			try {
				//���������� ������� std::stod ��� �������� std::string � double
				fly_time = std::stod(fly_time_str);
				fly_time_init = true;
			}
			catch (...) {
				fly_time_textbox->BackColor = System::Drawing::Color::Red;

				if (!error_called)
					MessageBox::Show(this, invalid_format_msg, error_msg, MessageBoxButtons::OK, MessageBoxIcon::Error);
				error_called = true;
			}
		}
		if (max_height_str != "")
		{
			try {
				//���������� ������� std::stod ��� �������� std::string � double
				max_height = std::stod(max_height_str);
				max_height_init = true;
			}
			catch (...) {
				max_height_textbox->BackColor = System::Drawing::Color::Red;

				if (!error_called)
					MessageBox::Show(this, invalid_format_msg, error_msg, MessageBoxButtons::OK, MessageBoxIcon::Error);
				error_called = true;
			}
		}


		//���� ��������� ������, ������� �� �������
		if (error_called)
			return;

		start_speed_textbox->BackColor = System::Drawing::Color::White;
		angle_textbox->BackColor = System::Drawing::Color::White;
		distance_textbox->BackColor = System::Drawing::Color::White;
		fly_time_textbox->BackColor = System::Drawing::Color::White;
		max_height_textbox->BackColor = System::Drawing::Color::White;

		double angle_rad = angle * pi / 180.0; // ���� � ��������
		
		//������ ��������� �������� � ����
		if ((last_changed1[0] || last_changed2[0]) && (last_changed1[1] || last_changed2[1]))
		{
			//������ ���������
			//������� ����������� � ������� � ������� ������� ������� = ������� * 3.14 / 180
			distance = abs(start_speed * start_speed * sin(2 * angle_rad) / g);

			//������ ������������ ������
			max_height = start_speed * start_speed * pow(sin(angle_rad), 2) / (2 * g);

			//������ �������
			fly_time = 2 * start_speed * sin(angle * pi / 180.0) / g;
		}
		//���� � ����������
		else if ((last_changed1[1] || last_changed2[1]) && (last_changed1[2] || last_changed2[2]))
		{
			//������ �������� 
			start_speed = sqrt(
				g * distance * distance /
				(2.0 * (distance * tan(angle_rad)))
					) / cos(angle_rad);

			//������ ������������ ������
			max_height = start_speed * start_speed * pow(sin(angle_rad), 2) / (2 * g);

			//������ �������
			fly_time = 2 * start_speed * sin(angle_rad) / g;
		}
		else 
		if (start_speed_init && angle_init)
		{
			//������ ���������
			//������� ����������� � ������� � ������� ������� ������� = ������� * 3.14 / 180
			distance = abs(start_speed * start_speed * sin(2 * angle * pi / 180.0) / g);

			//������ ������������ ������
			max_height = start_speed * start_speed * pow(sin(angle * pi / 180.0), 2) / (2 * g);

			//������ �������
			fly_time = 2 * start_speed * sin(angle * pi / 180.0) / g;
		}
		else if (angle_init && distance_init)
		{
			//������ �������� 
			start_speed = sqrt(
				g * distance * distance /
				(2.0 * (distance * tan(angle_rad)))
			) / cos(angle_rad);

			//������ ������������ ������
			max_height = start_speed * start_speed * pow(sin(angle_rad), 2) / (2 * g);

			//������ �������
			fly_time = 2 * start_speed * sin(angle_rad) / g;
		}
		else
		{
			if (lang == "�������")
			{
				if (angle_init)
				{
					MessageBox::Show(this, "������������ ������! ������� ��� ���������� ���� ��������� ��������!", "��������������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
				else if (distance_init || start_speed_init)
				{
					MessageBox::Show(this, "������������ ������! ������� ��� ����!", "��������������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
				else
				{
					MessageBox::Show(this, "������������ ������! ������� ��� ���� � ��������!", "��������������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
			}
			else if (lang == "English")
			{
				if (angle_init)
				{
					MessageBox::Show(this, "Not enough data! Enter another distance or starting speed!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
				else if (distance_init || start_speed_init)
				{
					MessageBox::Show(this, "Not enough data! Enter another angle!", "��������������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
				else
				{
					MessageBox::Show(this, "Not enough data!Enter more angle and speed!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
			}
			else if (lang == "����������")
			{
				if (angle_init)
				{
					MessageBox::Show(this, "������������ ��������! ������� ���� ���������� ����� ���������� ��������!", "������������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
				else if (distance_init || start_speed_init)
				{
					MessageBox::Show(this, "������������ ��������! ������� ���� ���!", "������������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
				else
				{
					MessageBox::Show(this, "������������ ��������! ������� ���� ��� � ��������!", "������������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
			}
			
		}

		block = true;
		start_speed_textbox->Text = marshal_as<String^>(std::to_string(start_speed));
		angle_textbox->Text = marshal_as<String^>(std::to_string(angle));
		distance_textbox->Text = marshal_as<String^>(std::to_string(distance));
		fly_time_textbox->Text = marshal_as<String^>(std::to_string(fly_time));
		max_height_textbox->Text = marshal_as<String^>(std::to_string(max_height));
		block = false;

		create_trajectory(start_speed, angle, fly_time, max_height, distance);
	}
	private: System::Void create_trajectory(double start_speed, double angle, double fly_time, double max_height, double distance)
	{
		chart1->Visible = true;
		clear_graph->Visible = true;
		chart1->Series[0]->ChartType = SeriesChartType::Line;
		chart1->Series[0]->MarkerStyle = MarkerStyle::Circle;


		double x, y;
		double t = 0.0;
		chart1->Series[0]->Color = System::Drawing::Color::Blue; //���� �����
		chart1->Series[0]->BorderWidth = 2; //������ �����

		auto start = std::chrono::system_clock::now();

		double step = fly_time / 100.0;
		double angle_radians = angle * pi / 180.0;

		int j = 0;
		if (real_time_mode_checkbox->Checked)
		{

			while (t < fly_time)
			{
				x = start_speed * t * cos(angle_radians);
				y = start_speed * t * sin(angle_radians) - g * t * t / 2.0;
				String^ x_str = x.ToString();
				String^ y_str = y.ToString();

				if (x_str->IndexOf(",") != -1) {
					x_str = x_str->Substring(0, x_str->IndexOf(","))
						+ x_str->Substring(x_str->IndexOf(","), 3);
					x = std::stod(marshal_as<std::string>(
						x_str->Replace(",", ".")
						));
				}

				if (y_str->IndexOf(",") != -1) {
					y_str = y_str->Substring(0, y_str->IndexOf(","))
						+ y_str->Substring(y_str->IndexOf(","), 3);


					y = std::stod(marshal_as<std::string>(
						y_str->Replace(",", ".")
						));
				}

				chart1->Series[0]->Points->AddXY(x, y);
				if (j % 10 == 0)
				{
					chart1->Update(); //������� ��������� ������� ������

					std::this_thread::sleep_until(start + std::chrono::milliseconds((int)t * 1000)); //��� ���� ����� �� ������ �� ��������� ����������
				}

				/*else
				  std::this_thread::sleep_for(std::chrono::milliseconds((int)(t*300)));*/
				t += step;
			}
		}
		else
		{
			while (t < fly_time)
			{
				x = start_speed * t * cos(angle_radians);
				y = start_speed * t * sin(angle_radians) - g * t * t / 2.0;

				String^ x_str = x.ToString();
				String^ y_str = y.ToString();

				if (x_str->IndexOf(",") != -1) {
					x_str = x_str->Substring(0, x_str->IndexOf(","))
						+ x_str->Substring(x_str->IndexOf(","), 3);
					x = std::stod(marshal_as<std::string>(
						x_str->Replace(",", ".")
						));
				}

				if (y_str->IndexOf(",") != -1) {
					y_str = y_str->Substring(0, y_str->IndexOf(","))
						+ y_str->Substring(y_str->IndexOf(","), 3);


					y = std::stod(marshal_as<std::string>(
						y_str->Replace(",", ".")
						));
				}

				chart1->Series[0]->Points->AddXY(x, y);
				if (j % 5 == 0)
					chart1->Update(); //������� ��������� ������� ������

				   //std::this_thread::sleep_until(start + std::chrono::milliseconds((int)t * 1000)); //��� ���� ����� �� ������ �� ��������� ����������
			 /*else
			   std::this_thread::sleep_for(std::chrono::milliseconds((int)(t*300)));*/
				t += step;
			}
		}



		// chart1->ChartAreas[0]->InnerPlotPosition->Y = distance * chart1->ChartAreas[0]->InnerPlotPosition->Height;
		 //chart1->ChartAreas[0]->InnerPlotPosition->X = distance * chart1->ChartAreas[0]->InnerPlotPosition->Height;

		// chart1->Series[0]->X

		 //makeSquare(max_height, distance);
	}

		   //������� ��� ������� ����� �����
	private: System::Void clear_button_Click(System::Object^ sender, System::EventArgs^ e) {
		start_speed_textbox->Text = "";
		angle_textbox->Text = "";
		distance_textbox->Text = "";
		fly_time_textbox->Text = "";
		max_height_textbox->Text = "";
	}
	private: System::Void input_data_label_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void clear_graph_Click(System::Object^ sender, System::EventArgs^ e) {
		chart1->Series[0]->Points->Clear();
	}
	private: System::Void real_time_mode_checkbox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
		FolderBrowserDialog^ fbd = gcnew FolderBrowserDialog();
		fbd->RootFolder = Environment::SpecialFolder::Desktop;
		if (lang == "�������")
		{
			fbd->Description = "�������� �����, � ������� ����� ������� ����";
		}
		else if (lang == "����������")
		{
			fbd->Description = "������� �����, � ���� ����� �������� ����";
		}
		else if (lang == "English")
		{
			fbd->Description = "Select the folder where the file will be saved";
		}
		
		fbd->ShowNewFolderButton = 0;

		String^ path_; // ������ ���������� ��� �������� ���������� ����

		if (fbd->ShowDialog() == System::Windows::Forms::DialogResult::OK) //���������� ��������� ���� ��� ������
		{
			path_ = fbd->SelectedPath; //����������� ���������� path ��������� ���� � �����
		}
		path_ += "\\results.txt"; // ������ ������������ ����� ���� � �����
		std::string path;
		path = msclr::interop::marshal_as<std::string>(path_); // ����������� String^ � string ��� ������������� � ifstream
		
		std::ofstream file;
		file.open(path);

		if (file.is_open())
		{
			std::string to_write;
			if (lang == "�������")
			{
				to_write = "��������� ��������: ";
				to_write += marshal_as<std::string>(start_speed_textbox->Text) + " ������ / �������";
				to_write += "\n���� ������: ";
				to_write += marshal_as<std::string>(angle_textbox->Text) + " ��������";
				to_write += "\n��������� ������: ";
				to_write += marshal_as<std::string>(start_speed_textbox->Text) + " ������";
				to_write += "\n����� ������: ";
				to_write += marshal_as<std::string>(fly_time_textbox->Text) + " ������";
				to_write += "\n������������ ������: ";
				to_write += marshal_as<std::string>(max_height_textbox->Text) + " ������";
			}
			else if (lang == "����������")
			{
				to_write = "���������� ��������: ";
				to_write += marshal_as<std::string>(start_speed_textbox->Text) + " ����� / �������";
				to_write += "\n��� ����: ";
				to_write += marshal_as<std::string>(angle_textbox->Text) + " �������";
				to_write += "\n�������� �����: ";
				to_write += marshal_as<std::string>(start_speed_textbox->Text) + " �����";
				to_write += "\n������ �����: ";
				to_write += marshal_as<std::string>(fly_time_textbox->Text) + " ������";
				to_write += "\n����������� ������: ";
				to_write += marshal_as<std::string>(max_height_textbox->Text) + " �����";
			}
			else if (lang == "English")
			{
				to_write = "Start speed: ";
				to_write += marshal_as<std::string>(start_speed_textbox->Text) + " meters / second";
				to_write += "\nAngle: ";
				to_write += marshal_as<std::string>(angle_textbox->Text) + " degrees";
				to_write += "\nDistance: ";
				to_write += marshal_as<std::string>(start_speed_textbox->Text) + " meters";
				to_write += "\nFly time: ";
				to_write += marshal_as<std::string>(fly_time_textbox->Text) + " seconds";
				to_write += "\n��x height: ";
				to_write += marshal_as<std::string>(max_height_textbox->Text) + " meters";
			}
			
			file << to_write;

			std::string message;
			std::string label;

			if (lang == "�������")
			{
				message = "������ ��������� � ���� '" + path + "'";
				label = "�����";
			}
			else if (lang == "����������")
			{
				message = "�������� �������� � ���� '" + path + "'";
				label = "������";
			}
			else if (lang == "English")
			{
				message = "Data was saved into file '" + path + "'";
				label = "Success";
			}
			MessageBox::Show(this, marshal_as<String^>(message), marshal_as<String^>(label), MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else
		{
			std::string message;
			std::string label;
			if (lang == "�������")
			{
				message = "�� ������� ������� ���� '" + path + "'";
				label = "������";
			}
			else if (lang == "����������")
			{
				message = "�� ���������� ������� ���� '" + path + "'";
				label = "�������";
			}
			else if (lang == "English")
			{
				message = "Could not open file '" + path + "'";
				label = "Failure";
			}
			MessageBox::Show(this, marshal_as<String^>(message), marshal_as<String^>(label), MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		file.close();
	}
	private: System::Void information_button_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string info = "";
		std::string label = "";
		if (lang == "�������")
		{
			info += "��������� ����������� �������������� �������� �������, ���������� ��� ������������ �����.\n";
			info += "\n��� ������� �������� ���������� ������ ��������� �������� � ����, ��� ������� ��� ������ ������\n";
			info += "\n����� �������� ���� ���� � ����������\n";

			info += "\n����� �������� ����� ��������� ����������, ����� ���������� �� �� �������\n";
			info += "\n������������� ����� �������� ���� �������, ����, ��������, ������ ���������� �� ������ �������\n";
			info += "\n����� ����������� �������� ��������, ����� �� ������� '�������� � ������������ � ��������'\n";

			info += "\n\n�����������: ";

			save_chart_button->Text = "��������� ������ � ����";


			label += "�������";

		}
		else if (lang == "����������")
		{
			info += "�������� ��������� ���������� ��� �������, ������� ��� ������ ������\n";
			info += "\n��� ������ ���� ������ ������ ���������� �������� � ���, ��� ��� ��� ����� ��'���\n";
			info += "\n������� ������� ���� ���� � ����������\n";
			info += "\n����� �������� ������ ������� ����������, ��� ��������� �� �� ������\n";
			info += "\n������������� ���� ������� ��� ������, ���, ��������, ���� ���������� �� ����� �������\n";
			info += "\n����� ��������� ������� ���, ��������� �� ������� '�������� � ������������ � �����'\n";

			info += "\n\n�����������:";



			save_chart_button->Text = "��������� ������ � ����";

			label += "�������";

		}
		else if (lang == "English")
		{
			info += "The program calculates the ballistic movement of a projectile thrown at a certain angle\n";
			info += "\nTo calculate the motion, it is enough to enter the initial speed and the angle at which the object was thrown\n";
			info += "\nIt is also possible to enter angle and distance\n";

			info += "\nYou can draw several paths at once to correlate them in size \ n";
			info += "\nAdministrator can change the force of gravity, if, for example, the throw occurs on another planet\n";
			info += "\nYou can emulate real movement by clicking on the 'Draw according to time' checkbox '\n";
			info += "\n\nnDeveloper:";

			


			label += "Reference";

		}
		MessageBox::Show(this, marshal_as<String^>(info), marshal_as<String^>(label), MessageBoxButtons::OK, MessageBoxIcon::Information);

	}
private: System::Void g_textbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	try
	{
		this->g = std::stod(marshal_as<std::string>(g_textbox->Text));
	}
	catch (...)
	{
		this->g = 9.8;
	}
}

	private: System::Void start_speed_textbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (last_changed1[0] || block)
			return;
		for (size_t i = 0; i < 5; i++)
			last_changed2[i] = last_changed1[i];
		for (size_t i = 0; i < 5; i++)
			last_changed1[i] = false;
		last_changed1[0] = true;
	}
	private: System::Void angle_textbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (last_changed1[1] || block)
			return;
		for (size_t i = 0; i < 5; i++)
			last_changed2[i] = last_changed1[i];
		for (size_t i = 0; i < 5; i++)
			last_changed1[i] = false;
		last_changed1[1] = true;
	}
	private: System::Void distance_textbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (last_changed1[2] || block)
			return;
		for (size_t i = 0; i < 5; i++) 
			last_changed2[i] = last_changed1[i];
		for (size_t i = 0; i < 5; i++)
			last_changed1[i] = false;
		last_changed1[2] = true;
	}
	private: System::Void fly_time_textbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (last_changed1[3] || block)
			return;
		for (size_t i = 0; i < 5; i++)
			last_changed2[i] = last_changed1[i];
		for (size_t i = 0; i < 5; i++)
			last_changed1[i] = false;
		last_changed1[3] = true;
	}
	private: System::Void max_height_textbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (last_changed1[4] || block)
			return;
		for (size_t i = 0; i < 5; i++)
			last_changed2[i] = last_changed1[i];
		for (size_t i = 0; i < 5; i++)
			last_changed1[i] = false;
		last_changed1[4] = true;
	}
private: System::Void get_max_distance_button_Click(System::Object^ sender, System::EventArgs^ e) {
	this->angle_textbox->Text = "45";
}
private: System::Void get_max_height_button_Click(System::Object^ sender, System::EventArgs^ e) {
	this->angle_textbox->Text = "90";
}
private: System::Void save_chart_button_Click(System::Object^ sender, System::EventArgs^ e) {
	FolderBrowserDialog^ fbd = gcnew FolderBrowserDialog();
	fbd->RootFolder = Environment::SpecialFolder::Desktop;
	if (lang == "�������")
	{
		fbd->Description = "�������� �����, � ������� ����� ������� ����";
	}
	else if (lang == "����������")
	{
		fbd->Description = "������� �����, � ���� ����� �������� ����";
	}
	else if (lang == "English")
	{
		fbd->Description = "Select the folder where the file will be saved";
	}

	fbd->ShowNewFolderButton = 0;

	if (fbd->ShowDialog() == System::Windows::Forms::DialogResult::OK) //���������� ��������� ���� ��� ������
	{
		String^ path = fbd->SelectedPath; //����������� ���������� path ��������� ���� � �����
		path += "\\chart.jpg"; // ������ ������������ ����� ���� � �����
		this->chart1->SaveImage(path, ChartImageFormat::Jpeg);

		std::string message;
		std::string label;

		if (lang == "�������")
		{
			message = "������ �������� � ���� '" + marshal_as<std::string>(path) + "'";
			label = "�����";
		}
		else if (lang == "����������")
		{
			message = "������ �������� � ���� '" + marshal_as<std::string>(path) + "'";
			label = "�����";
		}
		else if (lang == "English")
		{
			message = "Chart was saved into file '" + marshal_as<std::string>(path) + "'";
			label = "Success";
		}
		MessageBox::Show(this, marshal_as<String^>(message), marshal_as<String^>(label), MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	
}
};
	};
