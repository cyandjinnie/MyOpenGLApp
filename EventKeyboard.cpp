#include "EventKeyboard.h"

EventKeyboard::EventKeyboard(KeyCodes _code, Type _type) : type(_type), keyCode(_code), Event::Event()
{
}

EventKeyboard::EventKeyboard() : type(UNKNOWN), keyCode(KEY_UNKNOWN), Event::Event()
{
}

