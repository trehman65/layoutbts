//
// Created by Talha Rehman on 4/24/17.
//

#include "OneNearest.h"
#include "VerticalProfiles.h"


OneNearest::OneNearest(string path) {

    string fname;
    fstream layoutfolder;
    VerticalProfiles layoutProfile;
    vector<int> hammingVector;

    for(int i=0; i<5; i++){

        fname=path+to_string(i)+".png";
        layoutProfile.process(fname,hammingVector);

        this->layouts[i].label=i+1;
        this->layouts[i].hammingVec=hammingVector;

        hammingVector.clear();
    }
}

float OneNearest::calculateDistance(std::vector<float> input, std::vector<float> layout) {

    vector<float> dist;
        for (int i = 0; i < input.size(); i++) {
            dist.push_back(pow(input[i]-layout[i],2));
        }
    return sum(dist);
}


bool OneNearest::isLonger(std::vector<float>input1, std::vector<float> input2) {

    return input1.size()>input2.size();
}


float OneNearest::sum(std::vector<float> input) {

    float sum=0;

    for(int i=0; i<input.size(); i++){
        sum+=input[i];
    }

    return sum;
}

void OneNearest::findNearestNeighbour(std::vector<int> input, int &label) {

    float sim=0;
    float absim=-1;

    for (int i=0; i<5 ;i++){
        sim=compHamming(input,layouts[i].hammingVec);
        if(sim>absim){
            label=layouts[i].label;
        }
    }
}

int OneNearest::compHamming(std::vector<int> input, std::vector<int> layout) {
    vector<float> dist;

    for(int i=0; i<input.size(); i++){
        dist.push_back(input[i]*layout[i]);
    }
    return sum(dist);

}

void process(string fname){

    VerticalProfiles input;
    int label;
    vector<int> hammingInput;
    input.process(fname,hammingInput);
    findNearestNeighbour(hammingInput,label);
    cout<<label;



}
