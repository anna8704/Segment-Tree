# SIMPLE IMPLEMENTATION OF THE SEGMENT TREE

## Overview

This project builds a Segment Tree that allows users to query the sum and maximum sum over any arbitrary segment of an array in O(log N). In addition, user can update one single point in the Segment Tree that corresponds to a change at an index in the input array using a funciton which will also update the sum and maximum Sum for all ranges in the array that contain that updated index. For this project, we are using an input array of integers. 

## What does a user need for input:
- The input array
- Size of the input array which will trigger a calculation for the size of the Segment Tree

## How does this work ?
### 1. Node:
#### a. What is a Node ? 

In order to be build up the sum and the maximum sum for each arbitrary range in the input array, we need data points that hold the following pieces of info:
- prefixMaxSum: Maximum sum of a subarray, starting at the leftmost index of this range - this will help determine Maximum Sum
- suffixMaxSum: Maximum sum of a subarray, ending at the rightmost index of this range - this will help determine Maximum sum
- maxSum: Maximum sum of any subarray in this range
- sum: Sum of all elements in this range

Each Node would have a left and a right child which are the shorter left and right ranges that make up this longer range that the Node covers. As we are using an array to build a Tree, we don't necessarily need to factor these characters. Instead, we use the following formula for a root node that starts at index 1:
"left child" position in the   = stIndex * 2
right child = stIndex * 2 + 1

#### b. Starting out with the Leaf Nodes:

As the Segment Tree contains info on ranges from the input array, its construction starts with the info at each single index in the input array. Each of the values in the input array makes up a "leaf node".

The createLeafe function pulls the value at each index in the input array and set prefixMaxSum, suffixMaxSum, maxSum, sum to be this value. Later on when building the Segment Tree, such info will roll up into the resulting node for the ranges that spans more than one index. 

### 2. Segment Tree:

#### a. Creating the Segment Tree - Elements of the Segment Tree:

- N is the size of the input array. We need this details later on when running query and update functions
- SegmentTree_nodes - an array of nodes that contain info on the ranges: When the constructor is called, an array of Nodes is created which has the size that is 2 * the power of 2 that is just bigger than or equal to N. For example, if there are 4 elements, 2^2 is the smallest that is equal to or greater than 4. 2*2^2 = 2*4 = 8


#### b. Building the Segment Tree:

buildTree function (private) is part of the constructor which pulls data from the input array and fills up the nodes in the segmentTree_nodes array created with the right information. We can build a segment tree recursively in a depth first manner, starting at the root - the position of 1 in the array (representative of the whole input array), working our way towards the leaves (representatives of individual input array elements). Once both children of a node have returned, we can merge their aggregate statistics to form their "parent" node.

#### c. Querying the Segment Tree

- To query the sum of a range, call function querySum(int lo, int hi) with lo being the starting index (of the input array) and hi being the ending index of the range (in the input array)
- To query the sum of a range, call function querymaxSum(int lo, int hi) with lo being the starting index (of the input array) and hi being the ending index of the range (in the input array)

#### d. Updating the Segment Tree with a change in the input array

- To update a single index, call function update(int index, int value) with index being the index in the input array that is being changed and value being the new value
- The function first "binary searches" for the right leaf node in the segmentTree_nodes array, updates it and once that has been done, the value rolls back up all the way to the top such that all nodes that contain info on ranges which cover that index position will be updated. 

