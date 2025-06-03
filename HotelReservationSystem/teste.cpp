// teste.cpp - Tiago

#include <iostream>
#include <vector>
#include "data/seed.h"
#include "model/Reservation.h"
#include "model/Client.h"
#include "model/Date.h"
#include "data/ReservationStatus.h"
#include "data/RoomType.h"

int main() {
    // 1. Inicializar os hotéis fictícios
    std::vector<Hotel> hoteis = criarHoteisFicticios();

    std::cout << "======= Lista de Hoteis =======\n";
    for (const auto& hotel : hoteis) {
        std::cout << hotel.getName() << " - " << hotel.getLocation()
                  << " (" << hotel.getStars() << " estrelas)\n";

        const auto& quartos = hotel.getRoomContainer().getAllRooms();

        for (const auto& q : quartos) {
            std::cout << "  Quarto " << q.getNumber()
                      << " | Tipo: " << static_cast<int>(q.getType())
                      << " | Preço: " << q.getPricePerNight() << "€\n";
        }

        std::cout << "-----------------------------\n";
    }

    // 2. Criar cliente fictício
    Date nascimento(1, 1, 2000);
    auto cliente = std::make_shared<Client>("Tiago", "tiago@email.com", "911234567", nascimento);

    // 3. Selecionar hotel e quarto manualmente
    Hotel& hotelEscolhido = hoteis[0];
    auto& quartosHotel = hotelEscolhido.getRoomContainer().getAllRooms();
    std::shared_ptr<Room> quartoEscolhido = std::make_shared<Room>(quartosHotel[0]);

    // 4. Criar datas
    Date checkIn(1, 6, 2025);
    Date checkOut(3, 6, 2025);

    // 5. Criar reserva
    Reservation reserva(cliente, quartoEscolhido, checkIn, checkOut, quartoEscolhido->getPricePerNight(), ReservationStatus::CONFIRMED);

    // 6. Mostrar detalhes da reserva
    std::cout << "\n======= Reserva Criada =======\n";
    std::cout << "Cliente: " << cliente->getName() << "\n";
    std::cout << "Hotel: " << hotelEscolhido.getName() << "\n";
    std::cout << "Quarto nº: " << quartoEscolhido->getNumber()
              << " | Preço por noite: " << quartoEscolhido->getPricePerNight() << "€\n";

    std::cout << "Check-in: ";
    int dia, mes, ano;
    checkIn.getDate(dia, mes, ano);
    std::cout << dia << "/" << mes << "/" << ano;

    std::cout << "\nCheck-out: ";
    checkOut.getDate(dia, mes, ano);
    std::cout << dia << "/" << mes << "/" << ano;

    std::cout << "\nEstado: " << static_cast<int>(reserva.getStatus()) << " (0 = CONFIRMED, 1 = CANCELLED)\n";
    std::cout << "===============================\n";

    return 0;
}
