#include "template.h"
#include "ui_template.h"

Template::Template(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Template)
{
    ui->setupUi(this);
}

Template::~Template()
{
    delete ui;
}
