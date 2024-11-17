#include "SocialNetwork.h"
#include <iostream>

void SocialNetwork::init(std::string networkName, int minAge)
{
	_networkName = networkName;
	_minAge = minAge;

	_profiles.init();
}

void SocialNetwork::clear()
{
	_networkName = "";
	_minAge = 0;

	_profiles.clear();
}

std::string SocialNetwork::getNetworkName() const
{
	return _networkName;
}

int SocialNetwork::getMinAge() const
{
	return _minAge;
}

bool SocialNetwork::addProfile(Profile profile_to_add)
{
	if (profile_to_add.getOwner().getAge() < _minAge)
	{
		return false;
	}

	_profiles.add(profile_to_add);

	return true;
}

std::string SocialNetwork::getWindowsDevices() const
{
	std::string windowsDevices = "";
	ProfileNode* currProfile = _profiles.get_first();
	DeviceNode* currDevice = NULL;

	while (currProfile != nullptr)
	{
		currDevice = currProfile->get_data().getOwner().getDevices().get_first();

		while (currDevice != nullptr)
		{
			if (currDevice->get_data().getOS().find("Windows") != std::string::npos)
			{
				windowsDevices += "[" + std::to_string(currDevice->get_data().getID()) + ", " + currDevice->get_data().getOS() + "], ";
			}
			currDevice = currDevice->get_next();
		}

		currProfile = currProfile->get_next();
	}

	if (windowsDevices.compare("")) // if the windowsDevices ISNT empty..
	{
		windowsDevices = windowsDevices.substr(0, windowsDevices.length() - 2); // delete the last two characters which are the last ', '. which we do not want.
	}

	return windowsDevices;
}