#include "Device.h"
#include <iostream>

/*Initializing a new device*/
void Device::init(unsigned int id, DeviceType type, std::string os)
{
	// initializing all of the fields

	_id = id;
	_type = type;
	_os = os;
	_activated = true; // when initializing a new device - it is activated as default.
}

/*Getting the ID of the device*/
unsigned int Device::getID() const
{
	return _id;
}

/*Getting the type of the device*/
DeviceType Device::getType() const
{
	return _type;
}

/*Getting the OS of the device*/
std::string Device::getOS() const
{
	return _os;
}

/*Getting the activation status of the device.
true - activated
false - deactivated*/
bool Device::isActive() const
{
	return _activated;
}

/*Activating the device*/
void Device::activate()
{
	_activated = true;
}

/*Deactiviting the device*/
void Device::deactivate()
{
	_activated = false;
}