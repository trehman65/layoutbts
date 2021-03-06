//
// Created by Talha Rehman on 4/24/17.
//

#ifndef LAYOUTBTS_KNEAREST_H
#define LAYOUTBTS_KNEAREST_H

#include <iostream>
#include "opencv2/core/core_c.h"
#include "opencv2/highgui/highgui_c.h"
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <cmath>
#include "VerticalProfiles.h"
#include "fstream"

struct layout{
    float label;
    std::vector<float> normVerticalProjection;
};

class OneNearest {

public:
    float process(string);
    OneNearest();
    OneNearest(string path);

private:
    vector<layout> layouts;

    float calculateDistance(std::vector<float>, std::vector<float>);
    bool isLonger(std::vector<float>,std::vector<float>);
    float sum(std::vector<float>);
    void findNearest(std::vector<float>, float &);
    float compHamming(std::vector<float>, std::vector<float>);

};


#endif //LAYOUTBTS_KNEAREST_H
