#pragma once

namespace Warship {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm1
	/// </summary>



	public ref class fGame : public System::Windows::Forms::Form
	{
	public:
		fGame(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		void write(String^ s) { this->console->Text += " " + s; }
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~fGame()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
		int height;
		int width;
		array<Button^, 2 >^ field;
		array<Button^, 2 >^ enemyField;
		TextBox^ console;
		Button^ start;
		Button^ rand;
		Button^ showField;


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
			this->height = 462;
			this->width = 884;
			this->field = gcnew array<Button^, 2>(10, 10);
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j<10; j++) {
					field[i, j] = gcnew Button();
					field[i, j]->Click += gcnew System::EventHandler(this, &fGame::field_Click);
					field[i, j]->BackColor = System::Drawing::Color::White;
					field[i, j]->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
					field[i, j]->ForeColor = System::Drawing::Color::White;
					field[i, j]->Size = Drawing::Size(25, 25);
					field[i, j]->Location = System::Drawing::Point(97 + 27 * i, 97 + 27 * j);
					Controls->Add(field[i, j]);
				}
			}
			this->enemyField = gcnew array<Button^, 2>(10, 10);
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j<10; j++) {
					enemyField[i, j] = gcnew Button();
					enemyField[i, j]->BackColor = System::Drawing::Color::White;
					enemyField[i, j]->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
					enemyField[i, j]->ForeColor = System::Drawing::Color::White;
					enemyField[i, j]->Size = Drawing::Size(25, 25);
					enemyField[i, j]->Location = System::Drawing::Point(519 + 27 * i, 97 + 27 * j);
					Controls->Add(enemyField[i, j]);
				}
			}
			this->console = (gcnew System::Windows::Forms::TextBox());
			this->console->Location = System::Drawing::Point(width - width + 10, height - 52);
			this->console->Multiline = true;
			this->console->Name = L"textBox1";
			this->console->Size = System::Drawing::Size(200, 50);
			this->console->Text = "";
			Controls->Add(console);


			this->showField = gcnew Button();
			this->showField->Click += gcnew System::EventHandler(this, &fGame::showField_Click);
			this->showField->BackColor = System::Drawing::Color::White;
			this->showField->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->showField->ForeColor = System::Drawing::Color::White;
			this->showField->Size = Drawing::Size(25, 50);
			this->showField->Font = (gcnew System::Drawing::Font(L"BankGothic Md BT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->showField->Location = System::Drawing::Point(width - 25, height - 50);
			Controls->Add(showField);


			this->SuspendLayout();
			// 
			// fGame
			// 
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(884, 462);
			this->BackColor = System::Drawing::Color::Black;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Location = System::Drawing::Point(10, 0);
			this->Name = L"fGame";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L" ";
			this->ResumeLayout(false);


			///////////////////





		}
#pragma endregion

	private:
		System::Void field_Click(System::Object^  sender, System::EventArgs^  e) {
			field[0, 0]->BackColor = System::Drawing::Color::SteelBlue;
		}
		System::Void showField_Click(System::Object^ sender, System::EventArgs^ e) {
			console->ResetText();


		}

	};
}
