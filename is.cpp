#include<iostream>
#include<limits.h>
#include<cstdlib>
#include<fstream>
#include<time.h>

using namespace std;

int insertionSort(int arr[], int size){
    int comparisons=0;

    for(int i=1;i<size;i++){
        int j=i-1;
        while(j>=0 && arr[j]>arr[j+1]){
            int temp=arr[j];
            arr[j]= arr[j+1];
            arr[j+1]=temp;
            comparisons++;
        }
    }
    return comparisons;
}

int main(){

    ofstream outfile("isAnalysis.csv");
    outfile<<"size,"<<"bestcase,"<<"worstcase,"<<"averagecase"<<endl;

    for(int i=10;i<=100;i+=5){
        int bestcase=INT_MAX;
        int worstcase=INT_MIN;
        int averagecase=0;
        int size=i;

        for(int k=0;k<10;k++){
            int comparisons=0;

            srand(time(0));
            int arr[size];

            for(int j=0;j<size;j++){
                arr[j]=rand()%(size+1);
            }

            comparisons=insertionSort(arr, size);

            bestcase=min(comparisons,bestcase);
            worstcase=max(comparisons,worstcase);
            averagecase += (comparisons/10);

        }

        cout<<"size = "<<size<<endl;
        cout<<"bestcase comparisons = "<<bestcase<<endl;
        cout<<"worstcase comparisons "<<worstcase<<endl;
        cout<<"averagecase comparisons = "<<averagecase<<endl;
        cout<<"---------------------------------------------------"<<endl;

        outfile<<size<<","<<bestcase<<","<<worstcase<<","<<averagecase<<endl;
    }

    outfile.close();

    return 0;
}