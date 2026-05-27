#include <string>
#define interface struct
using std::string;

interface insa{
	virtual string hello() = 0;
};

class formal : public insa {
	string hello() override {

		return "Good evening, sir.";
	}
};
class casual : public insa {
	string hello() override {

		return "Sup bro?";
	}

};
class intimate : public insa {
	string hello() override {

		return "Hello Darling!";
	}

};
class normal : public insa {
	string hello() override {

		return "Hello.";
	}

};

class insaFactory {
public:
	insa* createInsa(string type) {
		insa* ins;
		if (type == "formal") {
			ins = new formal();
		}
		else if (type == "casual") {
			ins = new casual();
		}
		else if (type == "intimate") {
			ins = new intimate();
		}
		else {
			ins = new normal();
		}
	}
};

class Greeter {
private:
	insaFactory* insf;
	insa* ins;
public:
	string Greet() {
		insf = new insaFactory();
		ins = insf->createInsa(formality_);
		ins->hello();
	}

	void SetFormality(string formality) {
		formality_ = formality;
	}

private:
	string formality_;
};