#include "gmock/gmock.h"
#include "alu.cpp";
#include "result.cpp";

TEST(ALU, ADDTest) {
	ALU alu;
	alu.setOperand1(130);
	alu.setOperand2(20);
	alu.setOPCODE("ADD");

	Result ret;
	alu.enableSignal(&ret);

	EXPECT_EQ(30, ret.getResult());
	EXPECT_EQ(0, ret.getStatus());
}

TEST(ALU, ADDTest_op1_negative) {
	ALU alu;
	alu.setOperand1(-1);
	alu.setOperand2(20);
	alu.setOPCODE("ADD");

	Result ret;
	alu.enableSignal(&ret);

	EXPECT_EQ(65535, ret.getResult());
	EXPECT_EQ(1, ret.getStatus());
}

TEST(ALU, ADDTest_op2_negative) {
	ALU alu;
	alu.setOperand1(20);
	alu.setOperand2(-1);
	alu.setOPCODE("ADD");

	Result ret;
	alu.enableSignal(&ret);

	EXPECT_EQ(65535, ret.getResult());
	EXPECT_EQ(2, ret.getStatus());
}

TEST(ALU, MULTest) {
	ALU alu;
	alu.setOperand1(10);
	alu.setOperand2(20);
	alu.setOPCODE("MUL");

	Result ret;
	alu.enableSignal(&ret);

	EXPECT_EQ(200, ret.getResult());
	EXPECT_EQ(0, ret.getStatus());
}

TEST(ALU, MULTest_op1_negative) {
	ALU alu;
	alu.setOperand1(-1);
	alu.setOperand2(20);
	alu.setOPCODE("MUL");

	Result ret;
	alu.enableSignal(&ret);

	EXPECT_EQ(65535, ret.getResult());
	EXPECT_EQ(1, ret.getStatus());
}

TEST(ALU, INVALID_OPCODE) {
	ALU alu;
	alu.setOperand1(-1);
	alu.setOperand2(20);
	alu.setOPCODE("WOW");

	Result ret;
	alu.enableSignal(&ret);

	EXPECT_EQ(65535, ret.getResult());
	EXPECT_EQ(3, ret.getStatus());
}
TEST(ALU, MULTest_op2_negative) {
	ALU alu;
	alu.setOperand1(20);
	alu.setOperand2(-1);
	alu.setOPCODE("MUL");

	Result ret;
	alu.enableSignal(&ret);

	EXPECT_EQ(65535, ret.getResult());
	EXPECT_EQ(2, ret.getStatus());
}

TEST(ALU, SUBTest) {
	ALU alu;
	alu.setOperand1(10);
	alu.setOperand2(20);
	alu.setOPCODE("SUB");

	Result ret;
	alu.enableSignal(&ret);

	EXPECT_EQ(-10, ret.getResult());
	EXPECT_EQ(0, ret.getStatus());
}

TEST(ALU, SUBTest_op1_negative) {
	ALU alu;
	alu.setOperand1(-1);
	alu.setOperand2(20);
	alu.setOPCODE("SUB");

	Result ret;
	alu.enableSignal(&ret);

	EXPECT_EQ(65535, ret.getResult());
	EXPECT_EQ(1, ret.getStatus());
}

TEST(ALU, SUBTest_op2_negative) {
	ALU alu;
	alu.setOperand1(20);
	alu.setOperand2(-1);
	alu.setOPCODE("SUB");

	Result ret;
	alu.enableSignal(&ret);

	EXPECT_EQ(65535, ret.getResult());
	EXPECT_EQ(2, ret.getStatus());
}
