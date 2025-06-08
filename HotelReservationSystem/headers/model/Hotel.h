#ifndef HEADERS_MODEL_HOTEL_H_
#define HEADERS_MODEL_HOTEL_H_

#include <string>
#include <vector>
#include "RoomContainer.h"
#include "ServiceContainer.h"
#include "ActivityContainer.h"
#include "CommentContainer.h"
#include "ReservationContainer.h"  // Inclusão do cabeçalho ReservationContainer

class Room;

using namespace std;

class Hotel {
private:
    string name;
    string location;
    int stars;
    string region;

    RoomContainer rooms;
    ServiceContainer services;
    ActivityContainer activities;
    ReservationContainer reservations;
    CommentContainer comments;
    ActivityContainer activityContainer;

    void setDataForConsistency();

public:
    Hotel(); // construtor por omissão

    // construtor usado nos seeds (com location e region = location)
    Hotel(const string& name, const string& location, int stars);

    // construtor completo usado para instanciar com dados iniciais
    Hotel(const string& name, int stars, const string& region,
          const vector<Room>& rooms,
          const vector<Service>& services,
          const vector<Activity>& activities);

    Hotel(const Hotel& obj); // cópia
    ~Hotel(); // destrutor

    // Getters e setters
    const string& getName() const;
    void setName(const string& name);
    const string& getLocation() const;
    void setLocation(const string& location);
    int getStars() const;
    void setStars(int stars);
    string getRegion() const;

    // Rooms
    void adicionarQuarto(const Room& quarto);
    const RoomContainer& getRoomContainer() const;

    // Serviços, atividades, reservas, comentários
    const ServiceContainer& getServiceContainer() const;
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
