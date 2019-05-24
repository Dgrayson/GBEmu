#include "pch.h"
#include "MMU.h"
#include <cstdio>
#include <ostream>
#include <iostream>


MMU::MMU()
{
}


MMU::~MMU()
{
}


short MMU::readByte(short PC)
{
	return memory[PC]; 
}

void MMU::writeByte(short PC, short byte)
{
	memory[PC] = byte; 
}

void MMU::loadRom(char* fileName)
{
	FILE* rom;
	fopen_s(&rom, fileName, "rb");

	if (rom == nullptr)
		std::cout << "INvalid file" << std::endl;

	fseek(rom, 0, SEEK_END);

	long size = ftell(rom);

	rewind(rom);

	char* buffer = (char*)malloc(sizeof(char) * size);

	for(int i = 0; i < size; i++)
	{
		memory[i] = buffer[i]; 
	}
}


