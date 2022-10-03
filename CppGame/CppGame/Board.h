#pragma once


#include <vector>
#include <random>
#include <set>
#include <QtWidgets/QGraphicsPixmapItem> 
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsRectItem>
#include <QtWidgets/QGraphicsTextItem>

#include "item.h"
#include "Value.h"

using MatchPair = std::pair<int, int>;
using MatchSet = std::set<MatchPair>;

class Board : public Item::EventListener
{   


private:
	QGraphicsScene *_scene;
	Values* _values;
	QGraphicsRectItem _root;
	
	std::vector<std::vector<Item*>> _items;
	std::random_device _device; //랜덤함수 device 라는 랜덤시드가 밑에 시드랑 맞으면 파일 생성.
	std::mt19937 _gen;

	int _moveCount;
	//int _score;

public:
	Board(QGraphicsScene* scene, Values* values);    	//보드를 신에 추가하려면 scene을 알고있어야하니깐 라이브러리 추가
	~Board();
	void addItem(int row, int column);
	void removeItem(int row, int column);
	void moveItem(int fromRow, int fromColumn, int toRow, int toColumn);
	void moveItem(Item* item, int toRow, int toColumn);
	void  exchangeItems(int row0, int column0, int row1, int column1, bool canRevert);
	bool refresh();
	MatchSet matchedItems() const;  //멀티셋은 중복허용가능 벡터도 하지만 set은 중복이 안되기에 확신가능.
	MatchSet matchedItems(int row, int column) const;
	MatchSet matchedItemsHorizontal(int row, int column) const;
	MatchSet matchedItemsVertical(int row, int column) const;

	virtual void itemDragEvent(Item* item, Item::Direction dir) override;
	virtual void itemMoveFinished(Item* item0, Item* item1, bool canRevert) override;
};

/*
   _items
   1 2 3  == _items[0], row0
   4 5 6  == _items[1]. row1
   7 8 9  == _items[2]. row2
    
	_items [0][0] -> 1
	_items [0][2] -> 3
*/