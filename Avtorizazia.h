#pragma once
#include "MyForm.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

namespace BallisticMovement {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Avtorizazia
	/// </summary>
	public ref class Avtorizazia : public System::Windows::Forms::Form
	{
	public:
		Avtorizazia(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//

			this->lang = "Русский";

			lang_combobox->Items->Add("Русский");
			lang_combobox->Items->Add("English");
			lang_combobox->Items->Add("Беларуская");

			lang_combobox->SelectedItem = lang_combobox->Items[0];
			change_language();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Avtorizazia()
		{
			if (components)
			{
				delete components;
			}
			Application::Exit();
		}
	private: String^ lang;
	private: System::Windows::Forms::TextBox^ login_textbox;
	protected:
	private: System::Windows::Forms::Label^ title_label;
	private: System::Windows::Forms::TextBox^ password_textbox;
	private: System::Windows::Forms::Label^ login_label;
	private: System::Windows::Forms::ComboBox^ lang_combobox;
	private: System::Windows::Forms::Label^ lang_label;
	private: System::Windows::Forms::Label^ password_label;
	private: System::Windows::Forms::Button^ enter_button;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->login_textbox = (gcnew System::Windows::Forms::TextBox());
			this->title_label = (gcnew System::Windows::Forms::Label());
			this->password_textbox = (gcnew System::Windows::Forms::TextBox());
			this->login_label = (gcnew System::Windows::Forms::Label());
			this->lang_combobox = (gcnew System::Windows::Forms::ComboBox());
			this->lang_label = (gcnew System::Windows::Forms::Label());
			this->password_label = (gcnew System::Windows::Forms::Label());
			this->enter_button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// login_textbox
			// 
			this->login_textbox->Location = System::Drawing::Point(129, 161);
			this->login_textbox->Name = L"login_textbox";
			this->login_textbox->Size = System::Drawing::Size(135, 22);
			this->login_textbox->TabIndex = 0;
			this->login_textbox->TextChanged += gcnew System::EventHandler(this, &Avtorizazia::login_textbox_TextChanged);
			// 
			// title_label
			// 
			this->title_label->AutoSize = true;
			this->title_label->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->title_label->Location = System::Drawing::Point(43, 81);
			this->title_label->Name = L"title_label";
			this->title_label->Size = System::Drawing::Size(250, 30);
			this->title_label->TabIndex = 1;
			this->title_label->Text = L"Войдите в систему";
			this->title_label->Click += gcnew System::EventHandler(this, &Avtorizazia::title_label_Click);
			// 
			// password_textbox
			// 
			this->password_textbox->Location = System::Drawing::Point(129, 219);
			this->password_textbox->Name = L"password_textbox";
			this->password_textbox->PasswordChar = '*';
			this->password_textbox->Size = System::Drawing::Size(135, 22);
			this->password_textbox->TabIndex = 2;
			this->password_textbox->TextChanged += gcnew System::EventHandler(this, &Avtorizazia::password_textbox_TextChanged);
			// 
			// login_label
			// 
			this->login_label->AutoSize = true;
			this->login_label->Location = System::Drawing::Point(35, 161);
			this->login_label->Name = L"login_label";
			this->login_label->Size = System::Drawing::Size(47, 17);
			this->login_label->TabIndex = 3;
			this->login_label->Text = L"Логин";
			this->login_label->Click += gcnew System::EventHandler(this, &Avtorizazia::login_label_Click);
			// 
			// lang_combobox
			// 
			this->lang_combobox->FormattingEnabled = true;
			this->lang_combobox->Location = System::Drawing::Point(12, 33);
			this->lang_combobox->Name = L"lang_combobox";
			this->lang_combobox->Size = System::Drawing::Size(121, 24);
			this->lang_combobox->TabIndex = 5;
			this->lang_combobox->SelectedIndexChanged += gcnew System::EventHandler(this, &Avtorizazia::lang_combobox_SelectedIndexChanged);
			// 
			// lang_label
			// 
			this->lang_label->AutoSize = true;
			this->lang_label->Location = System::Drawing::Point(12, 12);
			this->lang_label->Name = L"lang_label";
			this->lang_label->Size = System::Drawing::Size(42, 17);
			this->lang_label->TabIndex = 4;
			this->lang_label->Text = L"Язык";
			this->lang_label->Click += gcnew System::EventHandler(this, &Avtorizazia::lang_label_Click);
			// 
			// password_label
			// 
			this->password_label->AutoSize = true;
			this->password_label->Location = System::Drawing::Point(35, 222);
			this->password_label->Name = L"password_label";
			this->password_label->Size = System::Drawing::Size(57, 17);
			this->password_label->TabIndex = 6;
			this->password_label->Text = L"Пароль";
			this->password_label->Click += gcnew System::EventHandler(this, &Avtorizazia::password_label_Click);
			// 
			// enter_button
			// 
			this->enter_button->Location = System::Drawing::Point(62, 264);
			this->enter_button->Name = L"enter_button";
			this->enter_button->Size = System::Drawing::Size(189, 35);
			this->enter_button->TabIndex = 7;
			this->enter_button->Text = L"Войти";
			this->enter_button->UseVisualStyleBackColor = true;
			this->enter_button->Click += gcnew System::EventHandler(this, &Avtorizazia::enter_button_Click);
			// 
			// Avtorizazia
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(332, 311);
			this->Controls->Add(this->enter_button);
			this->Controls->Add(this->password_label);
			this->Controls->Add(this->lang_combobox);
			this->Controls->Add(this->lang_label);
			this->Controls->Add(this->login_label);
			this->Controls->Add(this->password_textbox);
			this->Controls->Add(this->title_label);
			this->Controls->Add(this->login_textbox);
			this->Name = L"Avtorizazia";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Avtorizazia";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void lang_combobox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		this->lang = lang_combobox->SelectedItem->ToString();
		change_language();
	}
	private: System::Void change_language()
	{
		if (lang == "Русский")
		{
			lang_label->Text = "Язык";
			login_label->Text = "Логин";
			password_label->Text = "Пароль";
			title_label->Text = "Войдите в систему";
			enter_button->Text = "Войти";
			this->Text = "Авторизация";

		}
		else if (lang == "Беларуская")
		{
			lang_label->Text = "Мова";
			login_label->Text = "Лагін";
			password_label->Text = "Пароль";
			title_label->Text = "Увайдзіце ў сістэму";
			enter_button->Text = "Увайсці";
			this->Text = "Аўтарызацыя";
		}
		else if (lang == "English")
		{
			lang_label->Text = "Language";
			login_label->Text = "Login";
			password_label->Text = "Password";
			title_label->Text = "Sign in";
			enter_button->Text = "Enter";
			this->Text = "Authorization";

		}
	}

	//функция для разделения строки на слова
	//взята со stack overflow
	std::vector<std::string> split(const std::string& text, char sep) {
		std::vector<std::string> tokens;
		std::size_t start = 0, end = 0;
		while ((end = text.find(sep, start)) != std::string::npos) {
			tokens.push_back(text.substr(start, end - start));
			start = end + 1;
		}
		tokens.push_back(text.substr(start));
		return tokens;
	}

private: System::Void enter_button_Click(System::Object^ sender, System::EventArgs^ e) {
	std::ifstream file;
	std::string path = "Accounts.txt";
	file.open(path);

	std::string s;//сюда помещается строка из файла
	std::string word;//сюда будет помещаться каждое слово из строки s
	
	bool authorized = false;
	bool admin = false;

	while (getline(file, s)) // пока не достигнут конец файла класть очередную строку в переменную (s)
	{
		std::vector<std::string> args = split(s, ' ');//разделяем строку s на слова с помощью функции split
		if (args.size() == 3)
		{
			if (
				args[0] == marshal_as<std::string>(login_textbox->Text)
				&& args[1] == marshal_as<std::string>(password_textbox->Text)
				)

			{
				authorized = true;
				if (args[2] == "admin")
					admin = true;
				break;
			}
		}
		
	}

	file.close();

	if (authorized)
	{
		MyForm^ form = gcnew MyForm(admin, lang);
		form->Show();
		this->Hide();
	}
	else
	{
		if (lang == "Русский")
		{
			MessageBox::Show(this, "Неверный логин либо пароль!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);

		}
		else if (lang == "English")
		{
			MessageBox::Show(this, "Invalid login or password!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);

		}
		else if (lang == "Беларуская")
		{
			MessageBox::Show(this, "Няправільны лагін альбо пароль!", "Памылка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}
private: System::Void title_label_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void password_textbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void login_label_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void lang_label_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void password_label_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void login_textbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
