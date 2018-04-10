#pragma once
#include <set>
#include <map>
#include <string>

class CDeviceInfo
{
public:
	CDeviceInfo();
	~CDeviceInfo();

	static std::set<std::string> get_device_uuid_list();
	static std::string get_device_name(std::string device_uuid);
	static std::map<std::string, std::string> get_device_info(std::string device_uuid);
};

