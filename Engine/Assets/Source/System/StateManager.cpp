#include "StateManager.h"
#include<iostream>


namespace sp{

	StateManager::StateManager() {}
	StateManager::~StateManager() {}


	void StateManager::addState(State *state) {
		stateStack.push_back(state);
	}

	void StateManager::deleteState() {
		delete stateStack.back();
	}

	void StateManager::pauseStates() {
		for (int i = 0; i < stateStack.size(); i++)
			stateStack[i]->pause();
	}
	void StateManager::pauseState(std::string stateName) {
		for (int i = 0; i < stateStack.size(); i++) {
			if (stateStack[i]->getName() == stateName) {
				stateStack[i]->pause();
				return;
			}
		}
		std::cout << "Couldn't find state with the name \"" + stateName + "\"" << std::endl;
	}

	void StateManager::updateStates(sf::Event event) {
		for (int i = 0; i < stateStack.size(); i++)
			stateStack[i]->update(event);
	}
	void StateManager::drawStates(Window *window) {
		for (int i = 0; i < stateStack.size(); i++)
			stateStack[i]->draw(window);
	}

	//void StateManager::reindexState(std::string name, int newIndex) { 
		//
	//}
	//void StateManager::reindexState(int oldIndex, int newIndex) {
		//
	//}
}