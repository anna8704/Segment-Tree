#ifndef SEGMENTTREE_H__
#define SEGMENTTREE_H__

//#include <string>
#include <memory>
#include <array>
#include <iostream>
#include "Node.h"

using namespace std;

class SegmentTree {

  vector<Node> segmentTree_nodes;

public:
  int N;
  //constructor - user should input array and size of array
  SegmentTree(int arr[], int N);

  int querymaxSum(int lo, int hi);
  int querySum(int lo, int hi);
  void update(int index, int value);
  int getSegmentTreeSize(int N);
        

private:
  //algorithm to recursively build segment tree in the constructor, inputs are the name of the input array, the starting index of the segmentTree array which is 1, the starting index of the input array which is 0 and ending index of input array which is array size N - 1. 
  void buildTree(int arr[], int stIndex, int lo, int hi);
  //algorithm to update one "leaf node" in the Segment Tree array and recursively roll up to all the ranges that include that index in the input array
  void update(int stIndex, int lo, int hi, int index, int value);
  //returns the "Node" that contains the relevant infor the the queried range
  Node getValue(int stIndex, int left, int right, int lo, int hi);
  
};

#endif 