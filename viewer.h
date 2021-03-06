// просмотр и редактирование произвольных файлов 

#ifndef __VIEWER_H
#define __VIEWER_H
#include <stdint.h>
#include <QtWidgets>
#include "cpfiledir.h"

//***********************************************************
//* Класс главного окна 
//***********************************************************
class viewer  : public QMainWindow {

Q_OBJECT

cpfiledir* fileptr;
uint8_t* sdata;
uint32_t* slen;

bool readonly;
uint8_t* pdata;

QString findtext=""; // текст для поискового запроса

QWidget* central;
QSettings* config;
QVBoxLayout* vlm;
QTextEdit* ted;

QString textdata;

// Главное меню
QMenuBar* menubar;
QMenu* menu_file;
QMenu* menu_edit;
QMenu* menu_view;

// тулбар
QToolBar* toolbar;

bool datachanged=false;

public:
  
viewer(uint8_t* data, uint32_t* len, uint8_t rmode, char* name, cpfiledir* dfile=0);  
~viewer();

public slots:
void setChanged();
void save_all();
void find();
void findnext();
void fontselector();

signals:
void changed(); 
};

#endif
