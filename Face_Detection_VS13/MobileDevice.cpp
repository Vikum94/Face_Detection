#include "MobileDevice.h"
#include <exception>
using namespace System;
using namespace System::IO;
using namespace System::Net;
using namespace System::Net::NetworkInformation;
using namespace System::Text;

//192.168.43.10:8080/blink?f=
//192.168.43.140

int MobileDevice::num = 0;

void MobileDevice::sendMyRequest(System::String^ identifier) {
	WebRequest^ Request;
	HttpWebResponse^ Response;
	HttpListenerResponse^ myRes;
	Stream^ Stream1;
	StreamReader^ SReader;
	String^ Responsestring;
	String^ PATH = "http://192.168.43.20:8080/Id=" + identifier; //PATH to File on server //
	bool connceted;

	Ping ^pingSender = gcnew Ping;
	PingReply ^ reply = pingSender->Send("192.168.43.20");

	if (reply->Status == IPStatus::Success)
	{
		connceted = false;//The user is online, set our connection variable (CONN) to 10;
		Console::WriteLine("Working.");
	}
	else
	{
		connceted = true;//The user is offline, set our connection variable to 400;
	}
	//END

	if (connceted)//is the user online
	{
		try
		{
			Request = WebRequest::CreateHttp(PATH);
			Request->Credentials = CredentialCache::DefaultCredentials;
			Response = static_cast<HttpWebResponse^>(Request->GetResponse());
			Stream1 = Response->GetResponseStream();
			SReader = gcnew StreamReader(Stream1);
			Responsestring = SReader->ReadToEnd();
			Console::WriteLine("Data from remote server:\n" + Responsestring + ".\n");
			SReader->Close();
			Stream1->Close();
			Response->Close();
		}
		catch (std::exception& e){
			Console::Write(e.what());
		}

	}
	else//User is not online//
	{
		Console::WriteLine("Sorry, cannot detect a internet connection.");
	}
	Console::ReadKey();

}
MobileDevice::MobileDevice(){
	MobileDevice::num += 1;
}