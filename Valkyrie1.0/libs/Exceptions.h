#pragma once

#include <iostream>
#include <exception>


struct VersionException : public std::exception {
	const char* what() const throw () {
		return "OpenQASM version is invalid";
	}
};