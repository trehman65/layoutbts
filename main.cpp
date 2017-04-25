#include <iostream>
#include "opencv2/core/core_c.h"
#include "opencv2/ml.hpp"
#include "opencv2/highgui/highgui_c.h"
#include "VerticalProfiles.h"
#include "OneNearest.h"
#include "Evaluation.h"


using namespace std;
using namespace cv;

int main( int argc, char** argv ) {

    //main vertical profiles
//    vector<float> vertprof;
//    VerticalProfiles test;
//    test.process(argv[1],vertprof);

//    //main Onenearest
//    string path="/Users/talha/Desktop/traindata/";
//    OneNearest testAll(path);
//    cout<<testAll.process(argv[1]);


   //main evaluation
    string test="/Users/talha/Desktop/testdata/";
    string train="/Users/talha/Desktop/traindata/";
    Evaluation evaluator(train, test);
    float acc;
    evaluator.process(acc);
    cout<<endl<<"Overall Accuracy: "<<acc*100;

}

