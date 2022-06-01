#include<iostream>
#include<vector>
#include<iostream>
#include<algorithm>
#include "Category.cpp"
using namespace std;

class User{
	protected:
		vector<BasketProduct*> basket;
	public:
		void allProducts(vector<Category*> categories);	
		void addToBasket(string input);
		void viewBasket();
		void removeItem(string input, bool oneItem);
		void clearBasket();
		Product *productFromName(string item);
		double calculateBasket();
};