#include "device_data_transfer.h"
#include "sock_stuff.h"
#include <string>
#include "usbmuxd.h"
#include <Windows.h>

using std::string;


CDeviceDataTransfer::CDeviceDataTransfer()
{
}


CDeviceDataTransfer::~CDeviceDataTransfer()
{
}

void CDeviceDataTransfer::start_connect(std::string device_uuid, unsigned int port)
{
	usbmuxd_device_info_t *dev_list = NULL;
	usbmuxd_device_info_t *specified_device = NULL;

	do
	{
		int count = usbmuxd_get_device_list(&dev_list);
		int specified_index = -1;

		for (int i = 0; i < count; ++i)
		{
			string uuid = dev_list[i].udid;
			if (uuid == device_uuid)
			{
				specified_index = i;
				break;
			}
		}

		if (specified_index == -1)
			break;

		specified_device = &dev_list[specified_index];

		int socket_for_device = usbmuxd_connect(specified_device->handle, port);

		while (true)
		{
			Sleep(10);
			int buffer_len = 4096;
			char* recieve_data = new char[buffer_len];
			memset(recieve_data, 0, buffer_len);
			uint32_t recieve_bytes = 0;
			usbmuxd_recv(socket_for_device, recieve_data, buffer_len, &recieve_bytes);

			int i = 0;
			++i;
		}



	} while (false);
	
}
