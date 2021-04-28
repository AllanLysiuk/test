#include "creator_of_map.h"
void printMap(const std::string &file_name,QGraphicsScene *scene){
   std:: ifstream in(file_name);
    if (in.is_open())
    {

        //int x = 0;
        int row = 0; // row
        int col = 0; //column
        char  tmp = ' ';
        while (!in.eof())// пробегаем пока не встретим конец файла eof
        {
            in >> tmp;
            if (tmp == '.') {
                ++row;
                col = 0;
            } else {
                ++col;
            }
            if (tmp == '1') {
                Wall* wall = new Wall(scene);
                scene->addItem(wall);
                wall->setPos(col * 50-750, row * 50-380);
            }
        }
        in.close();
    }
}
