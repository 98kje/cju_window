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
	std::random_device _device; //�����Լ� device ��� �����õ尡 �ؿ� �õ�� ������ ���� ����.
	std::mt19937 _gen;

	int _moveCount;
	//int _score;

public:
	Board(QGraphicsScene* scene, Values* values);    	//���带 �ſ� �߰��Ϸ��� scene�� �˰��־���ϴϱ� ���̺귯�� �߰�
	~Board();
	void addItem(int row, int column);
	void removeItem(int row, int column);
	void moveItem(int fromRow, int fromColumn, int toRow, int toColumn);
	void moveItem(Item* item, int toRow, int toColumn);
	void  exchangeItems(int row0, int column0, int row1, int column1, bool canRevert);
	bool refresh();
	MatchSet matchedItems() const;  //��Ƽ���� �ߺ���밡�� ���͵� ������ set�� �ߺ��� �ȵǱ⿡ Ȯ�Ű���.
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