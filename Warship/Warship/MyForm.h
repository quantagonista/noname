#pragma once
#include "fGame.h"

namespace Warship {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  bStart;

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
			this->bStart = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// bStart
			// 
			this->bStart->BackColor = System::Drawing::Color::Black;
			this->bStart->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->bStart->Font = (gcnew System::Drawing::Font(L"BankGothic Md BT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bStart->ForeColor = System::Drawing::Color::White;
			this->bStart->Location = System::Drawing::Point(335, 184);
			this->bStart->Name = L"bStart";
			this->bStart->Size = System::Drawing::Size(200, 50);
			this->bStart->TabIndex = 0;
			this->bStart->Text = L"START";
			this->bStart->UseVisualStyleBackColor = false;
			this->bStart->Click += gcnew System::EventHandler(this, &MyForm::bStart_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(884, 462);
			this->Controls->Add(this->bStart);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"WARSHIPS";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void bStart_Click(System::Object^  sender, System::EventArgs^  e) {

		fGame^ fgame = gcnew fGame();
		fgame->Show();
		this->Hide();

	}
	};
}
