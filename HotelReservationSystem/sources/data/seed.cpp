// seed.cpp - Tiago

#include <vector>
#include <memory> 
#include "model/Hotel.h"
#include "model/Room.h"
#include "data/RoomType.h"

std::vector<Hotel> criarHoteisFicticios() {
    std::vector<Hotel> hoteis;

    // Criar um shared_ptr para Hotel
    std::shared_ptr<Hotel> h1 = std::make_shared<Hotel>("Hotel Mar Azul", "Porto", 4);
    h1->adicionarQuarto(Room(1, 101, 80.0, RoomType::STANDARD, h1));
    h1->adicionarQuarto(Room(2, 102, 120.0, RoomType::DOUBLE, h1));
    h1->adicionarQuarto(Room(3, 103, 150.0, RoomType::DELUXE, h1));
    hoteis.push_back(*h1); // Salvar o hotel na lista

    std::shared_ptr<Hotel> h2 = std::make_shared<Hotel>("Serra Palace", "Braga", 5);
    h2->adicionarQuarto(Room(4, 201, 90.0, RoomType::STANDARD, h2));
    h2->adicionarQuarto(Room(5, 202, 140.0, RoomType::DOUBLE, h2));
    h2->adicionarQuarto(Room(6, 203, 180.0, RoomType::DELUXE, h2));
    hoteis.push_back(*h2);

    std::shared_ptr<Hotel> h3 = std::make_shared<Hotel>("Sol Nascente", "Faro", 3);
    h3->adicionarQuarto(Room(7, 301, 70.0, RoomType::STANDARD, h3));
    h3->adicionarQuarto(Room(8, 302, 100.0, RoomType::DOUBLE, h3));
    h3->adicionarQuarto(Room(9, 303, 130.0, RoomType::DELUXE, h3));
    hoteis.push_back(*h3);

    std::shared_ptr<Hotel> h4 = std::make_shared<Hotel>("Montanha Real", "Viseu", 4);
    h4->adicionarQuarto(Room(10, 401, 85.0, RoomType::STANDARD, h4));
    h4->adicionarQuarto(Room(11, 402, 125.0, RoomType::DOUBLE, h4));
    h4->adicionarQuarto(Room(12, 403, 160.0, RoomType::DELUXE, h4));
    hoteis.push_back(*h4);

    std::shared_ptr<Hotel> h5 = std::make_shared<Hotel>("Lagoa Serena", "Aveiro", 3);
    h5->adicionarQuarto(Room(13, 501, 75.0, RoomType::STANDARD, h5));
    h5->adicionarQuarto(Room(14, 502, 110.0, RoomType::DOUBLE, h5));
    h5->adicionarQuarto(Room(15, 503, 140.0, RoomType::DELUXE, h5));
    hoteis.push_back(*h5);

    std::shared_ptr<Hotel> h6 = std::make_shared<Hotel>("Castelo do Sol", "Lisboa", 5);
    h6->adicionarQuarto(Room(16, 601, 95.0, RoomType::STANDARD, h6));
    h6->adicionarQuarto(Room(17, 602, 145.0, RoomType::DOUBLE, h6));
    h6->adicionarQuarto(Room(18, 603, 190.0, RoomType::DELUXE, h6));
    hoteis.push_back(*h6);

    return hoteis;
}
