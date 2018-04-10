#include <set>
#include <string.h>
#include <iostream>
#include "device_info.h"

using namespace std;


int main(int argc, char **argv)
{
	set<string> device_list = CDeviceInfo::get_device_uuid_list();
	set<string>::const_iterator device_iter = device_list.begin();
	while (device_iter != device_list.end())
	{
		string device_name = CDeviceInfo::get_device_name(*device_iter);
		map<string, string> device_info = CDeviceInfo::get_device_info(*device_iter);
		cout << device_name << " uuid: " << *device_list.begin() << endl;
		++device_iter;
	}
	return 0;
}
