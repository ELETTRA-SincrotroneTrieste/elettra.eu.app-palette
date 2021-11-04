#ifndef CUEPALETTE_H
#define CUEPALETTE_H

#include <QPalette>
#include <QApplication>

// from QTango qtcontrols elettracolors.h
//
#define BOOSTERCOLOR	QColor(205,230,255)
#define ELETTRACOLOR	QColor(220,255,222)
#define FERMICOLOR QColor(224,230,230)

#define KGRAYFERMIHIGHLIGHT 		QColor(154,160,160)
#define KGRAYFERMIALTERNATEBASE 	QColor(184,190,190)
#define KBOOSTERHIGHLIGHT		QColor(91,157,222)
#define KBOOSTERALTERNATEBASE		QColor(175,215,255)
#define KELETTRAHIGHLIGHT 		QColor(145,218,150)
#define KELETTRAALTERNATEBASE		QColor(180,205,182)

class CuEPalettePrivate {
public:
    CuEPalettePrivate(const QString& nam) : name(nam) {}
    QString name;
};

/*! \mainpage
 *
 * A helper class that builds a specific palette for a QApplication
 * belonging to *either* the "booster" *or* the "elettra" domain.
 *
 * When the object is constructed with the *booster* keyword, the *get* method
 * will return a *blue based* palette.
 *
 * When the object is constructed with the *elettra* keyword, the *get* method
 * will return a *green based* palette.
 *
 * Any other name used in the CuEPalette constructor will be ignored and *get*
 * will return the QApplication default palette (i.e. qApp->palette() ).
 *
 * The *name* method shall return the string used during the class construction.
 *
 * \note
 * The colors have been taken from those defined in the QTango *qtcontrols*
 * module (elettracolors.h)
 */
class CuEPalette
{
public:
    /*! build a new object with the given name
     *
     *  @param name either "booster" or "elettra" Any other value will
     *  map to the default QApplication palette
     */
    CuEPalette(const QString& name);

    virtual ~CuEPalette();

    /*!
     * \brief get returns a QPalette with the colors associated to the name
     *        used in the object constructor
     * \return a QPalette
     */
    QPalette get() const;

    /*! \brief returns the name used in the constructor
     */
    const QString name() const;

private:
    CuEPalettePrivate *d;
};

CuEPalette::CuEPalette(const QString& name) {
    d = new CuEPalettePrivate(name);
}

CuEPalette::~CuEPalette() {
    delete d;
}

QPalette CuEPalette::get() const {
    QPalette p;
    if(d->name == "booster") {
        p = QPalette(BOOSTERCOLOR);
        p.setColor(QPalette::Highlight, KBOOSTERHIGHLIGHT );
        p.setColor(QPalette::AlternateBase, KBOOSTERALTERNATEBASE );
    }
    else if(d->name == "elettra") {
        p = QPalette(ELETTRACOLOR);
        p.setColor(QPalette::Highlight, KELETTRAHIGHLIGHT );
        p.setColor(QPalette::AlternateBase, KELETTRAALTERNATEBASE);
    }
    else
        return qApp->palette();
    return p;
}

const QString CuEPalette::name() const {
    return d->name;
}

#endif // CUEPALETTE_H
