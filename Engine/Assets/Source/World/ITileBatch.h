#pragma once


namespace sp {

	class ITile;
	
	class ITileBatch {
	public:
		virtual ITile* createTile(int id) = 0;
	};
}