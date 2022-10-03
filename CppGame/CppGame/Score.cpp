#include "Score.h"
#include "Consts.h"

void observe(Score* score, const int& value)
{
	score->setText(("Score : " + std::to_string(value)).c_str());
}


Score::Score(QGraphicsScene* scene, Values* values)
{
	scene->addItem(this);
	setX(scene->sceneRect().width() / 2 -
		Consts::BOARD_ITEM_SIZE * Consts::BOARD_LENGTH / 2 + 10);
	setY(scene->sceneRect().height() / 2 +
		Consts::BOARD_ITEM_SIZE * Consts::BOARD_LENGTH / 2);
	setScale(3);

	values->score.observer([this](const int& value)
		{
			observe(this, value);
		});
}