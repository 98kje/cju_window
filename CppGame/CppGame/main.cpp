#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/qgraphicsview.h> //보이게해줌
#include <QtWidgets/qdesktopwidget.h> //화면 상단.

#include "Board.h"
#include "Score.h"
#include "Value.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QRect geometry = QApplication::desktop()->geometry(); //컴퓨터 화면으로 맞춰줌
    geometry.setY(0);   //geometry 확인해보면 y값이 -1080임 이걸 0으로 맞춰주면 왼쪽 젤 끝으로 사각형 생성(100,100)으로

    QGraphicsScene scene;   //그래픽의 신을 만듬.
    scene.setSceneRect(geometry);

    Values values; 

    Board board(&scene, &values);
    Score score(&scene, &values);

 
    QGraphicsView view(&scene);
    // view.show(); //보여지게 해주는 함수   실행시 안뜨면 ctrl shift esc 로 CppGame 프로그램 종료 혹은 리소스모니터에서 강제종료시켜줌  이 상태는 자그만한 화면
    view.showFullScreen();  //전체화면으로 보여줌. 끌때는 Alt F4

    return a.exec();
}
