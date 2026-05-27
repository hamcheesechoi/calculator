#include <iostream>
#include <vector>

using std::string;
using std::vector;
using std::cout;

class Node {
public:
    int dateCode;
    string name;

    Node(int dateCode, string name) {
        this->dateCode = dateCode;
        this->name = name;
    }
};

class Sign {
public:
    void makeSign(vector<Node>& signVector) {

        //2. valid 검사
        bool flag = false;
        valiate(signVector, flag);

        if (flag == false) {
            throw "Invalid dateCode";
        }

        //1. 서명 정렬하기
        sort_sign(signVector);

        //3. 서명하기
        sign(signVector);
    }
private:
    void sign(std::vector<Node>& signVector)
    {
        for (Node tar : signVector) {
            cout << tar.dateCode << " : " << tar.name << std::endl;
        }
    }
    void valiate(std::vector<Node>& signVector, bool& flag)
    {
        for (Node tar : signVector) {
            if (tar.dateCode > 0 && tar.dateCode < 10) continue;
            flag = true;
            break;
        }
    }
    void sort_sign(std::vector<Node>& signVector)
    {
        for (int y = 0; y < signVector.size(); y++) {   
            for (int x = y + 1; x < signVector.size(); x++) {
                if (signVector[y].dateCode > signVector[x].dateCode) {
                    Node temp(signVector[y].dateCode, signVector[y].name);
                    signVector[y].dateCode = signVector[x].dateCode;
                    signVector[y].name = signVector[x].name;
                    signVector[x].dateCode = temp.dateCode;
                    signVector[x].name = temp.name;
                }
            }
        }
    }
};

int main() {
    Sign sign;
    vector<Node> arr;
    arr.push_back(Node(5, "KFC"));
    arr.push_back(Node(1, "JASON"));
    arr.push_back(Node(2, "LUCKY"));

    try {
        sign.makeSign(arr);
    }
    catch (const char* msg) {
        std::cerr << msg << std::endl;
    }

    return 0;
}