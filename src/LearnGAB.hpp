#ifndef _LEARNGAB_HPP
#define _LEARNGAB_HPP
#include "common.hpp"
#include "LearnDQT.hpp"
#include <opencv2/core/core.hpp>
#include "data.hpp"


class GAB{
  public:
    GAB(int);
    void LearnGAB(DataSet& pos, DataSet& neg);
    void SaveIter(vector<int>, vector<int>, vector<int>, vector< vector<unsigned char> >, vector<float>, float, float, int);
    void Save();
    int CalcTreeDepth(vector<int> leftChild, vector<int> rightChild, int node = 0);
    void TestDQT(float[], vector<float>, vector< vector<unsigned char> > , vector<int>, vector<int>, cv::Mat);
    void TestDQT(float[], vector<float>, vector< vector<unsigned char> > , vector<int>, vector<int>, cv::Mat, vector<int> );
    float TestSubTree(vector<float> ,vector< vector<unsigned char> > ,cv::Mat ,int ,int ,vector<int> leftChild, vector<int> rightChild,bool init);
    void CalcWeight(float F[], float Fx[], int y, int maxWeight, int);
    void CalcWeight(float F[], float Fx[], int y, int maxWeight, vector<int> negPassIndex);
    float NPDClassify(cv::Mat test);
    void GetPoints(int feaid, int *x1, int *y1, int *x2, int *y2);
    void MiningNeg(const int n,DataSet& neg,float[]);
  public:
    int stages;
    vector< vector<int> > feaIds, leftChilds, rightChilds;
    vector< vector< vector<unsigned char> > > cutpoints;
    vector< vector<float> > fits;
    vector<int> depths;
    vector<float> thresholds;
    vector<float> fars;
    vector<int> lpoints;
    vector<int> rpoints;
    cv::Mat ppNpdTable;

};
#endif