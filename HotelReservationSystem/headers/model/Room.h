#ifndef HEADERS_MODEL_ROOM_H_
#define HEADERS_MODEL_ROOM_H_

#include "data/RoomType.h"
#include <memory>  // Certifique-se de incluir para o uso de std::shared_ptr

class Hotel;
class Room {
private:
    int id;
    int number;
    double pricePerNight;
    RoomType type;
    bool available;
    std::shared_ptr<Hotel> hotel;  // Ponteiro para o hotel associado

public:
    Room();  // Construtor padrão
    Room(int id, int number, double pricePerNight, RoomType type, std::shared_ptr<Hotel> hotel);  // Construtor com hotel
    Room(const Room& other);  // Construtor de cópia

    int getId() const;
    void setId(int id);

    int getNumber() const;
    void setNumber(int number);

    double getPricePerNight() const;
    void setPricePerNight(double price);

    RoomType getType() const;
    void setType(RoomType type);

    bool isAvailable() const;
    void setAvailable(bool value);

    bool operator==(const Room& other) const;
    
    // Retorna o hotel associado ao quarto
    std::shared_ptr<Hotel> getHotel() const;
};

#endif /* HEADERS_MODEL_ROOM_H_ */
