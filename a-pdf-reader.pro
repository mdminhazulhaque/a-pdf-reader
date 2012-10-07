##############################################################
#
#     a-pdf-reader, A poppler based pdf reader written in Qt4
#    Copyright (C) 2012 MD: Minhazul Haque;
#    mdminhazulhaque@gmail.com.
#
#    This program is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
##############################################################

QT       += core gui

TARGET = a-pdf-reader

TEMPLATE = app

LIBS += -lpoppler-qt4

SOURCES += main.cpp\
        window.cpp

HEADERS  += window.h

FORMS    += window.ui

RESOURCES += \
    icons.qrc
