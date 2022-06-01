#include<iostream>
#include "User.h"
#include <vector>
using namespace std;
vector<Category*> categories;

Product* User::productFromName(string item){
	categories.size();
	for(auto &c:categories){
		for(auto &p:c->getProducts()){
			if(p->getPname() == item){
				return p;
			}
		}
	}
	return nullptr;	
}

void User::allProducts(vector<Category*> categories){
	cout<<"All Products:"<<endl;
	for(int i =0; i< categories.size(); i++){
		for(int j = 0; j<categories.at(i)->getProducts().size();j++){
			cout<<" - "<<((categories.at(i))->getProducts()).at(j)->getPname()<<endl;
		}
	}
}

void User::addToBasket(string input){
	Product *item = productFromName(input);
	if(item == nullptr){
		cout<<"Please enter a valid item";
		return;
	}
    auto it = std::find_if(basket.begin(), basket.end(), [item](BasketProduct* prod){ return prod->getPname()==item->getPname();});
    size_t index = std::distance(basket.begin(), it);
    if (it != basket.end()){
        basket.at(index)->changeQuantity(1);
        
    }else{
        BasketProduct *bp = new BasketProduct(item);
        basket.push_back(bp);
    }
}

void User::viewBasket(){
    if (basket.size() == 0){
        cout << "Your Basket Is Empty" << endl;
    }else{
        for(int i = 0; i < basket.size(); i++)
        {
            cout << "Item: " << basket[i]->getPname()<< " Quantity: " << basket[i]->getQuantity() <<" Cost: "<<basket[i]->calculatePrice() << endl;
        }
        cout<<"\nYour total is : "<<calculateBasket()<<endl;
    }
}

void User::removeItem(string input, bool oneItem = true){
	Product *item = productFromName(input);
	if (item == nullptr){
		cout << "Please enter a valid item";
		return;
	}
 	auto it = std::find_if(basket.begin(), basket.end(), [item](BasketProduct *prod){ return prod->getPname()==item->getPname();});
  	size_t index = std::distance(basket.begin(), it);
	if (it != basket.end() && basket.at(index)->getQuantity() > 1 && oneItem){
    	basket.at(index)->changeQuantity(-1);
  	}else{
    	basket.erase(basket.begin() + index);
  	}
}

void User::clearBasket(){
	basket.clear();
}

double User::calculateBasket(){
	double total = 0;
	for(auto &b:basket){
		total += b->getPrice();
	}
	return total;
}

