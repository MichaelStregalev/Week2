#include "User.h"
#include <iostream>

/*Initializing a user object*/
void User::init(unsigned int id, std::string username, unsigned int age)
{
	_id = id;
	_username = username;
	_age = age;

	_devices.init(); 
}

/*Clearing all the information in the user object and freeing all allocated memory*/
void User::clear()
{
	_id = 0; // reset all fields
	_username = "";
	_age = 0;

	_devices.clear(); // clear all devices and free allocated memory
}

/*Getting the user's ID*/
unsigned int User::getID() const
{
	return _id;
}

/*Getting the user's username*/
std::string User::getUserName() const
{
	return _username;
}

/*Getting the user's age*/
unsigned int User::getAge() const
{
	return _age;
}

/*Getting a refrence to the user's devices list*/
const DevicesList& User::getDevices() const
{
	return _devices;
}

/*Adding a device to the user's devices list*/
void User::addDevice(Device newDevice)
{
	_devices.add(newDevice); // calling the function in DevicesList class, will take care of any situation
	// including - if the list is empty, it will initialize it.
}

/*Checking if ALL devices on the user's devices list are ACTIVATED*/
bool User::checkIfDevicesAreOn() const
{
	DeviceNode* curr = _devices.get_first(); // getting the current device in the list

	if (curr != nullptr) // if the list ISN'T EMPTY
	{
		while (curr != nullptr) // while the current device isn't null - while we are still in the list..
		{
			if (curr->get_data().isActive() == false) // if the current device is deactivated..
			{
				return false; // return false!
			}

			curr = curr->get_next(); // go to the next device in the list
		}
	}

	return true; // if we got to here - all devices are activated
}