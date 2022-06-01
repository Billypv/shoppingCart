#include<iostream>
#include<vector>
#include"Product.cpp"

using namespace std;

class BasketProduct : public Product{
	private:
		int quantity = 1;
		int price;
	public:
    	BasketProduct(Product *p);
    	int getQuantity();
    	void changeQuantity(int amount);
    	double calculatePrice();
    	double getPrice();
};