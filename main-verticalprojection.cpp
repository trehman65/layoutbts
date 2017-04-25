#include <iostream>
#include "opencv2/core/core_c.h"
#include "opencv2/ml.hpp"
#include "opencv2/highgui/highgui_c.h"
#include "VerticalProfiles.h"


using namespace std;
using namespace cv;

int main( int argc, char** argv ) {

    //main vertical profiles
    vector<float> vertprof;
    VerticalProfiles test;
    test.process(argv[1],vertprof);


}

