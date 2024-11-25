QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aceros.cpp \
    alquiydepre.cpp \
    azoteas.cpp \
    campotecyadmin.cpp \
    canceleria.cpp \
    capyprom.cpp \
    cargosdecampo.cpp \
    cargostecyadmin.cpp \
    carpinteria.cpp \
    cdfinales.cpp \
    cdfpreliminares.cpp \
    cdmanodeobra.cpp \
    cdpreliminares.cpp \
    cimbras.cpp \
    cimentaciones.cpp \
    ciobra.cpp \
    cioperacion.cpp \
    colocaciones.cpp \
    comyfletes.cpp \
    concretos.cpp \
    construcprov.cpp \
    consumosvarios.cpp \
    costos.cpp \
    costosdirectos.cpp \
    costosindirectos.cpp \
    drenajes.cpp \
    edit.cpp \
    editcsvview.cpp \
    equipos.cpp \
    estructuras.cpp \
    fianzas.cpp \
    financiamiento.cpp \
    herreria.cpp \
    imprevistos.cpp \
    impuestosr.cpp \
    instalacionese.cpp \
    lechadas.cpp \
    main.cpp \
    mainwindow.cpp \
    matdecons.cpp \
    morteros.cpp \
    murosdalascastillos.cpp \
    obligyseg.cpp \
    paisajismo.cpp \
    pastas.cpp \
    pisos.cpp \
    recubrimientos.cpp \
    subcontratos.cpp \
    trasladosper.cpp \
    utilidad.cpp

HEADERS += \
    aceros.h \
    alquiydepre.h \
    azoteas.h \
    campotecyadmin.h \
    canceleria.h \
    capyprom.h \
    cargosdecampo.h \
    cargostecyadmin.h \
    carpinteria.h \
    cdfinales.h \
    cdfpreliminares.h \
    cdmanodeobra.h \
    cdpreliminares.h \
    cimbras.h \
    cimentaciones.h \
    ciobra.h \
    cioperacion.h \
    colocaciones.h \
    comyfletes.h \
    concretos.h \
    construcprov.h \
    consumosvarios.h \
    costos.h \
    costosdirectos.h \
    costosindirectos.h \
    drenajes.h \
    edit.h \
    editcsvview.h \
    equipos.h \
    estructuras.h \
    fianzas.h \
    financiamiento.h \
    herreria.h \
    imprevistos.h \
    impuestosr.h \
    instalacionese.h \
    lechadas.h \
    mainwindow.h \
    matdecons.h \
    morteros.h \
    murosdalascastillos.h \
    obligyseg.h \
    paisajismo.h \
    pastas.h \
    pisos.h \
    recubrimientos.h \
    subcontratos.h \
    trasladosper.h \
    utilidad.h

FORMS += \
    aceros.ui \
    alquiydepre.ui \
    azoteas.ui \
    campotecyadmin.ui \
    canceleria.ui \
    capyprom.ui \
    cargosdecampo.ui \
    cargostecyadmin.ui \
    carpinteria.ui \
    cdfinales.ui \
    cdfpreliminares.ui \
    cdmanodeobra.ui \
    cdpreliminares.ui \
    cimbras.ui \
    cimentaciones.ui \
    ciobra.ui \
    cioperacion.ui \
    colocaciones.ui \
    comyfletes.ui \
    concretos.ui \
    construcprov.ui \
    consumosvarios.ui \
    costos.ui \
    costosdirectos.ui \
    costosindirectos.ui \
    drenajes.ui \
    edit.ui \
    editcsvview.ui \
    equipos.ui \
    estructuras.ui \
    fianzas.ui \
    financiamiento.ui \
    herreria.ui \
    imprevistos.ui \
    impuestosr.ui \
    instalacionese.ui \
    lechadas.ui \
    mainwindow.ui \
    matdecons.ui \
    morteros.ui \
    murosdalascastillos.ui \
    obligyseg.ui \
    paisajismo.ui \
    pastas.ui \
    pisos.ui \
    recubrimientos.ui \
    subcontratos.ui \
    trasladosper.ui \
    utilidad.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
