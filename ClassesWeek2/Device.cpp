#include "Device.h"
#include <iostream>

void Device::init(unsigned int id, DeviceType type, std::string os)
{
	_id = id;
	_type = type;
	_os = os;
	_activated = true;
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