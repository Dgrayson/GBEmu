#pragma once
class MMU
{
public:
	MMU();
	~MMU();

	short readByte(short PC);
	void writeByte(short PC, short byte);
	void loadRom(char* fileName); 

private: 
	unsigned char memory[65536];
};

