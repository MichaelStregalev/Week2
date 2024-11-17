#include "Device.h"
#include <iostream>

void Device::init(unsigned int id, DeviceType type, std::string os)
{
	// initializing all of the fields

	_id = id;
	_type = type;
	_os = os;
	_activated = true; // when initializing a new device - it is activated as default.
}

unsigned int Device::getID() const
{
	return _id;
}

DeviceType Device::getType() const
{
	return _type;
}

std::string Device::getOS() const
{
	return _os;
}

bool Device::isActive() const
{
	return _activated;
}

void Device::activate()
{
	_activated = true;
}

void Device::deactivate()
{
	_activated = false;
}