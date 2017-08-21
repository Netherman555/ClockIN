#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "getTime.h"

int main()
{
	//Initializes writing and puts in opening message.
	getTime time;
	std::ofstream logger;
	logger.open("logger.txt", std::fstream::app);
	std::string LogStartMessage = "Program Started At: ";
	LogStartMessage.append(time.getCurrentTime());
	logger << LogStartMessage << std::endl;
	logger.close();

	//Variables
	std::string ID;
	std::string writeMessage;
	std::vector <std::string> loggedIn(0);

	std::string message; //Used for std::cin commands

	std::cout << "Loading ClockIN by Anubis Studios..." << std::endl;
	
	while (true)
	{
		std::cout << "Welcome! Please type in a command:\n" << std::endl;
		std::cout << " 1) Check In" << std::endl;
		std::cout << " 2) Check Out" << std::endl;
		std::cout << " 3) Help" << std::endl;
		std::cout << " 4) Exit" << std::endl;
		std::cout << " ";
		std::cin >> message;

		if (message == "1")
		{
			std::cout << "Please Insert Your ID:" << std::endl;
			std::cin >> message;

			logger.open("logger.txt", std::fstream::app);
			logger << message << " clocked in at: " <<  time.getCurrentTime() << std::endl;
			logger.close();

			loggedIn.push_back(message);

		}
		else if (message == "2")
		{
			std::cout << "Please enter your ID:" << std::endl;
			std::cin >> message;
			if (std::find(loggedIn.begin(), loggedIn.end(), message) != loggedIn.end())
			{
				logger.open("logger.txt", std::fstream::app);
				logger << message << " clocked out at: " << time.getCurrentTime() << std::endl;
				logger.close();

				loggedIn.erase(std::remove(loggedIn.begin(), loggedIn.end(), message), loggedIn.end());

				std::cout << "You have been clocked out and removed." << std::endl;
			}
			else
			{
				std::cout << "You are not clocked in." << std::endl;
			}
		}
		else if (message == "3")
		{
			std::cout << "This program clocks you in and out to calculate how much time" << std::endl;
			std::cout << "you have spent on the job." << std::endl;
			std::cout << "Unregistered Copyright Anubis Studios 2017." << std::endl;
		}
		else if (message == "4")
		{
			return 0;
		}
		else
		{
			std::cout << "Command not recognized.  Please try again." << std::endl;
		}
	}
}
