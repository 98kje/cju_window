#pragma once
#include <string>
#include <QtWidgets/QGraphicsPixmapItem>


class Item  : public QGraphicsPixmapItem, public QObject
{
	class EventListener;
public:
	Item(EventListener* listener, const std::string& path, int row, int column, QGraphicsItem* parent);
	std::string path() const;
	int row() const;
	int column() const;

	void setRow(int row);
	void setColumn(int column);

	void moveTo(double toX, double toY);
	void moveTo(Item* other, bool canRevert);

protected:
	virtual void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
	virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override; //마우스를 눌렀을때 좌표기록 ,놓을때 여기서 놓았다.

private:
	const std::string _path;
	int _row;
	int _column;
	EventListener* _listener;

	QPointF _pressPos;

public:
	enum class Direction
	{
		Left,
		Right,
		Up,
		Down,
	};

	class EventListener
	{
	public:
		virtual void itemDragEvent(Item* item, Item::Direction dir) = 0;
		virtual void itemMoveFinished(Item* item0, Item* item1, bool canRevert) = 0;
	};
};


