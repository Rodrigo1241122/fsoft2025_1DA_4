// Hotel.h - Tiago

#ifndef HEADERS_MODEL_HOTEL_H_
#define HEADERS_MODEL_HOTEL_H_

#include <string>
#include <vector>
#include "RoomContainer.h"
#include "ServiceContainer.h"
#include "ActivityContainer.h"
#include "CommentContainer.h"
#include "ReservationContainer.h"

class Room;

class Hotel {
private:
    int id;
    std::string name;
    std::string location;
    int stars;
    std::string region;

    RoomContainer rooms;
    ServiceContainer services;
    ActivityContainer activities;
    ReservationContainer reservations;
    CommentContainer comments;

    void setDataForConsistency();

public:
    // Construtores
    Hotel(); // Por omissão
    Hotel(int id, const std::string& name, const std::string& location, int stars); // Para seed
    Hotel(const std::string& name, const std::string& location, int stars); // Sem ID
    Hotel(int id, const std::string& name, int stars, const std::string& region,
          const std::vector<Room>& rooms,
          const std::vector<Service>& services,
          const std::vector<Activity>& activities);
    Hotel(const Hotel& obj); // Cópia
    ~Hotel(); // Destrutor

    // Getters e setters básicos
    int getId() const;
    void setId(int id);
    const std::string& getName() const;
    void setName(const std::string& name);
    const std::string& getLocation() const;
    void setLocation(const std::string& location);
    int getStars() const;
    void setStars(int stars);
    std::string getRegion() const;
    const std::vector<Activity>& getActivities() const;

    // Rooms
    void adicionarQuarto(const Room& quarto);
    const RoomContainer& getRoomContainer() const;

    // Containers
    const ServiceContainer& getServiceContainer() const;
    ServiceContainer& getServiceContainer();
    ActivityContainer& getActivityContainer();
    const ActivityContainer& getActivityContainer() const;
    ReservationContainer& getReservationContainer();
    CommentContainer& getCommentContainer();

    // Contagem de quartos
    int getRoomCount() const {
        return rooms.size();
    }
};

#endif /* HEADERS_MODEL_HOTEL_H_ */
