#pragma once
#include<vector>


namespace sp{
	class Block {
	protected:
		int id;

	public:
		Block();

		int getID();
		void setID(int id);
	};
}