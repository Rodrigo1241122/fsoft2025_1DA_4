// seed.cpp - Tiago

#include <vector>
#include "model/Hotel.h"
#include "model/Room.h"
#include "data/RoomType.h"

std::vector<Hotel> criarHoteisFicticios() {
    std::vector<Hotel> hoteis;

    Hotel h1("Hotel Mar Azul", "Porto", 4);
    h1.adicionarQuarto(Room(101, 80.0, RoomType::STANDARD));
    h1.adicionarQuarto(Room(102, 120.0, RoomType::DOUBLE));
    h1.adicionarQuarto(Room(103, 150.0, RoomType::DELUXE));
    hoteis.push_back(h1);

    Hotel h2("Serra Palace", "Braga", 5);
    h2.adicionarQuarto(Room(201, 90.0, RoomType::STANDARD));
    h2.adicionarQuarto(Room(202, 140.0, RoomType::DOUBLE));
    h2.adicionarQuarto(Room(203, 180.0, RoomType::DELUXE));
    hoteis.push_back(h2);

    Hotel h3("Sol Nascente", "Faro", 3);
    h3.adicionarQuarto(Room(301, 70.0, RoomType::STANDARD));
    h3.adicionarQuarto(Room(302, 100.0, RoomType::DOUBLE));
    h3.adicionarQuarto(Room(303, 130.0, RoomType::DELUXE));
    hoteis.push_back(h3);

    Hotel h4("Montanha Real", "Viseu", 4);
    h4.adicionarQuarto(Room(401, 85.0, RoomType::STANDARD));
    h4.adicionarQuarto(Room(402, 125.0, RoomType::DOUBLE));
    h4.adicionarQuarto(Room(403, 160.0, RoomType::DELUXE));
    hoteis.push_back(h4);

    Hotel h5("Lagoa Serena", "Aveiro", 3);
    h5.adicionarQuarto(Room(501, 75.0, RoomType::STANDARD));
    h5.adicionarQuarto(Room(502, 110.0, RoomType::DOUBLE));
    h5.adicionarQuarto(Room(503, 140.0, RoomType::DELUXE));
    hoteis.push_back(h5);

    Hotel h6("Castelo do Sol", "Lisboa", 5);
    h6.adicionarQuarto(Room(601, 95.0, RoomType::STANDARD));
    h6.adicionarQuarto(Room(602, 145.0, RoomType::DOUBLE));
    h6.adicionarQuarto(Room(603, 190.0, RoomType::DELUXE));
    hoteis.push_back(h6);

    return hoteis;
}
