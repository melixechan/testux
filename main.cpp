#include <iostream>
#include <string>
#include "vector.h"
#include "matrix.h"
using namespace std;


vector multiply(matrix m, vector v) {
	vector result(m.size, "mult");
	for (int i = 0; i < m.size; i++) {
		result.data[i] = 0;
		for (int j = 0; j < v.size; j++) {
			result.data[i] += m.data2d[i][j] * v.data[j];
		}
	}
	return result;
};

vector operator+(vector v, vector u) {
	vector w(v.size, "plus");
	for (int i = 0; i < v.size; i++){
		w.data[i] = v.data[i] + u.data[i];
	}
	return w;
};

vector operator*(double a, vector v){
	vector w(v.size, "mult");
	for (int i = 0; i < v.size; i++){
		w.data[i] = a * v.data[i];
        }
        return w;
};

vector operator-(vector v, vector u) {
	vector w(v.size, "minus");
	for (int i = 0; i < v.size; i++){
		w.data[i] = v.data[i] - u.data[i];
	}
	return w;
};


vector simple_iter(matrix A, vector b, double eps){
	vector x_prev(A.size);
	x_prev.set_data(b.size, b.data);
	vector x(A.size);
	vector error(A.size);
	error = x_prev;

	double tau = 2 / A.norm_frob();

        while (error.norm2() > eps){
		x = x_prev - tau * multiply(A, x_prev) + tau*b;		
		error = x - x_prev;
		x_prev = x;
	}
	cout << "Error = " <<  error.norm2() << endl;
	return x;
};


int main(){
	cout << "Working fine!" << endl;
	
	vector v1(5, "first vector");
	vector v2(2, "second vector");
	v1.print();
	v2.print();

	vector v3(5);
	double arrow[5] = {1, 2, 3, 4, 5};
	v3.set_data(5, arrow);
	v3.print();
	matrix m(2, "first matrix");
	double** arrow2 = new double*[2];
	arrow2[0] = new double[2]{10, 5};
	arrow2[1] = new double[2]{7, 14};
	m.set_data(2, arrow2);
	m.print();
	
	vector b(2);
	double arrow3[2] = {1, 2};
	b.set_data(2, arrow3);
	vector answer(2);
	answer = simple_iter(m, b, 0.0001);
	answer.print();
	cout << endl;
	

	return 0;
}
