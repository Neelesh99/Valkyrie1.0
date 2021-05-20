#pragma once

#include <iostream>
#include <exception>

/*
	Exceptions.h
	Description: Defines custom exceptions.

*/

// VersionExcpetion is thrown if the OpenQASM version isn't 2.0.
struct VersionException : public std::exception {
	const char* what() const throw () {
		return "OpenQASM version is invalid";
	}
};