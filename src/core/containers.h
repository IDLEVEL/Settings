#pragma once
#include <Arduino.h>

#include "builder.h"
#include "codes.h"

namespace sets {

// контейнер гостевого доступа
class GuestAccess {
   public:
    GuestAccess(Builder& b) : b(b) {
        b.beginGuest();
    }
    ~GuestAccess() {
        b.endGuest();
    }

   private:
    Builder& b;
};

class BasicContainer {
   public:
    BasicContainer(Code type, size_t id, Builder& b, Text title = Text(), DivType divtype = DivType::Default) : b(b) {
        b._beginContainer(id, type, title, divtype);
    }
    ~BasicContainer() {
        b._endContainer();
    }

   private:
    Builder& b;
};

// контейнер группы виджетов
class Group : public BasicContainer {
   public:
    Group(Builder& b, Text title = Text(), size_t id = _NO_ID) : BasicContainer(Code::group, id, b, title) {}
};

// контейнер вложенного меню
class Menu : public BasicContainer {
   public:
    Menu(Builder& b, Text title, size_t id = _NO_ID) : BasicContainer(Code::menu, id, b, title) {}
};

// контейнер кнопок
class Buttons : public BasicContainer {
   public:
    Buttons(Builder& b, size_t id = _NO_ID) : BasicContainer(Code::buttons, id, b) {}
};

// горизонтальный контейнер [DivType::Line | DivType::Block]
class Row : public BasicContainer {
   public:
    Row(Builder& b, Text title = Text(), DivType divtype = DivType::Default, size_t id = _NO_ID) : BasicContainer(Code::row, id, b, title, divtype) {}
};

}  // namespace sets