#include "cxx-qt-gen/include/my_object.h"
#include "cxx-qt-gen/src/my_object.rs.h"

namespace cxx_qt::my_object {

MyObject::MyObject(QObject* parent)
  : CxxQObject(parent)
  , m_rustObj(createRs())
{
  initialiseCpp(*this);
  m_initialised = true;
}

MyObject::~MyObject() = default;

void
MyObject::sayHi(const QString& string, qint32 number)
{
  const std::lock_guard<std::mutex> guard(m_rustObjMutex);
  m_rustObj->sayHi(string, number);
}

void
MyObject::sayBye()
{
  const std::lock_guard<std::mutex> guard(m_rustObjMutex);
  m_rustObj->sayBye();
}

std::unique_ptr<CppObj>
newCppObject()
{
  return std::make_unique<CppObj>();
}

} // namespace cxx_qt::my_object
