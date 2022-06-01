#include<iostream>
#include<vector>
#include "Admin.cpp"
#include <conio.h>
using namespace std;
    
User user;
Admin admin;
void adminOptions()
{
    int input;
    cout<<"Hello admin! ";
    do
    {
        cout<<"What would you like to do?"<<endl;
        cout<<"1) Add products"<<endl;
        cout<<"2) Add categories"<<endl;
        cout<<"3) See Records based on price range"<<endl;
        cout<<"4) See records based on category name"<<endl;
        cout<<"5) See all records"<<endl;
        cout<<"6) Log out"<<endl;
        cin>>input;
        switch(input)
        {
            case 1:{
			
			
            	double price;
            	int catId;
            	string name;
            	cout<<"\nPlease enter the name of the product"<<endl;
            	cin>>name;
            	cout<<"\nPlease enter the Category Id\n"<<endl;
            	cin>>catId;
            	cout<<"\nPlease enter the price of the item\n"<<endl;
            	cin>>price;
                admin.addProduct(price, name, catId);
                break;
            }
            case 2:{
			
            	int catId;
            	string name, description;
            	cout<<"\nPlease enter the name of the category\n"<<endl;
            	cin>>name;
            	cout<<"\nPlease enter the Category Id\n"<<endl;
            	cin>>catId;
				cout<<"\nPlease enter a brief description of the category\n"<<endl;
				getline(cin, description);
            	getline(cin, description);
                admin.addCategory(catId, name,description);
                break;
        	}
                
            case 3:{
            	double upperBound, lowerBound;
            	cout<<"\nPlease enter an upper and lower bound for the search\n "<<endl;
            	cin>>upperBound;
            	cin>>lowerBound;
            	admin.getRecord(lowerBound,upperBound);
				break;
			}
                
            case 4:{
            	string name;
            	cout<<"\nPlease enter the name of the category you want to find\n"<<endl;
            	cin>>name;
            	admin.getRecord(name);            	
				break;
			}
			case 5:{
				admin.getAllRecords();
				break;
			}
			case 6:
				cout<<"\nGoodbye!\n"<<endl;
            	break;
            case 7:
            	break;
            default:
                cout<<"Invalid input, try again"<<endl;
        }        
    }while(input!=6);
    return;
}




void userOptions()
{
    int input;
    cout<<"Hello User! "<<endl;
    do
    {
        cout<<"What would you like to do?"<<endl;
        cout<<"1) View products"<<endl;
        cout<<"2) Add Product"<<endl;
        cout<<"3) View Cart"<<endl;
        cout<<"4) Remove Item(s)"<<endl;
        cout<<"5) Empty Basket"<<endl;
        cout<<"6) Get Total"<<endl;
        cout<<"7) Log out"<<endl;
        cin>>input;
        switch(input)
        {
            case 1:
                user.allProducts(admin.getCatagories());
                break;
            case 2:{
				string name;
            	cout<<"\nPlease enter the product you want to add: \n";
            	cin>>name;
            	user.addToBasket(name);
            	break;
            }
            	
            case 3:
                user.viewBasket();
                break;     
            case 4:{
				
			    string product;
            	char yesOrNo;
            	cout<<"\nPlease enter the name of the product you would like to remove"<<endl;
            	cin>>product;
            	cout<<"\nWould you like to remove all copies of that product? Y/N";
            	cin>>yesOrNo;
            	if(yesOrNo=='Y'){
            		user.removeItem(product,false);
				}else{
					user.removeItem(product);
				}
            	break;
            }
            case 5:
            	user.clearBasket();
            	break;
			case 6:     
				cout<<"\nYour total is: " <<user.calculateBasket()<<"\n";     
				break; 	
            case 7:
                cout<<"Goodbye!"<<endl;
                break;
            default:
                cout<<"Invalid input, try again"<<endl;
        }
        
        
    }while(input!=7);
    return;
}
void init(){
	admin.addCategory(10,"Fish","found in water");
    admin.addCategory(20,"Meat", "found on land");

    admin.addProduct(15.00,"Salmon",10);
    admin.addProduct(10.25,"Haddock",10);
    admin.addProduct(8.00,"Cod",10);
    admin.addProduct(6.00,"Beef",20);
    admin.addProduct(4.50,"Chicken",20);
    admin.addProduct(8.50,"Pork",20);
}
int main(){

	init();
    
    int input;
    
    do
    {
        cout<<"1) Log in as admin"<<endl;
        cout<<"2) Log in as user"<<endl;
        cout<<"3) Exit application"<<endl;
        cin>>input;
        switch(input)
        {
            case 1:
                adminOptions();
                break;
            case 2:
                userOptions();
                break;
            case 3:
                break;
                
            default:
                cout<<"Invalid input, try again"<<endl;
        }
        
        
    }while(input!=3);
       
    
}