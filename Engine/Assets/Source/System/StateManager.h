#pragma once

#include<vector>
#include"State.h"
#include"Window.h"

namespace summit{
	class StateManager {
		std::vector<State*> stateStack;

	public:
		StateManager();
		~StateManager();

		void addState(State *state);
		void deleteState();
		void pauseStates();
		void pauseState(std::string stateName);

		void updateStates(sf::Event event);
		void drawStates(Window *window);

		//void StateManager::reindexState(std::string name, int newIndex);
		//void StateManager::reindexState(int oldIndex, int newIndex);
	};
}