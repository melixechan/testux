#include <iostream>
#include <string>

using namespace std;

class vector {
private:
	int size;
	std::string id;
	double* data;
public:
	vector(int size, std::string id);
	void print();
	void setId(std::string id);
};

vector :: vector (int size, std::string id = "unknown") {
	this->size = size;
	this->id = id;

	data = new double [size];
	for (int i = 0; i < size; i++) {
		data[i] = 0.01;
	}
}

void vector :: print () {
	cout << id << " " << size <<  endl;
	for (int i = 0; i < size; i++) {
		cout << data[i] << " ";
	}
	cout << endl;
}

void vector :: setId(std::string id) {
	this->id = id;
}

int main(){
	vector v1(5, "first one");
	vector v2(7, "second one");
	v1.setId("new id");
	v1.print();
	v2.print();
	return 0;
}
