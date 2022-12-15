// If you change anything in this file, your changes will be ignored 
// in your homework submission.
// Chekout TEST_F functions bellow to learn what is being tested.
#include <gtest/gtest.h>
#include "../code/SegmentTree.h"

#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include <array>
#include <vector>

using namespace std;

class test_SegmentTree : public ::testing::Test {
protected:
	// This function runs only once before any TEST_F function
	static void SetUpTestCase(){
		std::ofstream outgrade("./total_grade.txt");
		if(outgrade.is_open()){
			outgrade.clear();
			outgrade << (int)0;
			outgrade.close();
		}
	}

	// This function runs after all TEST_F functions have been executed
	static void TearDownTestCase(){
		std::ofstream outgrade("./total_grade.txt");
		if(outgrade.is_open()){
			outgrade.clear();
			outgrade << (int)std::ceil(100*total_grade/max_grade);
			outgrade.close();
			std::cout << "Total Grade is : " << (int)std::ceil(100*total_grade/max_grade) << std::endl;
		}
	}

	void add_points_to_grade(double points){
		if(!::testing::Test::HasFailure()){
			total_grade += points;
		}
	}

	// this function runs before every TEST_F function
	void SetUp() override {}

	// this function runs after every TEST_F function
	void TearDown() override {
		std::ofstream outgrade("./total_grade.txt");
		if(outgrade.is_open()){
			outgrade.clear();
			outgrade << (int)std::ceil(100*total_grade/max_grade);
			outgrade.close();
		}
	}
	
	static double total_grade;
	static double max_grade;
};

double test_SegmentTree::total_grade = 0;
double test_SegmentTree::max_grade = 100;

/////////////////////////////////////////
// Test Helper Functions
/////////////////////////////////////////



std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

/////////////////////////////////////////
// Tests start here
/////////////////////////////////////////

int arr1[3] = {-2,1,1};
int arr2[4] = {-2,3,-5,8};
int arr3[8] = {1,1,1,1,1,1,1,1};
SegmentTree STTest1 = SegmentTree(arr1,3);
SegmentTree STTest2 = SegmentTree(arr2,4);
SegmentTree STTest3 = SegmentTree(arr3,8);

TEST_F(test_SegmentTree, TestGetSegmentTreesize){
	ASSERT_EQ(8,STTest1.getSegmentTreeSize(STTest1.N));
	cout<<"Passed GetSegmeentTreesize test for array size 3"<<endl;
	ASSERT_EQ(8,STTest2.getSegmentTreeSize(STTest2.N));
	cout<<"Passed GetSegmeentTreesize test for array size 4"<<endl;
	ASSERT_EQ(16,STTest3.getSegmentTreeSize(STTest3.N));
	cout<<"Passed GetSegmeentTreesize test for array size 8"<<endl;
	add_points_to_grade(25);
}

TEST_F(test_SegmentTree, TestQuerySum){
	ASSERT_EQ(-1,STTest1.querySum(0,1));
	cout<<"Passed QuerySum test for example 1"<<endl;
	ASSERT_EQ(6,STTest2.querySum(1,3));
	cout<<"Passed QuerySum test for example 2"<<endl;
	ASSERT_EQ(8,STTest3.querySum(0,7));
	cout<<"Passed QuerySum test for example 3"<<endl;
	add_points_to_grade(25);
}

TEST_F(test_SegmentTree, TestQueryMaxSum){
	ASSERT_EQ(1,STTest1.querymaxSum(0,1));
	cout<<"Passed QueryMaxSum test for example 1"<<endl;
	ASSERT_EQ(8,STTest2.querymaxSum(1,3));
	cout<<"Passed QueryMaxSum test for example 2"<<endl;
	ASSERT_EQ(8,STTest3.querySum(0,7));
	cout<<"Passed QueryMaxSum test for example 3"<<endl;
	add_points_to_grade(25);
}

TEST_F(test_SegmentTree, TestUpdate){
	arr1[0] = 2;
	STTest1.update(0,2);
	ASSERT_EQ(3,STTest1.querySum(0,1));
	cout<<"Passed Update test for example 1"<<endl;
	arr2[2] = 2;
	STTest2.update(2,2);
	ASSERT_EQ(13,STTest2.querySum(1,3));
	cout<<"Passed Update test for example 2"<<endl;
	arr3[2] = 2;
	STTest3.update(2,2);
	ASSERT_EQ(9,STTest3.querySum(0,7));
	cout<<"Passed Update test for example 3"<<endl;
	add_points_to_grade(25);
}