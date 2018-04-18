#pragma once

#include <string>
using std::string;

class CDeviceDataTransfer
{
public:
	CDeviceDataTransfer();
	~CDeviceDataTransfer();

	static void start_connect(std::string device_uuid, unsigned int port);
};

