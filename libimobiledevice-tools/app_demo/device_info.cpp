#include "device_info.h"
#include <libimobiledevice/libimobiledevice.h>
#include <libimobiledevice/lockdown.h>

using namespace std;

CDeviceInfo::CDeviceInfo()
{
}


CDeviceInfo::~CDeviceInfo()
{
}

std::set<std::string> CDeviceInfo::get_device_uuid_list()
{
	set<string> device_list;

	do{
		char **dev_list = NULL;
		int count = 0;

		if (idevice_get_device_list(&dev_list, &count) < 0)
		{
			break;
		}

		for (int i = 0; i < count; i++) {
			device_list.insert(dev_list[i]);
		}

		idevice_device_list_free(dev_list);

	} while (false);

	return device_list;
}

std::string CDeviceInfo::get_device_name(std::string device_uuid)
{
	string device_name;
	idevice_t device = NULL;
	lockdownd_client_t client = NULL;
	char *devname = NULL;

	do{
		if (LOCKDOWN_E_SUCCESS != idevice_new(&device, device_uuid.c_str())) 
			break;

		if (LOCKDOWN_E_SUCCESS != lockdownd_client_new(device, &client, "idevice_id")) 
			break;

		if ((LOCKDOWN_E_SUCCESS != lockdownd_get_device_name(client, &devname))) 
			break;

		device_name = devname;
	} while (false);

	if (device)
		idevice_free(device);

	if (client)
		lockdownd_client_free(client);

	if (devname)
		free(devname);

	return device_name;
}

std::map<std::string, std::string> CDeviceInfo::get_device_info(std::string device_uuid)
{
	map<string, string> device_info;
	idevice_t device = NULL;
	lockdownd_client_t client = NULL;

	char *domain = NULL;
	char *key = NULL;
	plist_t node = NULL;
	plist_type node_type;

	do{
		if (LOCKDOWN_E_SUCCESS != idevice_new(&device, device_uuid.c_str()))
			break;

		if (LOCKDOWN_E_SUCCESS != lockdownd_client_new(device, &client, "ideviceinfo"))
			break;

		if (LOCKDOWN_E_SUCCESS != lockdownd_get_value(client, domain, key, &node))
			break;

		if (node) 
		{
			char * plist_xml = NULL;
			unsigned int plist_len = 0;
			plist_to_xml(node, &plist_xml, &plist_len);
			node_type = plist_get_node_type(node);
			if (node_type == PLIST_DICT)
			{


			}
		}
	} while (false);

	if (device)
		idevice_free(device);

	if (client)
		lockdownd_client_free(client);

	if (domain)
		free(domain);

	if (key)
		free(key);

	return device_info;
}
