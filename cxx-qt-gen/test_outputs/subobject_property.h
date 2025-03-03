#pragma once

#include <mutex>

#include "rust/cxx_qt.h"

#include "cxx-qt-gen/include/sub_object.h"

namespace cxx_qt::my_object {

class RustObj;

class MyObject : public CxxQObject
{
  Q_OBJECT
  Q_PROPERTY(
    cxx_qt::sub_object::CppObj* obj READ getObj WRITE setObj NOTIFY objChanged)

public:
  explicit MyObject(QObject* parent = nullptr);
  ~MyObject();

  cxx_qt::sub_object::CppObj* getObj() const;
  std::unique_ptr<cxx_qt::sub_object::CppObj> takeObj();
  void giveObj(std::unique_ptr<cxx_qt::sub_object::CppObj> value);

public Q_SLOTS:
  void setObj(cxx_qt::sub_object::CppObj* value);

Q_SIGNALS:
  void objChanged();

private:
  rust::Box<RustObj> m_rustObj;
  std::mutex m_rustObjMutex;
  bool m_initialised = false;

  cxx_qt::sub_object::CppObj* m_obj = nullptr;
  std::unique_ptr<cxx_qt::sub_object::CppObj> m_ownedObj;
};

typedef MyObject CppObj;

std::unique_ptr<CppObj>
newCppObject();

} // namespace cxx_qt::my_object

Q_DECLARE_METATYPE(cxx_qt::my_object::CppObj*)
