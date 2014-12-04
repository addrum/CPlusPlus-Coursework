#ifndef SAMPLE_H
#define SAMPLE_H
#include <vector>
using namespace std;

class sample
{
public:
	sample();
	sample(vector<double> vctr);
	const vector<double> get_data();
	void set_data(const vector<double> &v);
	double minimum();
	double maximum();
	double range();
	double midRange();
	double mean();
	double variance();
	double std_deviation();
	double median();
private:
	vector<double> doubleV;
};

#endif // SAMPLE_H
