#include <stdio.h>
#include "MobileDevice.h"
#include "MyForm.h"
//#include "CustomerForm.h"

using namespace Face_Detection_VS13;


[STAThreadAttribute]
int main(){
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	
	//Application::Run(gcnew MyForm());
	MyForm^ form1 = gcnew MyForm();
	form1->ShowDialog();
	//MobileDevice mb = MobileDevice();
	//mb.sendMyRequest("com");
	
	return 0;
}
