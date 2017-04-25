#include <iostream>
#include "opencv2/core/core_c.h"
#include "opencv2/ml.hpp"
#include "opencv2/highgui/highgui_c.h"
#include "Evaluation.h"


using namespace std;
using namespace cv;

int main( int argc, char** argv ) {

    //main evaluation
    string test="/Users/talha/Desktop/testdata/";
    string train="/Users/talha/Desktop/traindata/";
    Evaluation evaluator(train, test);
    float acc;
    evaluator.process(acc);
    cout<<endl<<"Overall Accuracy: "<<acc*100;

}

