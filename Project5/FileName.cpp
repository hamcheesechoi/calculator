#include <iostream>
#include <vector>
#define interface struct
using std::vector;

interface sort{
    virtual void run(vector<int>& arr) = 0;
};

class BubbleSort : public sort {
public:
    void run(vector<int>& arr) {
        std::cout << "bubble sort: ";
        for (int i = 0; i < arr.size(); i++) {
            for (int x = 0; x < arr.size() - i - 1; x++) {
                if (arr[x] > arr[x + 1]) {
                    std::swap(arr[x], arr[x + 1]);
                }
            }
        }
    }
};

class SelectionSort :public sort {
public:
    void run(vector<int>& arr) {
        std::cout << "selection sort: ";
        //selection sort
        for (int i = 0; i < arr.size(); i++) {
            for (int x = i + 1; x < arr.size(); x++) {
                if (arr[i] > arr[x]) {
                    std::swap(arr[i], arr[x]);
                }
            }
        }
    }

};

class SortPrinter {
private:
    vector<int> arr;
    sort* sortalg;
public:
	void insert(int value) {
		arr.push_back(value);
	}

    void selection(sort* sort) {
        this->sortalg = sort;
    }
    void run() {
        sortalg->run(arr);
    }
    void show() {
        for (int value : arr) {
            std::cout << value << " ";
        }
        std::cout << "\n";
    }
};

class SortFactory {
public:
    sort* createSort(std::string type) {
        if (type == "s") return new SelectionSort();
        if (type == "b") return new BubbleSort();
        return nullptr;
    }
};
int main() {

    vector<int> arr = { 4, 2, 1, 6, 8 };

    //test
    SortPrinter* sp = new SortPrinter();
    SortFactory* sf = new SortFactory();

    //sp->insert(1);sp->insert(3);sp->insert(2);
    for (int num : arr) {
        sp->insert(num);
    }
    sp->selection(sf->createSort("s"));
    sp->run();
    sp->show();


    return 0;
}