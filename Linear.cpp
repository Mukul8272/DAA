#include<iostream>
#include<math.h>
#include<limits.h>
#include<stdio.h>
#include<fstream>

using namespace std;

int main(){
    ofstream outputfile("Analysis.csv");
    outputfile<<"DataSize,BestCase,WorstCase,AverageCase\n";

    for(int i=10;i<=100;i+=10){
        int size=i;
        int bestcase=INT_MAX;
        int Worstcase=INT_MIN;
        int averagecase=0;
        int totalcomparisons=0;

        int arr[size];
        for(int j=1;j<=size;j++){
            arr[j-1]=i;
        }

        int test[size+1];
        for(int j=1;j<=size+1;j++){
            test[j-1]=j;
        }

        //comparing test cases
        for(int j=0;j<size+1;j++){
            int testcase=test[j];
            int comparison=0;

            //comparing input array with testcases
            for(int k=0;k<size;k++){
                comparison++;
                if(arr[k]==testcase) break;
            }

            totalcomparisons=totalcomparisons+comparison;
            bestcase=min(bestcase,comparison);
            Worstcase=max(Worstcase,comparison);
        }
        averagecase=(totalcomparisons/2)/size;

        outputfile<< size <<","<< bestcase <<","<< Worstcase<<","<< averagecase<<endl;

        cout<<"Data Size: "<< size<<endl;
        cout<<"Bestcase comparisons: "<< bestcase<<endl;
        cout<<"worstcase comparisons: "<< Worstcase<<endl;
        cout<<"averagecase comparisons: "<< averagecase<<endl;
        cout<<"-------------------------------------"<<endl;

    }
    outputfile.close();
    return 0;
}