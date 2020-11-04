#include <iostream>
#include"Menu.h"
#include"MenuItem.h"
#include"Waitress.h"

int main()
{
	MenuComponent* pancakeHouseMenu = new Menu("PANCAKE HOUSE MENU", "Breakfast", false);
	MenuComponent* dinerMenu = new Menu("DINER MENU", "Lunch", false);
	MenuComponent* cafeMenu = new Menu("CAFE MENU", "DINNER", false);
	MenuComponent* dessertMenu = new Menu("DESSERT MENU", "Dessert of course!", false);

	MenuComponent* allMenus = new Menu("ALL MENUS", "ALL menus combined", false);
	allMenus->add(pancakeHouseMenu);
	allMenus->add(dinerMenu);
	allMenus->add(cafeMenu);

	pancakeHouseMenu->add(new MenuItem("K&B's Pancake Breakfast", "Pancakes with scrambled eggs, and toast", true, 2.99, true));
	pancakeHouseMenu->add(new MenuItem("Regular Pancake Breakfast", "Pancakes with fried eggs,sausage", false, 2.99, true));
	pancakeHouseMenu->add(new MenuItem("Blueberry Pancakes", "Pancakes made with fresh blueberries, and blueberry syrup", true, 3.49, true));
	pancakeHouseMenu->add(new MenuItem("Waffles", "Waffles,with your choice of blueBerries or strawberries", true, 3.59, true));

	dinerMenu->add(new MenuItem("Vegetarian BLT","(Fakin') Bacon with lettuce & tomato on  whole wheat",true,2.99,true));
	dinerMenu->add(new MenuItem("BLT", "Bacon with lettuce & tomato on whole wheat", false, 2.99, true));
	dinerMenu->add(new MenuItem("Soup of the day", "a bowl of the soup of the day,with a side of patato salad", false, 3.29, true));
	dinerMenu->add(new MenuItem("Hotdog", "A hot dog with saurkraut,relish,onions,topped eith cheese", false, 3.05, true));
	dinerMenu->add(new MenuItem("Steamed Veggies and Brown Rice", "Steamed Veggies over Brown Rice", true, 3.99, true));
	dinerMenu->add(new MenuItem("Pasta", "Spaghetti with Marinara Sauce, and a slice of sourdough bread", true, 3.89, true));
	dinerMenu->add(dessertMenu);

	dessertMenu->add(new MenuItem("Apple Pie", "Apple pie with a flakey crust, topped with vanilla ice cream", true, 1.59, true));
	dessertMenu->add(new MenuItem("CheeseCake", "creamy New York cheesecake,with a chocolate graham crust", true, 1.99, true));
	dessertMenu->add(new MenuItem("Sorbet", "A scoop of raspberry and a scoop of lime", true, 1.89, true));

	cafeMenu->add(new MenuItem("Veggie Burger and Air Fries", "Veggie burger on whole wheat bun,lettuce,tomato,and fries", true, 3.99, true));
	cafeMenu->add(new MenuItem("Soup of the day", "A cup of the soup of the day,with a side salad", false, 3.69, true));
	cafeMenu->add(new MenuItem("Burrito", "A large burrito,with whole pinto beans,salsa,guacamole", true, 4.29, true));

	Waitress* waitress = new Waitress(allMenus);

	waitress->printMenu();
	waitress->printVegetarianMenu();
}