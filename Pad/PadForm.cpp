/*
*Author: Sepehr Rafiei
* Date: Pi Day! 03/14/2021
* Description: Demonstrates how a stack calculates a mathematical expression
* Version: 1.0
*/

#include "PadForm.h" //include PadForm headerfile

using namespace std;
using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

//main
void main() {
	
	Application::SetCompatibleTextRenderingDefault(false); //set compatible text rendering to default false
	Application::EnableVisualStyles();//enable visual style
	Pad::PadForm frm;//initialize frm 
	Application::Run(% frm);//start application


}





