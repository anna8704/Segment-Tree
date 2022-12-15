#ifndef NODE_H__
#define NODE_H__

#include <string>
#include <memory>
#include <vector>
#include <iostream>

using namespace std;


struct Node {
  int sum;
  int maxSum;
  int suffixMaxSum;
  int prefixMaxSum;


  void createLeaf(int value);
  void merge(Node& left, Node& right);
  int getmaxSumValue();
  int getSumValue();


};

#endif 