#include "SegmentTree.h"
#include <iostream>


using namespace std;

//constructor
SegmentTree::SegmentTree(int arr[], int N) {
    this->N = N;
    segmentTree_nodes = vector<Node>(getSegmentTreeSize(N));
    buildTree(arr, 1, 0, N-1);
}


int SegmentTree::querymaxSum(int lo, int hi) {
    Node result = getValue(1, 0, N-1, lo, hi);
    return result.getmaxSumValue();
}

int SegmentTree::querySum(int lo, int hi) {
    Node result = getValue(1, 0, N-1, lo, hi);
    return result.getSumValue();
}

Node SegmentTree::getValue(int stIndex, int left, int right, int lo, int hi) {
    //ending condition, the stIndex is the node that has the aggregate for range [left,right]
    if (left == lo && right == hi)
      return this->segmentTree_nodes[stIndex];
    //binary search, if low > mid, look to the right; if high < mid, look to the left
    int mid = (left + right) / 2;
    if (lo > mid) {
      return getValue(2*stIndex+1, mid+1, right, lo, hi);
    }
    if (hi <= mid) {
      return getValue(2*stIndex, left, mid, lo, hi);

    }
    // low < mid < high-> merge new values  
    Node leftResult = getValue(2*stIndex, left, mid, lo, mid);
    Node rightResult = getValue(2*stIndex+1, mid+1, right, mid+1, hi);
    Node result;
    result.merge(leftResult, rightResult);
    return result;

}

void SegmentTree::update(int index, int value) {
    update(1, 0, N-1, index, value);
}

void SegmentTree::update(int stIndex, int lo, int hi, int index, int value) {
    if (lo == hi) {

    this->segmentTree_nodes[stIndex].createLeaf(value);
    return;
    }
    int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
    // if index positive < mid, look to the left
    if (index <= mid)
      update(left, lo, mid, index, value);
    // else look for the leaf node on the right side
    else
      update(right, mid+1, hi, index, value);
    //recursively goes back up the same path
    this->segmentTree_nodes[stIndex].merge(this->segmentTree_nodes[left], this->segmentTree_nodes[right]);
}

int SegmentTree::getSegmentTreeSize(int N) {
  int size = 1;
  for (;size<N;size<<=1);
  return size*2;
}

void SegmentTree::buildTree(int arr[], int stIndex, int lo, int hi) {
    //ending condition
    if (lo == hi) {
      this->segmentTree_nodes[stIndex].createLeaf(arr[lo]);
      return;
    }
    
    int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
    buildTree(arr, left, lo, mid);
    buildTree(arr, right, mid + 1, hi);
    this->segmentTree_nodes[stIndex].merge(this->segmentTree_nodes[left], this->segmentTree_nodes[right]);
}














