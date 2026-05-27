#include <string>
#include "result.cpp"

class ALU
{
    int operand1 = -1;
    int operand2 = -1;
    std::string OPCODE = "";
private:
    const std::string ADD_OPCODE_STR = "ADD";
    const std::string MUL_OPCODE_STR = "MUL";
    const std::string SUB_OPCODE_STR = "SUB";
    const int INVALID_RESULT = 65535;
    const int NORMAL_STATUS = 0;
    const int OP1_INVALID_STATUS = 1;
    const int OP2_INVALID_STATUS = 2;
    const int OPCODE_INVALID_STATUS = 3;

    bool validate_opcode(const std::string& OPCODE) {
        return OPCODE == ADD_OPCODE_STR || OPCODE == MUL_OPCODE_STR || OPCODE == SUB_OPCODE_STR;
    }
    
    bool validate_input(Result* r, const std::string& OPCODE, const int& operand1, const int& operand2) {

        int valid_res = -1;
        if (!validate_opcode(OPCODE)) {
            valid_res = OPCODE_INVALID_STATUS;
        }
        else if (operand1 == -1) {
            valid_res = OP1_INVALID_STATUS;
        }
        else if (operand2 == -1) {
            valid_res = OP2_INVALID_STATUS;
        }

        if (valid_res > 0) {
            r->setResult(INVALID_RESULT);
            r->setStatus(valid_res);
            return false;
        }
        else {
            r->setStatus(NORMAL_STATUS);
            return true;
        }


    }

    int calculate()
    {
        if (OPCODE == ADD_OPCODE_STR) {
            return add();
        }
        else if (OPCODE == MUL_OPCODE_STR) {
            return mul();
        }
        else if (OPCODE == SUB_OPCODE_STR) {
            return sub();
        }
    }
    int sub()
    {
        return operand1 - operand2;
    }
    int mul()
    {
        return operand1 * operand2;
    }
    int add()
    {
        return operand1 + operand2;
    }
public:
    void setOperand1(int operand1) {
        this->operand1 = operand1;
    }

    void setOperand2(int operand2) {
        this->operand2 = operand2;
    }

    void setOPCODE(std::string OPCODE) {
        this->OPCODE = OPCODE;
    }

    void enableSignal(Result* r) {

        if (!validate_input(r, OPCODE, operand1, operand2)) return;

        r->setResult(calculate());
    }
};