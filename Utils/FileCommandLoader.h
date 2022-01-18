/*
 * FileCommandLoader.h
 *
 *  Created on: Nov 26, 2021
 *      Author: Patrick Murphy
 */

#ifndef UTILS_FILECOMMANDLOADER_H_
#define UTILS_FILECOMMANDLOADER_H_

#include <functional>
#include <vector>
#include <string>
#include <stdint.h>

class Color;
class Vec2D;

/**
 * Enum to distinguish command types. Either ONE_LINE, or MULTI_LINE commands.
 */
enum CommandType
{
	COMMAND_ONE_LINE = 0,
	COMMAND_MULTI_LINE
};

/**
 * struct used to help organize parsed function parameters.
 */
struct ParseFuncParams
{
	std::string line;
	size_t dilimitPos;
	uint32_t lineNum;
};

/**
 * Lambda type declaration for dealing with ParseFuncParams.
 */
using ParseFunc = std::function<void(const ParseFuncParams & params)>;

/**
 * struct that defines a command.
 */
struct Command
{
	CommandType commandType = COMMAND_ONE_LINE;
	std::string command = "";
	ParseFunc parseFunc = nullptr;
};

class FileCommandLoader
{
public:

	/**
	 * Adds a command to the mCommands vector.
	 */
	void AddCommand(const Command& command);

	/**
	 * Tries to load command file. Returns false if it failed.
	 *
	 */
	bool LoadFile(const std::string& filePath);

	static Color ReadColor(const ParseFuncParams & params);
	static Vec2D ReadSize(const ParseFuncParams & params);
	static int ReadInt(const ParseFuncParams & params);
	static std::string ReadString(const ParseFuncParams & params);
	static char ReadChar(const ParseFuncParams & params);

private:
	std::vector<Command> mCommands;
};



#endif /* UTILS_FILECOMMANDLOADER_H_ */
