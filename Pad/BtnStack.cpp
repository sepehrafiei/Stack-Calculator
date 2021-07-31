/*
* Author:Sepehr Rafiei
*/
#include "BtnStack.h" //include BtnStack headerfile


//constructor with no parameter
BtnStack::BtnStack() {
	ptr = 0;//set ptr to 0
}

//constructor with Button^ type parameter
BtnStack::BtnStack(cli::array<Button^, 1>^ init) {
	ptr = 0;//set ptr to 0
	arr = init;//set arr equal to the array passed in the parameter

}

//push function, string parameter
void BtnStack::push(string element) {

	//check if ptr is not at the last spot
	if (ptr < 6) {
		arr[ptr]->Text = sTo(element);//set this spot(the text of the button) to the element
		ptr++;//increase ptr by 1
	}
}


//pop function, returns string
string BtnStack::pop() {
	//check if ptr is not at the first element
	if (ptr > 0) {
		ptr--;//decrease ptr by 1
	}
	string ret = sFrom(arr[ptr]->Text); //set ret equal to the text of the button at this spot
	arr[ptr]->Text = "";//set the text of the button at this pot equal to nothing/blank
	return ret;//return the value of ret which holds the poped element
}

//peek
string BtnStack::peek() {
	//check if the ptr is not pointing to the first element
	if (ptr > 0) {
		return sFrom(arr[ptr-1]->Text);//return the element one before the spot
	}
	else {
		return sFrom(arr[ptr]->Text);//return the element in this spot
	}
	
}


//this function sets arr equal to the array passed in the parameter
void BtnStack::setArr(cli::array<Button^, 1>^ init) {
	arr = init;
}

//this function coverts string to String^
String^ BtnStack::sTo(string a) {
	System::String^ b = msclr::interop::marshal_as<System::String^>(a);
	return b;
}

//this function coverts String^ to string
string BtnStack::sFrom(String^ a) {
	string b = msclr::interop::marshal_as<string>(a);
	return b;
}

