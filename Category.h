#include<iostream>
#include<vector>
#include "BasketProduct.cpp"

using namespace std;
class Category{
	
	private:
		int catId;
		string catName, description;
		vector<Product*> products;
	public:
		Category(int catId,string catName,string description):catId(catId),catName(catName),description(description){};
		void display();
		int getCatId();
		string getCatName();
		string getCatDescription();
		vector<Product*> getProducts();
		void addProduct(Product* product);
};

