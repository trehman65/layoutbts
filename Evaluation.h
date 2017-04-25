//
// Created by Talha Rehman on 4/25/17.
//

#ifndef LAYOUTBTS_EVALUATION_H
#define LAYOUTBTS_EVALUATION_H

#include <iostream>
#include "opencv2/core/core_c.h"
#include "opencv2/ml.hpp"
#include "opencv2/highgui/highgui_c.h"
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include "OneNearest.h"
#include "fstream"

using namespace std;
using namespace cv;

class Evaluation {

private:
    OneNearest eval;
    string pathToTrainData;
    string pathToTestData;
    vector<float> accuracy;
    void meanVector(vector<float>, float &);

public:
    Evaluation(string, string);
    void process(float &);

};


#endif //LAYOUTBTS_EVALUATION_H
