#include<iostream>
#include "User.cpp"
using namespace std;

class Admin:public User{
	public:
		vector<Category*> getCatagories();
		void addCategory(int catId, string catName, string description); 
		void addProduct(double price,  string pname, int catId);
		void getRecord(string catName);
		void getRecord(double lowerBound, double upperBound);
		void getAllRecords();
};