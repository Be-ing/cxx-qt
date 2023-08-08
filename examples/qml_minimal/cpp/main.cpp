// clang-format off
// SPDX-FileCopyrightText: 2021 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
// clang-format on
// SPDX-FileContributor: Andrew Hayzen <andrew.hayzen@kdab.com>
// SPDX-FileContributor: Gerhard de Clercq <gerhard.declercq@kdab.com>
//
// SPDX-License-Identifier: MIT OR Apache-2.0

// ANCHOR: book_main_cpp
#include <QtGui/QGuiApplication>
#include <QtQml/QQmlApplicationEngine>

#include <QtQml/qqmlprivate.h>
namespace QmlCacheGeneratedCode {
namespace _qt_qml_com_kdab_cxx_qt_demo__0x2e__0x2e__qml_main_qml {
  extern const QQmlPrivate::TypedFunction aotBuiltFunctions[];
}
}

int
main(int argc, char* argv[])
{
  const auto &aot = QmlCacheGeneratedCode::_qt_qml_com_kdab_cxx_qt_demo__0x2e__0x2e__qml_main_qml::aotBuiltFunctions[0];
  Q_ASSERT(aot.functionPtr != nullptr);

  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;

  // ANCHOR: book_qml_url
  const QUrl url(
    QStringLiteral("qrc:/qt/qml/com/kdab/cxx_qt/demo/qml/main.qml"));
  // ANCHOR_END: book_qml_url
  QObject::connect(
    &engine,
    &QQmlApplicationEngine::objectCreated,
    &app,
    [url](QObject* obj, const QUrl& objUrl) {
      if (!obj && url == objUrl)
        QCoreApplication::exit(-1);
    },
    Qt::QueuedConnection);

  engine.load(url);

  return app.exec();
}
// ANCHOR_END: book_main_cpp
