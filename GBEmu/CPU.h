#pragma once
class CPU
{
public:
	CPU();
	~CPU();

	void decode();
	void execute();
	void loadGame();
	void init(); 

private:
	unsigned short stack[16];
	unsigned short flags[8]; 
	unsigned short A, B, C, D, E, F, H, L, SP, PC, BC, DE, HL;

	unsigned short opcode;

	int clock;

	// 8bit loads
	void LD_NN_N(short r, short n); 
	void LD_R1_R2(short r1, short r2, short opcode);
	void LD_A_N(short n, short opcode);
	void LD_N_A(short r, opcode);
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

};


