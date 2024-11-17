#pragma once
#include <string>

class Page
{
public:
	void init(); // initialization function

	std::string getPosts() const; // getters - const since they don't change any of the fields
	std::string getStatus() const;

	void setStatus(std::string status); // setter for the status
	void addLineToPosts(std::string new_line); // adding a line to the posts

	void clearPage(); // clearing method

private:
	// fields
	std::string _status;
	std::string _posts;

};