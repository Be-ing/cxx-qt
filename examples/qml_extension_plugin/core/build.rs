// SPDX-FileCopyrightText: 2021 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
// SPDX-FileContributor: Andrew Hayzen <andrew.hayzen@kdab.com>
// SPDX-FileContributor: Gerhard de Clercq <gerhard.declercq@kdab.com>
//
// SPDX-License-Identifier: MIT OR Apache-2.0

// ANCHOR: book_build_rs
use clang_format::ClangFormatStyle;
use cxx_qt_build::CxxQtBuilder;

fn main() {
    CxxQtBuilder::new()
        .qqmlextensionplugin(
            "com.kdab.cxx_qt.demo", // QML import name
            "core_qmlplugin",       // C++ library target name
        )
        .cpp_format(ClangFormatStyle::Mozilla)
        .file("src/lib.rs")
        .build();
}
// ANCHOR_END: book_build_rs
