#include "pch.h"
#include "CPU.h"
#include <iostream>


MMU gb_mmu; 

CPU::CPU()
{
	init(); 
}


CPU::~CPU()
{

}

void CPU::init()
{

	A = 0;
	B = 0;
	C = 0;
	D = 0;
	F = 0;
	H = 0;
	L = 0;

	PC = 0x0100;
	SP = 0xFFFE;
	BC = 0;
	DE = 0;
	HL = 0;

	for (int i = 0; i < 8; i++)
		flags[i] = 0; 

	gb_mmu = MMU(); 
}

void CPU::decode()
{
	opcode = gb_mmu.readByte(PC);

	switch(opcode)
	{
		case 0xD3:
		case 0xDB:
		case 0xDD: 
		case 0xE3:
		case 0xE4:
		case 0xEB:
		case 0xEC:
		case 0xED:
		case 0xF4:
		case 0xFC:
		case 0xFD:
			std::cout << "Invalid opcode" << std::endl;
			exit(3);
			break; 

		#pragma region 0x00 - 0x0F
		case 0x00:
			// NOP
			NOP(); 
			PC++;
			// TODO: increase cycles
			break;
		case 0x01:
			
			
			break;
		case 0x02:

			break;
		case 0x03:

			break;
		case 0x04:

			break;
		case 0x05:

			break;
		case 0x06:
			LD_NN_N(&B, opcode >> 8); 
			break;
		case 0x07:

			break;
		case 0x08:

			break;
		case 0x09:

			break;
		case 0x0A:

			break;
		case 0x0B:

			break;
		case 0x0C:

			break;
		case 0x0D:

			break;
		case 0x0E:
			LD_NN_N(&C, opcode >> 8); 
			break;
		case 0x0F:

			break;
		#pragma endregion 
		#pragma region 0x10 - 0x1F
		case 0x10:

			break;
		case 0x11:

			break;
		case 0x12:

			break;
		case 0x13:

			break;
		case 0x14:

			break;
		case 0x15:

			break;
		case 0x16:
			LD_NN_N(&D, opcode >> 8);
			break;
		case 0x17:

			break;
		case 0x18:

			break;
		case 0x19:

			break;
		case 0x1A:

			break;
		case 0x1B:

			break;
		case 0x1C:

			break;
		case 0x1D:

			break;
		case 0x1E:
			LD_NN_N(&E, opcode >> 8);
			break;
		case 0x1F:

			break;
		#pragma endregion 
		#pragma region 0x20 - 0x2F
		case 0x20:

			break;
		case 0x21:

			break;
		case 0x22:

			break;
		case 0x23:

			break;
		case 0x24:

			break;
		case 0x25:

			break;
		case 0x26:
			LD_NN_N(&H, opcode >> 8);
			break;
		case 0x27:

			break;
		case 0x28:

			break;
		case 0x29:

			break;
		case 0x2A:

			break;
		case 0x2B:

			break;
		case 0x2C:

			break;
		case 0x2D:

			break;
		case 0x2E:
			LD_NN_N(&L, opcode >> 8);
			break;
		case 0x2F:

			break;
		#pragma endregion 
		#pragma region 0x30 - 0x3F
		case 0x30:

			break;
		case 0x31:

			break;
		case 0x32:

			break;
		case 0x33:

			break;
		case 0x34:

			break;
		case 0x35:

			break;
		case 0x36:
			LD_NN_N(&H, opcode >> 8);
			break;
		case 0x37:

			break;
		case 0x38:

			break;
		case 0x39:

			break;
		case 0x3A:

			break;
		case 0x3B:

			break;
		case 0x3C:

			break;
		case 0x3D:

			break;
		case 0x3E:
			LD_NN_N(&L, opcode >> 8);
			break;
		case 0x3F:

			break;
#pragma endregion 
		#pragma region 0x40 - 0x4F
		case 0x40:
			LD_R1_R2(&B, B);
			break;
		case 0x41:
			LD_R1_R2(&B, C);
			break;
		case 0x42:
			LD_R1_R2(&B, D);
			break;
		case 0x43:
			LD_R1_R2(&B, E);
			break;
		case 0x44:
			LD_R1_R2(&B, H);
			break;
		case 0x45:
			LD_R1_R2(&B, L);
			break;
		case 0x46:
			LD_R1_R2(&B, HL);
			break;
		case 0x47:
			LD_R1_R2(&B, *A);
			break;
		case 0x48:
			LD_R1_R2(&C, B);
			break;
		case 0x49:
			LD_R1_R2(&C, C);
			break;
		case 0x4A:
			LD_R1_R2(&C, D);
			break;
		case 0x4B:
			LD_R1_R2(&C, E);
			break;
		case 0x4C:
			LD_R1_R2(&C, H);
			break;
		case 0x4D:
			LD_R1_R2(&C, L);
			break;
		case 0x4E:
			LD_R1_R2(&C, HL);
			break;
		case 0x4F:
			LD_R1_R2(&C, *A);
			break;
#pragma endregion 
		#pragma region 0x50 - 0x5F
		case 0x50:
			LD_R1_R2(&D, B);
			break;
		case 0x51:
			LD_R1_R2(&D, C);
			break;
		case 0x52:
			LD_R1_R2(&D, D);
			break;
		case 0x53:
			LD_R1_R2(&D, E);
			break;
		case 0x54:
			LD_R1_R2(&D, H);
			break;
		case 0x55:
			LD_R1_R2(&D, L);
			break;
		case 0x56:
			LD_R1_R2(&D, HL);
			break;
		case 0x57:
			LD_R1_R2(&D, *A);
			break;
		case 0x58:
			LD_R1_R2(&E, B);
			break;
		case 0x59:
			LD_R1_R2(&E, C);
			break;
		case 0x5A:
			LD_R1_R2(&E, D);
			break;
		case 0x5B:
			LD_R1_R2(&E, E);
			break;
		case 0x5C:
			LD_R1_R2(&E, H);
			break;
		case 0x5D:
			LD_R1_R2(&E, L);
			break;
		case 0x5E:
			LD_R1_R2(&E, HL);
			break;
		case 0x5F:
			LD_R1_R2(&E, *A);
			break;
		#pragma endregion 
		case 0x60:

			break;
		case 0x61:

			break;
		case 0x62:

			break;
		case 0x63:

			break;
		case 0x64:

			break;
		case 0x65:

			break;
		case 0x66:
			LD_NN_N(&H, opcode >> 8);
			break;
		case 0x67:

			break;
		case 0x68:

			break;
		case 0x69:

			break;
		case 0x6A:

			break;
		case 0x6B:

			break;
		case 0x6C:

			break;
		case 0x6D:

			break;
		case 0x6E:
			LD_NN_N(&L, opcode >> 8);
			break;
		case 0x6F:

			break;
		case 0x70:

			break;
		case 0x71:

			break;
		case 0x72:

			break;
		case 0x73:

			break;
		case 0x74:

			break;
		case 0x75:

			break;
		case 0x76:
			LD_NN_N(&H, opcode >> 8);
			break;
		case 0x77:

			break;
		case 0x78:

			break;
		case 0x79:

			break;
		case 0x7A:

			break;
		case 0x7B:

			break;
		case 0x7C:

			break;
		case 0x7D:

			break;
		case 0x7E:
			LD_NN_N(&L, opcode >> 8);
			break;
		case 0x7F:

			break;
		case 0x80:
			ADD_A_N(B);
			break;
		case 0x81:
			ADD_A_N(C);
			break;
		case 0x82:
			ADD_A_N(D);
			break;
		case 0x83:
			ADD_A_N(*A);
			break;
		case 0x84:

			break;
		case 0x85:

			break;
		case 0x86:
			LD_NN_N(&H, opcode >> 8);
			break;
		case 0x87:
			ADD_A_N(*A);
			break;
		case 0x88:

			break;
		case 0x89:

			break;
		case 0x8A:

			break;
		case 0x8B:

			break;
		case 0x8C:

			break;
		case 0x8D:

			break;
		case 0x8E:
			LD_NN_N(&L, opcode >> 8);
			break;
		case 0x8F:

			break;
		case 0x90:

			break;
		case 0x91:

			break;
		case 0x92:

			break;
		case 0x93:

			break;
		case 0x94:

			break;
		case 0x95:

			break;
		case 0x96:
			LD_NN_N(&H, opcode >> 8);
			break;
		case 0x97:
			
			break;
		case 0x98:

			break;
		case 0x99:

			break;
		case 0x9A:

			break;
		case 0x9B:

			break;
		case 0x9C:

			break;
		case 0x9D:

			break;
		case 0x9E:
			LD_NN_N(&L, opcode >> 8);
			break;
		case 0x9F:

			break;
		case 0xA0:

			break;
		case 0xA1:

			break;
		case 0xA2:

			break;
		case 0xA3:

			break;
		case 0xA4:

			break;
		case 0xA5:

			break;
		case 0xA6:
			LD_NN_N(&H, opcode >> 8);
			break;
		case 0xA7:

			break;
		case 0xA8:

			break;
		case 0xA9:

			break;
		case 0xAA:

			break;
		case 0xAB:

			break;
		case 0xAC:

			break;
		case 0xAD:

			break;
		case 0xAE:
			LD_NN_N(&L, opcode >> 8);
			break;
		case 0xAF:

			break;
		case 0xB0:

			break;
		case 0xB1:

			break;
		case 0xB2:

			break;
		case 0xB3:

			break;
		case 0xB4:

			break;
		case 0xB5:

			break;
		case 0xB6:
			LD_NN_N(&H, opcode >> 8);
			break;
		case 0xB7:

			break;
		case 0xB8:

			break;
		case 0xB9:

			break;
		case 0xBA:

			break;
		case 0xBB:

			break;
		case 0xBC:

			break;
		case 0xBD:

			break;
		case 0xBE:
			LD_NN_N(&L, opcode >> 8);
			break;
		case 0xBF:

			break;
		case 0xC0:

			break;
		case 0xC1:

			break;
		case 0xC2:

			break;
		case 0xC3:

			break;
		case 0xC4:

			break;
		case 0xC5:

			break;
		case 0xC6:
			LD_NN_N(&H, opcode >> 8);
			break;
		case 0xC7:

			break;
		case 0xC8:

			break;
		case 0xC9:

			break;
		case 0xCA:

			break;
		case 0xCB:

			break;
		case 0xCC:

			break;
		case 0xCD:

			break;
		case 0xCE:
			LD_NN_N(&L, opcode >> 8);
			break;
		case 0xCF:

			break;
		case 0xD0:

			break;
		case 0xD1:

			break;
		case 0xD2:

			break;
		case 0xD4:

			break;
		case 0xD5:

			break;
		case 0xD6:
			LD_NN_N(&H, opcode >> 8);
			break;
		case 0xD7:

			break;
		case 0xD8:

			break;
		case 0xD9:

			break;
		case 0xDA:

			break;
		case 0xDC:

			break;
		case 0xDE:
			LD_NN_N(&L, opcode >> 8);
			break;
		case 0xDF:

			break;
		case 0xE0:

			break;
		case 0xE1:

			break;
		case 0xE2:

			break;
		case 0xE5:

			break;
		case 0xE6:
			LD_NN_N(&H, opcode >> 8);
			break;
		case 0xE7:

			break;
		case 0xE8:

			break;
		case 0xE9:

			break;
		case 0xEA:

			break;
		case 0xEE:
			LD_NN_N(&L, opcode >> 8);
			break;
		case 0xEF:

			break;
		case 0xF0:

			break;
		case 0xF1:

			break;
		case 0xF2:

			break;
		case 0xF3:

			break;
		case 0xF5:

			break;
		case 0xF6:
			LD_NN_N(&H, opcode >> 8);
			break;
		case 0xF7:

			break;
		case 0xF8:

			break;
		case 0xF9:

			break;
		case 0xFA:

			break;
		case 0xFB:

			break;
		case 0xFE:
			LD_NN_N(&L, opcode >> 8);
			break;
		case 0xFF:

			break;
	}
}

void CPU::setFlags(short Z, short N, short H, short C) {
	flags[7] = Z; 
	flags[6] = N; 
	flags[5] = H; 
	flags[4] = C; 
}

#pragma region 8 bit loads
void CPU::LD_NN_N(short *r, short n)
{
	*r = n; 
}

void CPU::LD_R1_R2(short *r1, short r2)
{
	*r1 = r2; 
}

void CPU::LD_A_N(short *n, short opcode)
{
	A = n; 
}

void CPU::LD_N_A(short *r)
{
	*r = *A; 
}

void CPU::LD_A_C()
{
	
}

void CPU::LD_C_A()
{
	
}

void CPU::LDD_A_HL()
{
	
}
#pragma  endregion 

#pragma region 8-bit ALU
void CPU::ADD_A_N(short n)
{
	A += n;

	if (A == 0)
		flags[7] = 1;

	flags[6] = 0; 

}

void CPU::ADC_A_N(short n)
{
	A += n;

	A += flags[4]; 
}

void CPU::SUB_N(short n)
{
	A -= n;

	if (A == 0)
		flags[7] = 1;

	flags[6] = 0; 
}

void CPU::SBC_A_N(short n)
{
	A -= n;

	A -= flags[4];
}

void CPU::AND_N(short n)
{
	*A &= n;

	if (A == 0)
		flags[7] = 1;
	flags[6] = 0;
	flags[5] = 1;
	flags[4] = 0;
}

void CPU::OR_N(short n)
{
	*A |= n;

	if (A == 0)
		flags[7] = 1;
	flags[6] = 0;
	flags[5] = 0;
	flags[4] = 0;
}

void CPU::XOR_N(short n)
{
	*A ^= n;

	if (A == 0)
		flags[7] = 1;
	flags[6] = 0;
	flags[5] = 0;
	flags[4] = 0;
}

void CPU::CP_N(short n)
{
	short result = *A - n;

	if (result == 0)
		flags[7] = 1;

	flags[6] = 1;

	// TODO
	flags[5] = 1;
	flags[4] = 1;
}

void CPU::INC_N(short n)
{
	n++;

	if (n == 0)
		flags[7] = 1;

	flags[6] = 0;

	//
	flags[5] = 1; 
}

void CPU::DEC_N(short n)
{
	n--;

	if (n == 0)
		flags[7] = 1;

	flags[6] = 0;

	//
	flags[5] = 1;
}





#pragma endregion 

#pragma region 16 bit arithmatic

void ADD_HL_N(short n) {
}

void CPU::ADD_SP_N(short n)
{
	SP += n; 
}

void CPU::INC_NN(short nn)
{
	nn++; 
}

void CPU::DEC_NN(short nn)
{
	nn--; 
}



#pragma endregion

#pragma region Misc

short CPU::SWAP_N(short n)
{
	return ((n & 0x0F) << 4 | (n & 0xF0) >> 4); 
}

#pragma endregion 


#pragma region Jumps
	
void CPU::JP_NN(short nn) {
	PC = nn; 

}

void CPU::JP_CC_NN(char* cc, short nn) {

	if (cc == "NZ") {
		if (flags[7] == 0)
			PC = nn; 
	}
	else if (cc == "Z") {
		if (flags[7] == 1)
			PC = nn; 
	}
	else if (cc == "NC") {
		if (flags[4] == 0)
			PC = nn; 
	}
	else {
		if (flags[4] == 1)
			PC = nn; 
	}
}

void CPU::JP_HL() {
	PC = HL; 
}

void CPU::JR_N(short n) {
	PC += n; 
}

void CPU::JR_CC_N(char* cc, short n) {
	if (cc == "NZ") {
		if (flags[7] == 0)
			PC += n;
	}
	else if (cc == "Z") {
		if (flags[7] == 1)
			PC += n;
	}
	else if (cc == "NC") {
		if (flags[4] == 0)
			PC += n;
	}
	else {
		if (flags[4] == 1)
			PC += n;
	}


}
	
#pragma endregion

#pragma region Returns

void CPU::RET() {

}
#pragma endregion







