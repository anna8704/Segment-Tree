#include "Node.h"


void Node::createLeaf(int value) {
    prefixMaxSum = suffixMaxSum = maxSum = sum = value;
}

void Node::merge(Node& left, Node& right) {
    this->sum = left.sum + right.sum;
    this->prefixMaxSum = max(left.prefixMaxSum, left.sum + right.prefixMaxSum);
    this->suffixMaxSum = max(right.suffixMaxSum, right.sum + left.suffixMaxSum);
    this->maxSum = max(prefixMaxSum, max(suffixMaxSum, max(left.maxSum, max(right.maxSum, left.suffixMaxSum + right.prefixMaxSum))));
}
  
int Node::getmaxSumValue() {
    return this->maxSum;
}

int Node::getSumValue() {
    return this->sum;
}







