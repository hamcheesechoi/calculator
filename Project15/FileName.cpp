#include<iostream>
#include<string>
using std::string;

class Cut {
public:
	class Hair {
	public:

		Hair& setFront(int front) {
			cut->f = front;
			return *this;
		}
		Hair& setSide(int side) {
			cut->s = side;
			return *this;
		}
		Hair& setBack(int back) {
			cut->b = back;
			return *this;
		}
		Cut* build() {
			if (cut->f == 0 || cut->s == 0 || cut->b == 0)return nullptr;
			return cut;
		}
	private:
		Cut* cut = new Cut();
	};
private:
	Cut() {};
	Cut(int front, int side, int back) :f{ front }, s{ side }, b{ back } {};
	int f, s, b;
};

class CutPointer {
public:
	CutPointer() {};
	CutPointer* setFront(int front) {
		this->f = front;
		return this;
	}
	CutPointer* setSide(int side) {
		this->s = side;
		return this;
	}
	CutPointer* setBack(int back) {
		this->b = back;
		return this;
	}
private:
	int f, s, b;
};

int main() {
	//Cut cut;
	//cut.setFront(2).setSide(3).setBack(4);


	////cut.setSide(3);
	////cut.setBack(4);

	//CutPointer* cutPointer = new CutPointer();// < -주소를 찾아가서 메소드를 사용
	//cutPointer->setFront(4)->setSide(3)->setBack(2);
	Cut* cut = new Cut()
	Cut* cut = Cut::Hair().setBack(3).setSide(2).setFront(5).create();
}