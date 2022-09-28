// SPDX-FileCopyrightText: 2021 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
// SPDX-FileContributor: Andrew Hayzen <andrew.hayzen@kdab.com>
// SPDX-FileContributor: Gerhard de Clercq <gerhard.declercq@kdab.com>
//
// SPDX-License-Identifier: MIT OR Apache-2.0

// ANCHOR: book_main_qml
import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Window 2.12

// ANCHOR: book_qml_import
import com.kdab.cxx_qt.demo 1.0
// ANCHOR_END: book_qml_import

Window {
    height: 480
    title: qsTr("Hello World")
    visible: true
    width: 640
    color: "white"

    MyObject {
        id: myObject
        number: 1
        string: "My String with my number: " + myObject.number
    }

    Column {
        anchors.fill: parent
        anchors.margins: 10
        spacing: 10

        Label {
            text: "Number: " + myObject.number
            color: "black"
        }

        Label {
            text: "String: " + myObject.string
            color: "black"
        }

        Button {
            text: "Increment Number"

            onClicked: myObject.incrementNumber()

            palette.button: "black"
            palette.buttonText: "white"
        }

        Button {
            text: "Say Hi!"

            property color red: "red"

            onClicked: myObject.sayHi(myObject.string, myObject.number, red)

            palette.button: "black"
            palette.buttonText: "white"
        }
    }
}
// ANCHOR_END: book_main_qml
