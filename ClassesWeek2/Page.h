#pragma once
#include <string>

class Page
{
public:
	void init(); // initialization function
	void clearPage(); // clearing method

	// getters
	std::string getPosts() const; // getters - const since they don't change any of the fields
	std::string getStatus() const;

	// setters
	void setStatus(std::string status); // setter for the status
	void addLineToPosts(std::string new_line); // adding a line to the posts

private:
	// fields
	std::string _status;
	std::string _posts;

};