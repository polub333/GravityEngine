#include "bodylistwindow.h"
#include "ui_bodylistwindow.h"

BodyListWindow::BodyListWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BodyListWindow)
{
    ui->setupUi(this);
    connect(ui->CloseButton, SIGNAL(clicked()), this, SLOT(hide()));
}

BodyListWindow::BodyListWindow(Engine* _engine, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BodyListWindow),
    engine(_engine)
{
    ui->setupUi(this);
    connect(ui->CloseButton, SIGNAL(clicked()), this, SLOT(hide()));
}

BodyListWindow::~BodyListWindow()
{
    delete ui;
}

void BodyListWindow::open()
{
    size_t size = engine->bodies.size();
    clearLayout(ui->MainLayout);

    names.resize(size);
    selectButtons.resize(size);
    deleteButtons.resize(size);
    layouts.resize(size);

    for(int i=0;i<size;++i){
        names[i] = new QLabel;
        selectButtons[i] = new QPushButton;
        deleteButtons[i] = new QPushButton;
        layouts[i] = new QHBoxLayout;
        names[i]->setText(engine->bodies[i]->getName());
        if(engine->bodies[i]->getSelected()){
            selectButtons[i]->setText("Unselect");
        }
        else{
            selectButtons[i]->setText("Select");
        }
        deleteButtons[i]->setText("Delete");

        connect(selectButtons[i], &QPushButton::clicked, this, [this, i](){this->changeSelected(i);});
        connect(deleteButtons[i], &QPushButton::clicked, this, [this, i](){this->deleteBody(i);});

        layouts[i]->addWidget(names[i]);
        layouts[i]->addWidget(selectButtons[i]);
        layouts[i]->addWidget(deleteButtons[i]);
        ui->MainLayout->addLayout(layouts[i]);
    }
    show();
}

void BodyListWindow::clearLayout(QLayout* mainLayout)
{
    QLayoutItem* item;
    QLayout* layout;
    QWidget* widget;
    while(item = mainLayout->takeAt(0)){
        if(layout = item->layout()){
            clearLayout(layout);
            delete layout;
        }
        else if(widget = item->widget()){
            delete widget;
        }
    }

    names.clear();
    selectButtons.clear();
    deleteButtons.clear();
    layouts.clear();
}

void BodyListWindow::changeSelected(int index)
{
    bool newSelected = true;
    if(engine->bodies[index]->getSelected()){
        newSelected = false;
    }
    for(int i=0;i<engine->bodies.size();++i){
        if(engine->bodies[i]->getSelected()){
            engine->bodies[i]->setSelected(false);
        }
    }
    engine->bodies[index]->setSelected(newSelected);
    hide();
    open();
}

void BodyListWindow::deleteBody(int index)
{
    delete engine->bodies[index];
    engine->bodies.erase(engine->bodies.begin() + index);
    hide();
    open();
}
