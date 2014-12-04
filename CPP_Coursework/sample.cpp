#include "sample.h"
#include <iostream>
#include <stdlib.h>
#include <utility>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;


sample::sample(){
	
	}
	
sample::sample(vector<double> vctr){
	doubleV = vctr;
	sort(doubleV.begin(), doubleV.end());
}

const vector<double> sample::get_data(){
	return doubleV;
}

void sample::set_data(const vector<double> &v){
	doubleV = v;
	sort(doubleV.begin(), doubleV.end());
}

double sample::minimum(){
	double min = doubleV[0];
	int tSize = doubleV.size();
	for(int i=0;i<tSize;i++)
	{
		if(doubleV[i]<min)
			min=doubleV[i];
	}
	return min;
}

double sample::maximum(){
	double max = doubleV[0];
	int tSize = doubleV.size();
	for(int i=0;i<tSize;i++)
	{
		if(doubleV[i]>max)
			max=doubleV[i];
	}
	return max;
}

double sample::range(){
	double rangeValue = (maximum() - minimum());
	return rangeValue;
}

double sample::midRange(){
	double midRangeValue = (maximum()/2+minimum()/2);
	return midRangeValue;
}

double sample::mean(){
	double mean = 0;
	int tSize = doubleV.size();
	for(int i=0;i<tSize;i++)
	{
		mean = mean + (doubleV[i]/tSize);
	}
	return mean;
}

double sample::variance(){
	double variance = 0;
	double meanValue = mean();
	double vectorValue = 0;
	int tSize = doubleV.size();
	for(int i=0;i<tSize;i++)
	{
		vectorValue = doubleV[i];
		if(doubleV[i] > meanValue)
		{
			variance = variance + (((vectorValue - meanValue)*(vectorValue - meanValue))/tSize);
		}else{
			variance = variance + (((meanValue - vectorValue)*(meanValue - vectorValue))/tSize);
		}
	}
	return variance;
}

double sample::std_deviation(){
	return sqrt(variance());
}

double sample::median(){
	double median;
	median = doubleV[(doubleV.size()/2)];
	if(doubleV.size() % 2 == 0)
	{
		median = doubleV[doubleV.size()/2-1]/2 + median/2;
	}
	return median;
}