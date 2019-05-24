#pragma once

#include <bitset>
#include "MMU.h"

class CPU
{
public:
	CPU();
	~CPU();

	MMU mmu;
	short* A, B, C, D, E, F, H, L, SP, PC, BC, DE, HL;

	void decode();
	void execute();
	void loadGame();
	void init(); 

private:
	unsigned short stack[16];
	std::bitset<8> flags; 


	unsigned short opcode;

	void setFlags(short Z, short N, short H, short C); 

	// 8bit loads
	void LD_NN_N(short *r, short n); 
	void LD_R1_R2(short *r1, short r2, short opcode);
	void LD_A_N(short *n, short opcode);
	void LD_N_A(short *r);
	void LD_A_C();
	void LD_C_A();
	void LD_A_HLD();
	void LD_A_HL_MINUS();
	void LDD_A_HL();
	void LD_HLD_A();
	void LD_HL_MINUS_A();
	void LDD_HL_A();
	void LD_A_HLI();
	void LD_A_HL_PLUS();
	void LDI_A_HL();
	void LD_HLI_A();
	void LD_HL_PLUS_A();
	void LDI_HL_A();
	void LDH_N_A(short addr);
	void LDH_A_N(short addr);

	//16 bit loads
	void LD_N_NN(short r, short nn);
	void LD_SP_HL();
	void LD_HL_SP();
	void LDHL_SP_N(short n);
	void LD_NN_SP(short nn);
	void PUSH_NN(short r);
	void POP_NN(short r);

	//8-bit ALU
	void ADD_A_N(short n);
	void ADC_A_N(short n);
	void SUB_N(short n);
	void SBC_A_N(short n);
	void AND_N(short n);
	void OR_N(short n);
	void XOR_N(short n);
	void CP_N(short n);
	void INC_N(short n);
	void DEC_N(short n);

	//16-bit alu
	void ADD_HL_N(short n);
	void ADD_SP_N(short n);
	void INC_NN(short nn);
	void DEC_NN(short nn);

	//MISC
	short SWAP_N(short n);
	void DAA();
	void CPL();
	void CCF();
	void SCF();
	void NOP();
	void HALT();
	void STOP();
	void DI();
	void EL();

	//Rotates and shifts
	void RLCA();
	void RLA();
	void RRCA();
	void RRA();
	void RLC();
	void RL_N();
	void RRC_N();
	void RR_N();
	void SLA_N();
	void SRA_N();
	void SRL_N();

	//Bit Opcodes
	void BIT_B_R(short b, short r);
	void SET_B_R(short b, short r);
	void RES_B_R(short b, short r);

	//Jumps
	void JP_NN(short nn);
	void JP_CC_NN(char* cc, short nn);
	void JP_HL();
	void JR_N(short n);
	void JR_CC_N(char* cc, short n);

	// Calls
	void CALL_NN();
	void CALL_CC_NN();

	// Restarts
	void RST_N(short N);

	// REturns
	void RET();
	void RET_CC();
	void RETI();


};


