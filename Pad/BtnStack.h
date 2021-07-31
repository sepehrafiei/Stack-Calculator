/*
* Author: Sepehr Rafiei
* The BtnStack class is a stack made and designed for Windows Form Buttons
* Each array element is a button where you can push and pop numbers from
* This class is used for the graphic side of the stack
*/


//classes/things we need to use in the program
#pragma once
#include <string> //for std::string related things
#include <msclr\marshal_cppstd.h> //used to covert between string and String^
using namespace System::Windows::Forms; 
using namespace std;
using namespace System; 


//Btn Stack Class
ref class BtnStack {
	//public
public:
	int ptr; //pointer that points at a certain element of the array
	cli::array<Button^, 1>^ arr; //array of type Button^
	BtnStack(); //constructor
	BtnStack(cli::array<Button^, 1>^ init); //second constructor with parameter
	void setArr(cli::array<Button^, 1>^ init); //set array to the array from the argument
	void push(string element); //push function for string element
	string pop();//pop stack, return string
	string peek();//peek stack, return string
	String^ BtnStack::sTo(string a);//convert from string to String^
	string BtnStack::sFrom(String^ a);//convert from String^ to string

};

