// Forage-Sims-Store.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>


class Store : public Sim
{
private:
	std::string store_name;//Name of the store. Could be useful if there are multiple stores.
	std::pair<int, int> open_hours;//Store hours
	float balance;//Player's balance. Can be used to purchase items, or view balance after selling an item.
	std::unordered_map<std::string, int> inventory;//If any item is to be limited from bulk purchasing.
	int current_time;//The current in game time.
	std::string item;//Name of the item
	int quantity;//The amount of items that a user wants

public:
	Store(const std::string name, std::unordered_map<std::string, int> max_inventory) : store_name(name), inventory(max_inventory)
	{
		open_hours = { 9, 21 };//Hours set from 9 AM to 9 PM
	}//Default constructor
	void overlay(std::string& name, int time, float amount);//Function for an in-game overlay or key legend feature
	void StoreMap(std::string& name, float beginX, float beginY, float beginZ, float beginDirection);
	//Gets the name of the store, as well as the location of the character in order to ping them on the map
	void sell(std::string& itemName, float& balanceAmt, int& quantity);//Name of the item, and the current balance. A function to sell items
	void hold(std::string& item, int quantity);//Function that holds a certain item
	void buy(std::string& item, float& balanceAmt, std::unordered_map<std::string, int>& inventory, int& quantity);
	//a function to buy an item. This gets the item name, the current balance, check's the store's inventory
	//and the requested quantity of the item.

	//Getters and setters
	std::string getItem() const { return item; }//Gets the name of a certain item.
	float getBalance() const { return balance; }//Gets the balance.
	int getQuantity() const { return quantity;  }//Returns the quantity requested
	std::string setItem(std::string newItem) { item = newItem; }//Sets the item name
	float setBalance(float newBal) { balance = newBal; }//Sets the balance amount.
	int setQuantity(int newQuantity) { quantity = newQuantity; }//Sets the new quantity


};

class Sim//Class that controls for the movement of a Sim character.
{
private:
	float x;//Character's left and right movement
	float y; //Character's up and down movement
	float z; //For third dimensional movement
	float direction;//Direction that the character is facing

public:
	Sim(float beginX, float beginY, float beginZ, float beginDirection) 
	{
		x = beginX;
		y = beginY;
		z = beginZ;
		direction = beginDirection;
	};//Sim constructor
	void move(float time) {};//Function that moves the character
	void move_to(float endX, float endY, float endZ);//Function that gets the coordinates of a desired location,
													 //and moves the character to it
	float getX() const { return x; }//Getter for x value
	float getY() const { return y; }//Getter for y value
	float getZ() const { return z; }//Getter for z value

	void setX(float newX) { x = newX; }//Sets the x value
	void setY(float newY) { y = newY; }//Sets the y value
	void setZ(float newZ) { z = newZ; }//Sets the z value

	float getDirection() const { return direction; }//Gets the direction that the character is facing
	void setDirection(float newDirection) { direction = newDirection;  }
};


