/*
*Author: Sepehr Rafiei
* Date: Pi Day! 03/14/2021
* Description: Demonstrates how a stack calculates a mathematical expression
* Version: 1.0
*/

#pragma once
#include <string> //for std::string related things
#include <msclr\marshal_cppstd.h> //to convert between string and String^
#include <fstream> //file stream to read file
#include"BtnStack.h" //include BtnStack headerfile(and cpp file)
#include<map> //to map the mathematical operations to integers(used for priority)
#include<windows.h> //mostly used for sleep

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace std;



namespace Pad {




		string line; //string line stores the line read from file


	public ref class PadForm : public System::Windows::Forms::Form
	{
		cli::array<Button^, 1>^ numArray;//array of Button^ for number
		cli::array<Button^, 1>^ opArray;//array of Button^ for operations
		BtnStack g1; //initialize BtnStack class and make an instance called g1(for numbers)
		BtnStack g2;//initialize BtnStack class and make an instance called g2(for operations)
		

	//public
	public:
		PadForm(void)
		{
			//call this function to initialize the components within the Form(buttons, textboxes, etc)
			InitializeComponent();
			
			ifstream file;//initialize and make an instance of ifstream,
			file.open("C://temp//input.txt");//open input.txt located at C:/temp/
			//if file is not open
			if (!file.is_open()) {
				inputbox->Text = "Could Not Open File";//set the text of inputbox to this message
			}
			//else
			else {
				getline(file, line);//read line
				inputbox->Text = stringTo(line);//set the text of inputbox to the read line
				setupbtn();//set up buttons
				g1.setArr(numArray);//call the setArr function within this class to set arr to this array
				g2.setArr(opArray);//call the setArr function within this class to set arr to this array
			}
		}

		//calculate function to calculate a 2 number mathematical expression
		//Takes in 3 string parameters, first number, the operation, the second number
		string calculate(string n1, string op, string n2) {
			p1->Text = stringTo(n1);//set the text of p1 to the first number
			p2->Text = stringTo(op);//set the text of p2 to the operation
			p3->Text = stringTo(n2);//set the text of p3 to the second number
			this->Refresh();//refresh the Form to see changes
			Sleep(1000);//sleep for a sec
			double num1 = stod(n1);//convert the first number to double
			double num2 = stod(n2);//convert the second number to double
			string answer = "";//initialize answer and set it to blank
			double d;//initialize a double variable called d
			//use switch statements to check what the operation is 
			switch (op[0]) {
			//if the operation is plus
			case '+':
				d = (num1 + num2);//set d to the sum of the two numbers
				break;//break
			//if the operation is minus
			case '-':
				d = (num1 - num2);//subtract the two numbers and set d to the result
				break;//break
			//if the operation is multiplication
			case '*':
				d = (num1 * num2);//multiply the two numbers and set d to the result
				break;//break
			//if the operation is division
			case '/':
				d = (num1 / num2);//divide the two numbers and set d to the result

				break;//break
			}
			//this long equation rounds the value in d to two decimal points and stores it in answer
			answer = to_string(d).substr(0, to_string(d + .005).find('.') + 2) + to_string(stoi(to_string(to_string(d + .005)[to_string(d + .005).find('.') + 2] - 48)));
			p1->Text = "";//set p1 text to blank
			p2->Text = "";//set p2 text to blank
			p3->Text = "";//set p3 text to blank
			p4->Text = stringTo(answer);//set p4 text to the answer
			this->Refresh();//refresh form to see changes
			Sleep(1000);//wait for one second
			p4->Text = "";//set the text of p4 to blank
			this->Refresh();//refresh the form to see changes
			return answer;//return the answer
		}


		//This function makes two arrays of buttons, one for numbers and one for operations
		void setupbtn() {
			//Create two type Button^ arrays of size 6
			numArray = gcnew cli::array<Button^, 1>(6);
			opArray = gcnew cli::array<Button^, 1>(6);
			//set the buttons for numbers
			numArray[0] = b00;
			numArray[1] = b01;
			numArray[2] = b02;
			numArray[3] = b03;
			numArray[4] = b04;
			numArray[5] = b05;
			//set buttons for operations
			opArray[0] = b10;
			opArray[1] = b11;
			opArray[2] = b12;
			opArray[3] = b13;
			opArray[4] = b14;
			opArray[5] = b15;
		}

		//this function converts string to String^
		String^ stringTo(string a) {
			System::String ^ b = msclr::interop::marshal_as<System::String^>(a);
			return b;
		}
		//this function coverts String^ to string
		string stringFrom(String^ a) {
			string b = msclr::interop::marshal_as<string>(a);
			return b;
		}

	//protected
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PadForm()
		{
			if (components)
			{
				delete components;//delete components
			}
		}

	/*
	* GUI component initialization(Buttons, textboxs, etc)
	*/
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	public: System::Windows::Forms::TextBox^ inputbox;
	private: System::Windows::Forms::TextBox^ ansBox;
	private: System::Windows::Forms::Button^ calcBtn;
	private: System::Windows::Forms::Button^ b00;
	private: System::Windows::Forms::Button^ b01;
	private: System::Windows::Forms::Button^ b02;
	private: System::Windows::Forms::Button^ b03;
	private: System::Windows::Forms::Button^ b04;
	private: System::Windows::Forms::Button^ b05;
	private: System::Windows::Forms::Button^ b10;
	private: System::Windows::Forms::Button^ b11;
	private: System::Windows::Forms::Button^ b12;
	private: System::Windows::Forms::Button^ b13;
	private: System::Windows::Forms::Button^ b14;
	private: System::Windows::Forms::Button^ b15;
	private: System::Windows::Forms::Button^ p4;
	private: System::Windows::Forms::Button^ p1;
	private: System::Windows::Forms::Button^ p3;
	private: System::Windows::Forms::Button^ p2;

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

		/// Initialize components
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->inputbox = (gcnew System::Windows::Forms::TextBox());
			this->ansBox = (gcnew System::Windows::Forms::TextBox());
			this->calcBtn = (gcnew System::Windows::Forms::Button());
			this->b00 = (gcnew System::Windows::Forms::Button());
			this->b01 = (gcnew System::Windows::Forms::Button());
			this->b02 = (gcnew System::Windows::Forms::Button());
			this->b03 = (gcnew System::Windows::Forms::Button());
			this->b04 = (gcnew System::Windows::Forms::Button());
			this->b05 = (gcnew System::Windows::Forms::Button());
			this->b10 = (gcnew System::Windows::Forms::Button());
			this->b11 = (gcnew System::Windows::Forms::Button());
			this->b12 = (gcnew System::Windows::Forms::Button());
			this->b13 = (gcnew System::Windows::Forms::Button());
			this->b14 = (gcnew System::Windows::Forms::Button());
			this->b15 = (gcnew System::Windows::Forms::Button());
			this->p4 = (gcnew System::Windows::Forms::Button());
			this->p1 = (gcnew System::Windows::Forms::Button());
			this->p3 = (gcnew System::Windows::Forms::Button());
			this->p2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(40, 40);
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(968, 60);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// inputbox
			// 
			this->inputbox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.1F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->inputbox->Location = System::Drawing::Point(0, 0);
			this->inputbox->Multiline = true;
			this->inputbox->Name = L"inputbox";
			this->inputbox->Size = System::Drawing::Size(443, 97);
			this->inputbox->TabIndex = 1;
			this->inputbox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->inputbox->TextChanged += gcnew System::EventHandler(this, &PadForm::inputbox_TextChanged);
			// 
			// ansBox
			// 
			this->ansBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.1F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ansBox->Location = System::Drawing::Point(440, 0);
			this->ansBox->Multiline = true;
			this->ansBox->Name = L"ansBox";
			this->ansBox->ReadOnly = true;
			this->ansBox->Size = System::Drawing::Size(282, 97);
			this->ansBox->TabIndex = 2;
			this->ansBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// calcBtn
			// 
			this->calcBtn->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->calcBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.1F));
			this->calcBtn->Location = System::Drawing::Point(725, 0);
			this->calcBtn->Margin = System::Windows::Forms::Padding(0);
			this->calcBtn->Name = L"calcBtn";
			this->calcBtn->Size = System::Drawing::Size(243, 97);
			this->calcBtn->TabIndex = 3;
			this->calcBtn->Text = L"Calculate";
			this->calcBtn->UseVisualStyleBackColor = true;
			this->calcBtn->Click += gcnew System::EventHandler(this, &PadForm::button1_Click);
			// 
			// b00
			// 
			this->b00->Location = System::Drawing::Point(19, 738);
			this->b00->Margin = System::Windows::Forms::Padding(0);
			this->b00->Name = L"b00";
			this->b00->Size = System::Drawing::Size(200, 100);
			this->b00->TabIndex = 4;
			this->b00->UseVisualStyleBackColor = true;
			// 
			// b01
			// 
			this->b01->Location = System::Drawing::Point(19, 633);
			this->b01->Margin = System::Windows::Forms::Padding(0);
			this->b01->Name = L"b01";
			this->b01->Size = System::Drawing::Size(200, 100);
			this->b01->TabIndex = 4;
			this->b01->UseVisualStyleBackColor = true;
			// 
			// b02
			// 
			this->b02->Location = System::Drawing::Point(19, 528);
			this->b02->Margin = System::Windows::Forms::Padding(0);
			this->b02->Name = L"b02";
			this->b02->Size = System::Drawing::Size(200, 100);
			this->b02->TabIndex = 4;
			this->b02->UseVisualStyleBackColor = true;
			// 
			// b03
			// 
			this->b03->Location = System::Drawing::Point(19, 423);
			this->b03->Margin = System::Windows::Forms::Padding(0);
			this->b03->Name = L"b03";
			this->b03->Size = System::Drawing::Size(200, 100);
			this->b03->TabIndex = 4;
			this->b03->UseVisualStyleBackColor = true;
			// 
			// b04
			// 
			this->b04->Location = System::Drawing::Point(19, 318);
			this->b04->Margin = System::Windows::Forms::Padding(0);
			this->b04->Name = L"b04";
			this->b04->Size = System::Drawing::Size(200, 100);
			this->b04->TabIndex = 4;
			this->b04->UseVisualStyleBackColor = true;
			// 
			// b05
			// 
			this->b05->Location = System::Drawing::Point(19, 213);
			this->b05->Margin = System::Windows::Forms::Padding(0);
			this->b05->Name = L"b05";
			this->b05->Size = System::Drawing::Size(200, 100);
			this->b05->TabIndex = 4;
			this->b05->UseVisualStyleBackColor = true;
			// 
			// b10
			// 
			this->b10->Location = System::Drawing::Point(242, 738);
			this->b10->Margin = System::Windows::Forms::Padding(0);
			this->b10->Name = L"b10";
			this->b10->Size = System::Drawing::Size(200, 100);
			this->b10->TabIndex = 4;
			this->b10->UseVisualStyleBackColor = true;
			// 
			// b11
			// 
			this->b11->Location = System::Drawing::Point(242, 633);
			this->b11->Margin = System::Windows::Forms::Padding(0);
			this->b11->Name = L"b11";
			this->b11->Size = System::Drawing::Size(200, 100);
			this->b11->TabIndex = 4;
			this->b11->UseVisualStyleBackColor = true;
			// 
			// b12
			// 
			this->b12->Location = System::Drawing::Point(242, 528);
			this->b12->Margin = System::Windows::Forms::Padding(0);
			this->b12->Name = L"b12";
			this->b12->Size = System::Drawing::Size(200, 100);
			this->b12->TabIndex = 4;
			this->b12->UseVisualStyleBackColor = true;
			// 
			// b13
			// 
			this->b13->Location = System::Drawing::Point(242, 423);
			this->b13->Margin = System::Windows::Forms::Padding(0);
			this->b13->Name = L"b13";
			this->b13->Size = System::Drawing::Size(200, 100);
			this->b13->TabIndex = 4;
			this->b13->UseVisualStyleBackColor = true;
			// 
			// b14
			// 
			this->b14->Location = System::Drawing::Point(242, 318);
			this->b14->Margin = System::Windows::Forms::Padding(0);
			this->b14->Name = L"b14";
			this->b14->Size = System::Drawing::Size(200, 100);
			this->b14->TabIndex = 4;
			this->b14->UseVisualStyleBackColor = true;
			// 
			// b15
			// 
			this->b15->Location = System::Drawing::Point(242, 213);
			this->b15->Margin = System::Windows::Forms::Padding(0);
			this->b15->Name = L"b15";
			this->b15->Size = System::Drawing::Size(200, 100);
			this->b15->TabIndex = 4;
			this->b15->UseVisualStyleBackColor = true;
			// 
			// p4
			// 
			this->p4->Location = System::Drawing::Point(652, 528);
			this->p4->Margin = System::Windows::Forms::Padding(0);
			this->p4->Name = L"p4";
			this->p4->Size = System::Drawing::Size(100, 100);
			this->p4->TabIndex = 4;
			this->p4->UseVisualStyleBackColor = true;
			// 
			// p1
			// 
			this->p1->Location = System::Drawing::Point(547, 423);
			this->p1->Margin = System::Windows::Forms::Padding(0);
			this->p1->Name = L"p1";
			this->p1->Size = System::Drawing::Size(100, 100);
			this->p1->TabIndex = 4;
			this->p1->UseVisualStyleBackColor = true;
			// 
			// p3
			// 
			this->p3->Location = System::Drawing::Point(757, 423);
			this->p3->Margin = System::Windows::Forms::Padding(0);
			this->p3->Name = L"p3";
			this->p3->Size = System::Drawing::Size(100, 100);
			this->p3->TabIndex = 4;
			this->p3->UseVisualStyleBackColor = true;
			// 
			// p2
			// 
			this->p2->Location = System::Drawing::Point(652, 423);
			this->p2->Margin = System::Windows::Forms::Padding(0);
			this->p2->Name = L"p2";
			this->p2->Size = System::Drawing::Size(100, 100);
			this->p2->TabIndex = 4;
			this->p2->UseVisualStyleBackColor = true;
			// 
			// PadForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(968, 1039);
			this->Controls->Add(this->p3);
			this->Controls->Add(this->p2);
			this->Controls->Add(this->p1);
			this->Controls->Add(this->p4);
			this->Controls->Add(this->b15);
			this->Controls->Add(this->b05);
			this->Controls->Add(this->b14);
			this->Controls->Add(this->b04);
			this->Controls->Add(this->b13);
			this->Controls->Add(this->b03);
			this->Controls->Add(this->b12);
			this->Controls->Add(this->b02);
			this->Controls->Add(this->b11);
			this->Controls->Add(this->b01);
			this->Controls->Add(this->b10);
			this->Controls->Add(this->b00);
			this->Controls->Add(this->calcBtn);
			this->Controls->Add(this->ansBox);
			this->Controls->Add(this->inputbox);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"PadForm";
			this->Text = L"PadForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion




//if the calculate button is clicked, do this
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	//try and catch to catch errors
	try {
		bool p = 0;//set p to 0, this checks every '(' has a ')'
		//Make a map of the operations to decide the priority
		map<string, int> Map;
		Map["-"] = 1;//lowest priority
		Map["+"] = 1;
		Map["*"] = 2;
		Map["/"] = 2;
		Map["("] = 3;
		Map[")"] = 4;//highest priority

		//for every letter in the line read
		for (size_t i = 0; i < line.length(); i++) {
			//make a string of the character and put it in string letter
			string letter(1, line[i]);

			//if this letter is a digit do the following
			if (isdigit(letter[0])) {

				//while the next letter in the line is a digit to the following
				//used for numbers that are more than 1 digit, ex 145
				while(isdigit(line[i+1])) {
					letter += line[i+1];//set letter equal to letter plus the next letter
					i++;//increase i to go to the next letter
				}

				g1.push(letter);//push letter to stack
				this->Refresh();//refresh form to see changes
				Sleep(1000);//sleep for a second
			}
			//else not a digit
			else {
				//check if the operation is not defined
				if (Map[letter] == 0) {
					inputbox->Text = "Bad Input";//set inputbox's text to display the message
					goto getout;//jump to getout label at the bottom
				}

				//check if the operation is '('
				if (Map[letter] == 3) {
					p = 1;//set p equal to 1. This is used for error purposes to make sure
						  //parenthesis are closed
				}

				//check if operation is ')'
				if (Map[letter] == 4) {
					//if p equals 0 do the following
					if (p == 0) {
						inputbox->Text = "Bad Input";//set inputbox text to the following message
						goto getout;//jump to getout label at the bottom
					}

					p = 0;//set p equal to 0 to let the program know the paraethesis is closed

					//while the previous element is not '('
					while (g2.peek() != "(") {
						g1.push(calculate(g1.pop(), g2.pop(), g1.pop()));//pop the last two numbers and computer 
																		 //the operation. Push the result to number stack.
					}
					g2.pop();//pop operation stack
					this->Refresh();//refresh form to see changes
					Sleep(1000);//sleep for a second

				}
				//else operation is not ')'
				else {
					//while previous operation in the stack has a higher or equal priority than the current operation
					//and the previous operation is not '('
					while ((Map[g2.peek()] >= Map[letter]) && (Map[g2.peek()] != 3)) {
						g1.push(calculate(g1.pop(), g2.pop(), g1.pop()));//pop the last two numbers and computer 
																		 //the operation. Push the result to number stack.
					}
					g2.push(letter);//push operation to operation stack
					this->Refresh();//refresh form to see changes
					Sleep(1000);//sleep for a second
				}

			}


		}

		//if p equals 1 then the parenthesis hasn't closed therefore the input is incorrect
		if (p == 1) {
			inputbox->Text = "Bad Input";//set inputbox text to the message
			goto getout;//jump to getout label at the bottom
		}

		//while the previous operation is not blank
		while (g2.peek() != "") {
			g1.push(calculate(g1.pop(), g2.pop(), g1.pop()));//pop the last two numbers and computer 
															 //the operation. Push the result to number stack.
			this->Refresh();//refresh page to see changes
			Sleep(1000);//sleep for a second
		}

		ansBox->Text = stringTo(g1.pop());//pop the final answer and put it in the answer box
		goto end;//jump to end label

	}
	//catch any exceptions
	catch (...) {
		inputbox->Text = "bad Input";//set inputbox text to the message
		goto getout;//jump to getout label 
	}

	//getout label
	getout:;
	ansBox->Text = ""; //set answerbox to blank
	//end label
	end:;
	//pop everything in the stack
	for (int i = 0; i < 6; i++) {
		g1.pop();
		g2.pop();
	}
	//set all the buttons on the right to blank
	p1->Text = "";
	p2->Text = "";
	p3->Text = "";
	p4->Text = "";
}


//if input box text changes set line equal to the new input
private: System::Void inputbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	line = stringFrom(inputbox->Text);//get text from inputbox and set line equal to it

}	
};

}

