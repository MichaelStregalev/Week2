#pragma once
#include <string>

#include "DeviceList.h"

class User
{
public:
	void init(unsigned int id, std::string username, unsigned int age); // initialization function
	void clear(); // clear the object and free allocated memory

	unsigned int getID() const; // getters
	std::string getUserName() const;
	unsigned int getAge() const;
	DevicesList& getDevices(); // won't be const as were sending a refrence of the devices - which means, the devices list can be changed!

	// methods

	void addDevice(Device newDevice);
	bool checkIfDevicesAreOn() const; // const - as were not changing any fields

private:
	unsigned int _id;
	std::string _username;
	unsigned int _age;
	DevicesList _devices;
};