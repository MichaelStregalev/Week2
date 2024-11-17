#pragma once
#include "ProfileList.h"

class SocialNetwork
{
public:
	void init(std::string networkName, int minAge);
	void clear();

	std::string getNetworkName() const;
	int getMinAge() const;
	std::string getWindowsDevices() const;

	bool addProfile(Profile profile_to_add);

private:
	// fields
	std::string _networkName;
	ProfileList _profiles;
	int _minAge;
};