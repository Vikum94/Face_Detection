#pragma once
#ifndef MOBILEDEVICE_H
#define MOBILEDEVICE_H

#include "stdio.h"
#include <string>

class MobileDevice{
public:
	void sendMyRequest(System::String^);
	static int num;

	MobileDevice();
};
#endif