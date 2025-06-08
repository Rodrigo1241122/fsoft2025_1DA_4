#ifndef ROOM_TYPE_H
#define ROOM_TYPE_H

#include <string>

enum class RoomType {
    STANDARD,
    DOUBLE,
    DELUXE
};

inline const std::string toString(RoomType type) {
    switch (type) {
        case RoomType::STANDARD: return "Standard";
        case RoomType::DOUBLE: return "Double";
        case RoomType::DELUXE: return "Deluxe";
        default: return "Unknown";
    }
}

#endif // ROOM_TYPE_H
