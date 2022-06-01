#include<iostream>
#include<vector>
#include "Category.h"

using namespace std;

void Category::display(){
	cout << "Name: " << catName << endl;
    cout << "ID: " << catId << endl;
    cout << "Description: " << description << endl;
}


int Category::getCatId(){
	return catId;
};

string Category::getCatName(){
	return catName;
}
string Category::getCatDescription(){
	return description;
}
vector<Product*> Category::getProducts(){
	return products;
}
void Category::addProduct(Product* product){
	products.push_back(product);
};