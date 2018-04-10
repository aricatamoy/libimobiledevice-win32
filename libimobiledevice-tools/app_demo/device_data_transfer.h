#pragma once

#include <string>
using std::string;

class CDeviceDataTransfer
{
public:
	CDeviceDataTransfer();
	~CDeviceDataTransfer();

	void start_connect(std::string ip, unsigned int port);
};

