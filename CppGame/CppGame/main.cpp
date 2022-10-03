#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/qgraphicsview.h> //���̰�����
#include <QtWidgets/qdesktopwidget.h> //ȭ�� ���.

#include "Board.h"
#include "Score.h"
#include "Value.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QRect geometry = QApplication::desktop()->geometry(); //��ǻ�� ȭ������ ������
    geometry.setY(0);   //geometry Ȯ���غ��� y���� -1080�� �̰� 0���� �����ָ� ���� �� ������ �簢�� ����(100,100)����

    QGraphicsScene scene;   //�׷����� ���� ����.
    scene.setSceneRect(geometry);

    Values values; 

    Board board(&scene, &values);
    Score score(&scene, &values);

 
    QGraphicsView view(&scene);
    // view.show(); //�������� ���ִ� �Լ�   ����� �ȶ߸� ctrl shift esc �� CppGame ���α׷� ���� Ȥ�� ���ҽ�����Ϳ��� �������������  �� ���´� �ڱ׸��� ȭ��
    view.showFullScreen();  //��üȭ������ ������. ������ Alt F4

    return a.exec();
}
