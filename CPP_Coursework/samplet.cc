#ifndef SAMPLET_H
#define SAMPLET_H
#include <iostream>
#include <stdlib.h>
#include <utility>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;


template <class any> class samplet
{
public:
	samplet(){}
	
	samplet(vector<any> vctr){
		vectorT = vctr;
		sort(vectorT.begin(), vectorT.end());
	}
	
	const vector<any> get_data(){
		return vectorT;
	}
	
	void set_data(const vector<any> &v){
		vectorT = v;
		sort(vectorT.begin(), vectorT.end());
	}
	
	any minimum(){
		any min = vectorT[0];
		for(int i=0;i<vectorT.size();i++)
		{
			if(vectorT[i]<min)
				min=vectorT[i];
		}
		return min;
	}
	
	any maximum(){
		any max = vectorT[0];
		for(int i=0;i<vectorT.size();i++)
		{
			if(vectorT[i]>max)
				max=vectorT[i];
		}
		return max;
	}
	
	any range(){
		any rangeValue = (maximum() - minimum());
		return rangeValue;
	}
	
	any midRange(){
		any midRangeValue = (maximum()/2+minimum()/2);
		return midRangeValue;
	}
	
	any mean(){
		any mean = 0;
		int tSize = vectorT.size();
		for(int i=0;i<vectorT.size();i++)
		{
			mean = mean + (vectorT[i]/tSize);
		}
		return mean;
	}
	
	any variance(){
		any variance = 0;
		any meanValue = mean();
		any vectorValue = 0;
		int tSize = vectorT.size();
		for(int i=0;i<vectorT.size();i++)
		{
			vectorValue = vectorT[i];
			if(vectorValue > meanValue)
			{
				variance = variance + ((vectorValue - meanValue)/tSize*(vectorValue - meanValue));
			}else{
				variance = variance + ((meanValue - vectorValue)/tSize*(meanValue - vectorValue));
			}
		}
		return variance;
	}
	
	any std_deviation(){
		any deviation = sqrt(variance());
		return deviation;
	}
	
	any median(){
		any median;
		median = vectorT[(vectorT.size()/2)];
		if(vectorT.size() % 2 == 0)
		{
			median = vectorT[vectorT.size()/2-1]/2 + median/2;
		}
		return median;
	}
private:
	vector<any> vectorT;
};

#endif // SAMPLET_H
