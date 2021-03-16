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
		// Unused OpCodes
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
			INC_NN(BC);
			break;
		case 0x04:
			INC_N(B); 
			break;
		case 0x05:
			DEC_N(B); 
			break;
		case 0x06:
			LD_NN_N(&B, opcode >> 8); 
			break;
		case 0x07:
			RLCA(); 
			break;
		case 0x08:

			break;
		case 0x09:
			ADD_HL_N(BC); 
			break;
		case 0x0A:

			break;
		case 0x0B:
			DEC_NN(BC); 
			break;
		case 0x0C:
			INC_N(C); 
			break;
		case 0x0D:
			DEC_N(C); 
			break;
		case 0x0E:
			LD_NN_N(&C, opcode >> 8); 
			break;
		case 0x0F:
			RRCA();
			break;
		#pragma endregion 
		#pragma region 0x10 - 0x1F
		case 0x10:
			STOP(); 
			break;
		case 0x11:

			break;
		case 0x12:

			break;
		case 0x13:
			INC_NN(DE); 
			break;
		case 0x14:
			INC_N(D); 
			break;
		case 0x15:
			DEC_N(D); 
			break;
		case 0x16:
			LD_NN_N(&D, opcode >> 8);
			break;
		case 0x17:
			RLA(); 
			break;
		case 0x18:

			break;
		case 0x19:

			break;
		case 0x1A:

			break;
		case 0x1B:
			DEC_NN(DE); 
			break;
		case 0x1C:
			INC_N(E); 
			break;
		case 0x1D:
			DEC_N(E); 
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
		#pragma region 0x60 - 0x6F
		case 0x60:
			LD_R1_R2(&H, B);
			break;
		case 0x61:
			LD_R1_R2(&H, C);
			break;
		case 0x62:
			LD_R1_R2(&H, D);
			break;
		case 0x63:
			LD_R1_R2(&H, E);
			break;
		case 0x64:
			LD_R1_R2(&H, F);
			break;
		case 0x65:
			LD_R1_R2(&H, H);
			break;
		case 0x66:
			LD_R1_R2(&H, HL);
			break;
		case 0x67:
			LD_R1_R2(&H, *A);
			break;
		case 0x68:
			LD_R1_R2(&H, B);
			break;
		case 0x69:
			LD_R1_R2(&L, C);
			break;
		case 0x6A:
			LD_R1_R2(&L, D);
			break;
		case 0x6B:
			LD_R1_R2(&L, E);
			break;
		case 0x6C:
			LD_R1_R2(&L, H);
			break;
		case 0x6D:
			LD_R1_R2(&L, L);
			break;
		case 0x6E:
			LD_R1_R2(&L, HL);
			break;
		case 0x6F:
			LD_R1_R2(&L, *A);
			break;
#pragma endregion 
		#pragma region 0x070 - 0x07F
		case 0x70:
			LD_R1_R2(&HL, B);
			break;
		case 0x71:
			LD_R1_R2(&HL, C);
			break;
		case 0x72:
			LD_R1_R2(&HL, D);
			break;
		case 0x73:
			LD_R1_R2(&HL, E);
			break;
		case 0x74:
			LD_R1_R2(&HL, H);
			break;
		case 0x75:
			LD_R1_R2(&HL, L);
			break;
		case 0x76:
			HALT(); 
			break;
		case 0x77:
			LD_R1_R2(&HL, *A);
			break;
		case 0x78:
			LD_R1_R2(A, B);
			break;
		case 0x79:
			LD_R1_R2(A, C);
			break;
		case 0x7A:
			LD_R1_R2(A, D);
			break;
		case 0x7B:
			LD_R1_R2(A, E);
			break;
		case 0x7C:
			LD_R1_R2(A, H);
			break;
		case 0x7D:
			LD_R1_R2(A, L);
			break;
		case 0x7E:
			LD_R1_R2(A, HL);
			break;
		case 0x7F:
			LD_R1_R2(A, *A);
			break;
#pragma endregion 
#pragma region 0x80 - 0x8f
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
			ADD_A_N(E);
			break;
		case 0x84:
			ADD_A_N(H);
			break;
		case 0x85:
			ADD_A_N(L);
			break;
		case 0x86:
			ADD_A_N(HL);
			break;
		case 0x87:
			ADD_A_N(*A);
			break;
		case 0x88:
			ADC_A_N(B);
			break;
		case 0x89:
			ADC_A_N(C);
			break;
		case 0x8A:
			ADC_A_N(D);
			break;
		case 0x8B:
			ADC_A_N(E);
			break;
		case 0x8C:
			ADC_A_N(H);
			break;
		case 0x8D:
			ADC_A_N(L);
			break;
		case 0x8E:
			ADC_A_N(HL);
			break;
		case 0x8F:
			ADC_A_N(*A);
			break;
#pragma endregion 
#pragma region 0x90 - 0x9F
		case 0x90:
			SUB_N(B);
			break;
		case 0x91:
			SUB_N(C);
			break;
		case 0x92:
			SUB_N(D);
			break;
		case 0x93:
			SUB_N(E);
			break;
		case 0x94:
			SUB_N(H);
			break;
		case 0x95:
			SUB_N(L);
			break;
		case 0x96:
			SUB_N(HL);
			break;
		case 0x97:
			SUB_N(*A);
			break;
		case 0x98:
			SBC_A_N(B);
			break;
		case 0x99:
			SBC_A_N(C);
			break;
		case 0x9A:
			SBC_A_N(D);
			break;
		case 0x9B:
			SBC_A_N(E);
			break;
		case 0x9C:
			SBC_A_N(H);
			break;
		case 0x9D:
			SBC_A_N(L);
			break;
		case 0x9E:
			SBC_A_N(HL);
			break;
		case 0x9F:
			SBC_A_N(*A);
			break;
#pragma endregion 
#pragma region 0xA0 - 0xAF
		case 0xA0:
			AND_N(B); 
			break;
		case 0xA1:
			AND_N(C);
			break;
		case 0xA2:
			AND_N(D);
			break;
		case 0xA3:
			AND_N(E);
			break;
		case 0xA4:
			AND_N(H);
			break;
		case 0xA5:
			AND_N(L);
			break;
		case 0xA6:
			AND_N(HL);
			break;
		case 0xA7:
			AND_N(*A);
			break;
		case 0xA8:
			XOR_N(B);
			break;
		case 0xA9:
			XOR_N(C);
			break;
		case 0xAA:
			XOR_N(D);
			break;
		case 0xAB:
			XOR_N(E);
			break;
		case 0xAC:
			XOR_N(H);
			break;
		case 0xAD:
			XOR_N(L);
			break;
		case 0xAE:
			XOR_N(HL);
			break;
		case 0xAF:
			XOR_N(*A);
			break;
#pragma endregion 
#pragma region 0xB0 - 0xBF
		case 0xB0:
			OR_N(B);
			break;
		case 0xB1:
			OR_N(C);
			break;
		case 0xB2:
			OR_N(D);
			break;
		case 0xB3:
			OR_N(E);
			break;
		case 0xB4:
			OR_N(H);
			break;
		case 0xB5:
			OR_N(L);
			break;
		case 0xB6:
			OR_N(HL);
			break;
		case 0xB7:
			OR_N(*A);
			break;
		case 0xB8:
			CP_N(B);
			break;
		case 0xB9:
			CP_N(C);
			break;
		case 0xBA:
			CP_N(D);
			break;
		case 0xBB:
			CP_N(E);
			break;
		case 0xBC:
			CP_N(H);
			break;
		case 0xBD:
			CP_N(L);
			break;
		case 0xBE:
			CP_N(HL);
			break;
		case 0xBF:
			CP_N(*A);
			break;
#pragma endregion 
		case 0xC0:
			RET(); 
			break;
		case 0xC1:
			POP_NN(BC); 
			break;
		case 0xC2:
			// TODO
			break;
		case 0xC3:
			JP_NN(opcode >> 8); 
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







