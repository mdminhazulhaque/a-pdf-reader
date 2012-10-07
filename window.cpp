/*****************************************************************************
a-pdf-reader, A poppler based pdf reader written in Qt4
Copyright (C) 2012 MD: Minhazul Haque;
mdminhazulhaque@gmail.com.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*****************************************************************************/

#include "window.h"
#include "ui_window.h"

Window::Window(QWidget *parent) : QMainWindow(parent), ui(new Ui::Window)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    connect(ui->exit, SIGNAL(clicked()), qApp, SLOT(quit()));
    ui->statusBar->showMessage("Ready to use...");
}

Window::~Window()
{
    delete ui;
}

void Window::on_browse_clicked()
{
    ui->filepath->setText(QFileDialog::getOpenFileName(this, "Select a PDF file", QDir::homePath(), tr("PDF File, (*.pdf)")));
    on_load_clicked();
    return;
}

void Window::on_load_clicked()
{
    if(!QFile::exists(ui->filepath->text()))
    {
        QMessageBox::warning(this, "Error!", "Please select a valid PDF file!");
        return;
    }

    pageNo = 0;
    document = Poppler::Document::load(ui->filepath->text());
    document->setRenderHint(Poppler::Document::Antialiasing, true);
    document->setRenderHint(Poppler::Document::TextAntialiasing, true);
    reload();
}
void Window::reload()
{
    scene->clear();
    pdfPage = document->page(pageNo);
    scene->addPixmap(QPixmap::fromImage(pdfPage->renderToImage(96, 96, 0, 0, pdfPage->pageSize().width(),pdfPage->pageSize().height())));

    ui->pdfviewport->setScene(scene);
    ui->pdfviewport->repaint();
    showStatusBarMsg();
}

void Window::showStatusBarMsg()
{
    ui->statusBar->showMessage(QString("Showing page %1 of %2 pages").arg(pageNo+1).arg(document->numPages()));
}

void Window::on_previous_clicked()
{
    if(pageNo==0)
        QMessageBox::warning(this, "Error!", "Reached beginning of file!");
    else
    {
        --pageNo;
        reload();
    }
}

void Window::on_next_clicked()
{
    if(pageNo==document->numPages()-1)
        QMessageBox::warning(this, "Error!", "Reached end of file!");
    else
    {
        ++pageNo;
        reload();
    }
}
