/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:29:15 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/12 15:09:58 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"

#include <iostream>
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void subjectTest(){
	std::cout << std::endl << "SUBJECT TEST - START" << std::endl;
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << i->gettype() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		std::cout << j->gettype() << " " << std::endl;
		j->makeSound();
		meta->makeSound();
		delete meta;
		delete i;
		delete j;
	}
	std::cout << "SUBJECT TEST - END" << std::endl;
}
void wrongSubjectTest(){
	std::cout << std::endl << "WRONG SUBJECT TEST - START" << std::endl;
	{
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();

		std::cout << i->gettype() << " " << std::endl;
		i->makeSound(); 
		meta->makeSound();
		delete meta;
		delete i;
	}
	std::cout << "WRONG SUBJECT TEST - END" << std::endl;
}
void testDog(){
	std::cout << std::endl << "DOG TEST - START" << std::endl;
	{
		Dog stack_dog;
		Dog *heap_dog = new Dog();

		std::cout << "stack_dog gettype: " << stack_dog.gettype() << std::endl;
		std::cout << "stack_dog sound: ";
		stack_dog.makeSound();

		std::cout << "heap_dog gettype: " << heap_dog->gettype() << std::endl;
		std::cout << "heap_dog sound: ";
		heap_dog->makeSound();
		delete heap_dog;
	}
	std::cout << "DOG TEST - END" << std::endl;
}

void testCat(){
	std::cout << std::endl << "CAT TEST - START" << std::endl;
	{
		Cat stack_cat;
		Cat *heap_cat = new Cat();

		std::cout << "stack_cat gettype: " << stack_cat.gettype() << std::endl;
		std::cout << "stack_cat sound: ";
		stack_cat.makeSound();

		std::cout << "heap_cat gettype: " << heap_cat->gettype() << std::endl;
		std::cout << "heap_cat sound: ";
		heap_cat->makeSound();
		delete heap_cat;
	}
	std::cout << "CAT TEST - END" << std::endl;
}
void testAnimal(){
	std::cout << std::endl << "ANIMAL TEST - START" << std::endl;
	{
		Animal stack_animal;
		Animal *heap_animal = new Animal();

		std::cout << "stack_animal gettype: " << stack_animal.gettype() << std::endl;
		std::cout << "stack_animal sound: ";
		stack_animal.makeSound();

		std::cout << "heap_animal gettype: " << heap_animal->gettype() << std::endl;
		std::cout << "heap_animal sound: ";
		heap_animal->makeSound();
		delete heap_animal;
	}
	std::cout << "ANIMAL TEST - END" << std::endl;
}
int main(void){
	subjectTest();
	wrongSubjectTest();
	testDog();
	testCat();
	testAnimal();
	return (0);
}