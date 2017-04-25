//
// Created by Talha Rehman on 4/25/17.
//

#include "Evaluation.h"

Evaluation::Evaluation(string trainPath, string testPath) {

    pathToTrainData=trainPath;
    eval=OneNearest(pathToTrainData);
    pathToTestData=testPath;
    std::cout<<"Training Done"<<endl;
}


void Evaluation::process(float &acc){


    string pathToImage;
    string pathToFolder;
    string pathToTxt;
    fstream filesTxt;
    string image;
    int labelPredicted;


    for(int i=1; i<=5; i++){

        cout<<"Testing on class "<<i<<endl;

        pathToFolder=pathToTestData+to_string(i)+"/";
        pathToTxt=pathToFolder+"files.txt";

        filesTxt.open(pathToTxt);

        while(getline(filesTxt,image)){

            pathToImage=pathToFolder+image;
            cout<<"Processing:"<<pathToImage;

            if(eval.process(pathToImage)==i){
                cout<<": Matched"<<endl;
                accuracy.push_back(1);
            }
            else{
                cout<<": Not Matched"<<endl;
                accuracy.push_back(0);
            }

        }
        filesTxt.close();
    }

    meanVector(accuracy,acc);
}


void Evaluation::meanVector(vector<float> input, float &acc) {

    float sum=0;
    float count=0;
    for(int i=0; i<input.size(); i++){
        sum+=input[i];
        count++;
    }

    acc = sum/count;
}
