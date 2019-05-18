#pragma once
class MMU
{
public:
	MMU();
	~MMU();

	short readByte();
	void writeByte();

private: 
	unsigned char memory[65536];
};

