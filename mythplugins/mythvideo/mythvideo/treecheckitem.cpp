#include <qapplication.h>
#include <qstring.h>
#include <qpixmap.h>
#include <qimage.h>
#include <iostream>
using namespace std;

#include "treecheckitem.h"

#include <mythtv/mythcontext.h>

QPixmap *TreeCheckItem::artist = NULL;
QPixmap *TreeCheckItem::album = NULL;
QPixmap *TreeCheckItem::track = NULL;
QPixmap *TreeCheckItem::catalog = NULL;
QPixmap *TreeCheckItem::cd = NULL;
bool TreeCheckItem::pixmapsSet = false;

TreeCheckItem::TreeCheckItem(MythContext *context, QListView *parent, 
                             QString &ltext, const QString &llevel, 
                             Metadata *mdata)
  : QListViewItem(parent, ltext.prepend(" "))
{
    level = llevel;
    metadata = mdata;
    m_context = context;

}



void TreeCheckItem::paintCell(QPainter* p, const QColorGroup& cg,
         int column, int width, int align)
{   
	    QColorGroup newCg = cg;
	    //	    cout << "Genre:" << metadata->Genre().ascii() << endl;
	    if(metadata->Genre() == "dir")
	      {
//	   	    cout << "Genre:" << metadata->Genre().ascii() << endl;
		
		newCg.setColor(QColorGroup::Foreground, "Yellow");
		newCg.setColor(QColorGroup::Text, "Yellow");
		newCg.setColor(QColorGroup::HighlightedText, "Yellow");
	      }
	    QListViewItem::paintCell(p,newCg,column,width,align);
}

TreeCheckItem::TreeCheckItem(MythContext *context, TreeCheckItem *parent, 
                             QString &ltext, const QString &llevel, 
                             Metadata *mdata)
             : QListViewItem(parent, ltext.prepend(" "))
{
    level = llevel;
    metadata = mdata;
    m_context = context;

}

