<!--
SPDX-FileCopyrightText: 2021 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
SPDX-FileContributor: Andrew Hayzen <andrew.hayzen@kdab.com>

SPDX-License-Identifier: MIT OR Apache-2.0
-->

# Types

## Primitive Trivial Types

These types can be used for properties, parameters or return types in invokables, and parameters in signals without any conversion.

They appear as their normal types on both the C++ and Rust sides of the bridge.

| Rust Type | C++ Type |
|-----------|----------|
| bool      | bool     |
| f32       | float    |
| f64       | double   |
| i8        | qint8    |
| i16       | qint16   |
| i32       | qint32   |
| u8        | quint8   |
| u16       | quint16  |
| u32       | quint32  |

TODO: Note that u64 / quint64 is not supported currently ( [https://github.com/KDAB/cxx-qt/issues/36](https://github.com/KDAB/cxx-qt/issues/36) ).

## Custom Types

These types are custom and require special treatment when traversing the bridge, to assist with traversing the bridge we have provided helper types in the cxx_qt_lib crate.

Within these custom types there are two kinds to consider

  * Trivial
  * Opaque

### Custom Trivial Types

Custom trivial types, like primitive trival types, can be used for properties, parameters or return types in invokables, and parameters in signals without any conversion.

On the rust side they appear as the cxx_qt_lib helper type.

Note that when they are used as a parameter type in invokables they should be passed as a reference, eg `pointf: &QPointF`, and when they are a property or return type they should be a value, eg `QPointF`.

| Rust Type | C++ Type |
|-----------|----------|
| cxx_qt_lib::QDate | QDate |
| cxx_qt_lib::QPoint | QPoint |
| cxx_qt_lib::QPointF | QPointF |
| cxx_qt_lib::QRect | QRect |
| cxx_qt_lib::QRectF | QRectF |
| cxx_qt_lib::QTime | QTime |

### Custom Opaque Types

Custom opaque types require specific types to be used when being used as an input from C++ to Rust and an output from Rust to C++.

For properties and signals the Rust Output column below should be used.

For parameter types in invokables a reference as in the Rust Input column below should be used.

For return types from invokables the Rust Output column should be used.

| Rust Input | Rust Output | C++ Type |
|------------|-------------|----------|
| &cxx_qt_lib::QColor | cxx_qt_lib::Color | QColor |
| &cxx_qt_lib::QDateTime | cxx_qt_lib::DateTime | QDateTime |
| &cxx_qt_lib::QString | String or str | QString |
| &cxx_qt_lib::QUrl | cxx_qt_lib::Url | QUrl |
| &cxx_qt_lib::QVariant | cxx_qt_lib::Variant | QVariant |

Note that in the future custom opaque types will be transparent so there won't be a difference between the input and output ( [https://github.com/KDAB/cxx-qt/issues/9](https://github.com/KDAB/cxx-qt/issues/9) ).

An example of a QVariant as a parameter, return type, and property is shown below.

```rust,ignore,noplayground
{{#include ../../../examples/qml_features/src/types.rs:book_macro_code}}
```

## Future possible types

  * Enums
  * Lists
