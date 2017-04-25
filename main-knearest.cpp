#include <iostream>
#include "opencv2/core/core_c.h"
#include "opencv2/ml.hpp"
#include "opencv2/highgui/highgui_c.h"
#include "OneNearest.h"


using namespace std;
using namespace cv;

int main( int argc, char** argv ) {


    //main Onenearest
    string path="/Users/talha/Desktop/traindata/";
    OneNearest testAll(path);
    float label;

    label=testAll.process(argv[1]);

    cout<<endl<<"Predicted Label: "<<label;



}

