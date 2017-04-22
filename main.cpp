#include <iostream>
#include "opencv2/core/core_c.h"
#include "opencv2/ml.hpp"
#include "opencv2/highgui/highgui_c.h"
#include "VerticalProfiles.h"

using namespace std;
using namespace cv;

int main( int argc, char** argv ) {

    VerticalProfiles test;
   test.proces(argv[1]);

}