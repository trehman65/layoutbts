#include <iostream>
#include "opencv2/core/core_c.h"
#include "opencv2/ml.hpp"
#include "opencv2/highgui/highgui_c.h"
#include "VerticalProfiles.h"

using namespace std;
using namespace cv;

int main( int argc, char** argv ) {

    VerticalProfiles test;

    Mat imgRgb=imread(argv[1]);

    vector<int> final;
    Mat imgBin;
    Mat imgGray;
    vector<int> verticalprofiles;
    vector<float> normverticalprofiles;
    vector<int> filterverticalprofiles;


    cvtColor(imgRgb,imgGray,CV_BGR2GRAY);
    test.binarizeShafait(imgGray,imgBin,50,0.3);
    test.verticalProjectionProfiles(imgBin,verticalprofiles);
    //test.gaussianSmoothing(verticalprofiles,filterverticalprofiles);
    test.normalizeHistogram(verticalprofiles,normverticalprofiles);
    test.plot(normverticalprofiles);

}