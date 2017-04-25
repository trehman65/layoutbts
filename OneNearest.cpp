//
// Created by Talha Rehman on 4/24/17.
//

#include "OneNearest.h"
#include "VerticalProfiles.h"


OneNearest::OneNearest(string path) {

    string fname;
    VerticalProfiles layoutProfile;
    vector<float> verticalProjection;
    layout temp;

    for(int i=0; i<5; i++){

        fname=path+to_string(i+1)+".JPG";
        layoutProfile.process(fname,verticalProjection);

        temp.label=i+1;
        temp.normVerticalProjection=verticalProjection;

        layouts.push_back(temp);

        verticalProjection.clear();
    }
}

OneNearest::OneNearest() {

}

float OneNearest::calculateDistance(std::vector<float> input, std::vector<float> layout) {

    vector<float> dist;
        for (float i = 0; (i < input.size()) && (i < layout.size()); i++) {
            dist.push_back(abs(input[i]-layout[i]));
        }
    return sum(dist);
}


bool OneNearest::isLonger(std::vector<float>input1, std::vector<float> input2) {

    return input1.size()>input2.size();
}


float OneNearest::sum(std::vector<float> input) {

    float sum=0;

    for(float i=0; i<input.size(); i++){
        sum+=input[i];
    }

    return sum;
}

void OneNearest::findNearest(std::vector<float> input, float &label) {

    float dist=5;
    float abdis=1;
    label=0;

    cout<<", Distances: ";

    for (float i=0; i<5 ;i++){

        dist=calculateDistance(input,layouts[i].normVerticalProjection);
        cout<<dist<<" ";
        if(dist<abdis){
            label=layouts[i].label;
            abdis=dist;
        }
    }
}

float OneNearest::compHamming(std::vector<float> input, std::vector<float> layout) {

    vector<float> dist;

    for(float i=0; (i<input.size()) && (i < layout.size()); i++){
        dist.push_back(input[i]*layout[i]);
    }
    return sum(dist);

}

float OneNearest::process(string fname){

    VerticalProfiles input;
    float label;
    vector<float> verticalInput;

    input.process(fname,verticalInput);
    findNearest(verticalInput,label);
    verticalInput.clear();

    return label;

}
//TODO: use same function for boht float and float type
