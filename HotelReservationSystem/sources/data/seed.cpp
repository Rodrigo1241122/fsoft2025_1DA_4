#include <vector>
#include <memory>
#include "model/Hotel.h"
#include "model/Room.h"
#include "model/Activity.h"
#include "model/Service.h"
#include "data/RoomType.h"

std::vector<Hotel> criarHoteisFicticios() {
    std::vector<Hotel> hoteis;

    // Hotel 1: Porto
    std::shared_ptr<Hotel> h1 = std::make_shared<Hotel>(1, "Hotel Mar Azul", "Porto", 4);
    h1->adicionarQuarto(Room(101, 101, 80.0, RoomType::STANDARD, h1));
    h1->adicionarQuarto(Room(102, 102, 120.0, RoomType::SUITE, h1));
    h1->adicionarQuarto(Room(103, 103, 150.0, RoomType::DELUXE, h1));
    h1->getActivityContainer().addActivity(Activity(110, "Port Wine Tasting", "Taste the famous Porto wines.", 20.0f));
    h1->getActivityContainer().addActivity(Activity(111, "River Cruise", "Boat trip on the Douro river.", 30.0f));
    h1->getActivityContainer().addActivity(Activity(112, "Pool", "Outdoor swimming pool access.", 10.0f));
    h1->getActivityContainer().addActivity(Activity(113, "Gym", "Fitness center full access.", 12.0f));
    h1->getActivityContainer().addActivity(Activity(114, "Fado Night", "Traditional Portuguese music night.", 15.0f));
    h1->getServiceContainer().addService(Service(120, "Breakfast", "Buffet breakfast served daily.", 7.5f));
    h1->getServiceContainer().addService(Service(121, "Lunch/Dinner", "3-course meal.", 18.0f));
    h1->getServiceContainer().addService(Service(122, "Room Cleaning", "Daily cleaning.", 5.0f));
    h1->getServiceContainer().addService(Service(123, "Laundry", "Laundry service.", 6.5f));
    h1->getServiceContainer().addService(Service(124, "Premium Wi-Fi", "High-speed internet.", 3.0f));
    h1->getServiceContainer().addService(Service(125, "Port Wine Mini-bar", "Mini-bar with Porto wines.", 15.0f));
    h1->getServiceContainer().addService(Service(126, "River View Upgrade", "Upgrade to river view.", 12.0f));
    hoteis.push_back(*h1);

    // Hotel 2: Braga
    std::shared_ptr<Hotel> h2 = std::make_shared<Hotel>(2, "Serra Palace", "Braga", 5);
    h2->adicionarQuarto(Room(201, 201, 90.0, RoomType::STANDARD, h2));
    h2->adicionarQuarto(Room(202, 202, 140.0, RoomType::SUITE, h2));
    h2->adicionarQuarto(Room(203, 203, 180.0, RoomType::DELUXE, h2));
    h2->getActivityContainer().addActivity(Activity(210, "Cathedral Tour", "Visit iconic cathedral.", 18.0f));
    h2->getActivityContainer().addActivity(Activity(211, "Hiking", "Guided Gerês tour.", 25.0f));
    h2->getActivityContainer().addActivity(Activity(212, "Pool", "Outdoor pool access.", 10.0f));
    h2->getActivityContainer().addActivity(Activity(213, "Sauna", "Relaxing sauna session.", 14.0f));
    h2->getActivityContainer().addActivity(Activity(214, "Wine & Cheese", "Regional tasting.", 20.0f));
    h2->getServiceContainer().addService(Service(220, "Breakfast", "Buffet breakfast.", 7.5f));
    h2->getServiceContainer().addService(Service(221, "Lunch/Dinner", "3-course meal.", 18.0f));
    h2->getServiceContainer().addService(Service(222, "Room Cleaning", "Daily cleaning.", 5.0f));
    h2->getServiceContainer().addService(Service(223, "Laundry", "Laundry service.", 6.5f));
    h2->getServiceContainer().addService(Service(224, "Premium Wi-Fi", "Fast internet.", 3.0f));
    h2->getServiceContainer().addService(Service(225, "Mountain Shuttle", "Shuttle to Gerês park.", 20.0f));
    h2->getServiceContainer().addService(Service(226, "Cathedral View", "Room upgrade with view.", 14.0f));
    hoteis.push_back(*h2);

    // Hotel 3: Faro
    std::shared_ptr<Hotel> h3 = std::make_shared<Hotel>(3, "Sol Nascente", "Faro", 3);
    h3->adicionarQuarto(Room(301, 301, 70.0, RoomType::STANDARD, h3));
    h3->adicionarQuarto(Room(302, 302, 100.0, RoomType::SUITE, h3));
    h3->adicionarQuarto(Room(303, 303, 130.0, RoomType::DELUXE, h3));
    h3->getActivityContainer().addActivity(Activity(310, "Boat Tour", "Explore Ria Formosa park.", 28.0f));
    h3->getActivityContainer().addActivity(Activity(311, "Beach Yoga", "Morning yoga by the sea.", 12.0f));
    h3->getActivityContainer().addActivity(Activity(312, "Pool", "Outdoor swimming pool access.", 10.0f));
    h3->getActivityContainer().addActivity(Activity(313, "Surf Lessons", "Group surf lessons.", 35.0f));
    h3->getActivityContainer().addActivity(Activity(314, "Bike Rental", "Explore the city.", 8.0f));
    h3->getServiceContainer().addService(Service(320, "Breakfast", "Buffet breakfast.", 7.5f));
    h3->getServiceContainer().addService(Service(321, "Lunch/Dinner", "3-course meal.", 18.0f));
    h3->getServiceContainer().addService(Service(322, "Room Cleaning", "Daily cleaning.", 5.0f));
    h3->getServiceContainer().addService(Service(323, "Laundry", "Laundry service.", 6.5f));
    h3->getServiceContainer().addService(Service(324, "Premium Wi-Fi", "Fast internet.", 3.0f));
    h3->getServiceContainer().addService(Service(325, "Beach Umbrella Rental", "Umbrella and chair.", 9.0f));
    h3->getServiceContainer().addService(Service(326, "Seafood Platter", "Algarve seafood meal.", 20.0f));
    hoteis.push_back(*h3);

    // Hotel 4: Viseu
    std::shared_ptr<Hotel> h4 = std::make_shared<Hotel>(4, "Montanha Real", "Viseu", 4);
    h4->adicionarQuarto(Room(401, 401, 85.0, RoomType::STANDARD, h4));
    h4->adicionarQuarto(Room(402, 402, 125.0, RoomType::SUITE, h4));
    h4->adicionarQuarto(Room(403, 403, 160.0, RoomType::DELUXE, h4));
    h4->getActivityContainer().addActivity(Activity(410, "Vineyard Tour", "Tour through vineyards.", 22.0f));
    h4->getActivityContainer().addActivity(Activity(411, "Horse Riding", "Horseback riding tour.", 27.0f));
    h4->getActivityContainer().addActivity(Activity(412, "Pool", "Outdoor swimming pool access.", 10.0f));
    h4->getActivityContainer().addActivity(Activity(413, "Mountain Hiking", "Guided hiking tour.", 25.0f));
    h4->getActivityContainer().addActivity(Activity(414, "Cuisine Night", "Traditional dinner event.", 18.0f));
    h4->getServiceContainer().addService(Service(420, "Breakfast", "Buffet breakfast.", 7.5f));
    h4->getServiceContainer().addService(Service(421, "Lunch/Dinner", "3-course meal.", 18.0f));
    h4->getServiceContainer().addService(Service(422, "Room Cleaning", "Daily cleaning.", 5.0f));
    h4->getServiceContainer().addService(Service(423, "Laundry", "Laundry service.", 6.5f));
    h4->getServiceContainer().addService(Service(424, "Premium Wi-Fi", "Fast internet.", 3.0f));
    h4->getServiceContainer().addService(Service(425, "Picnic Basket", "Mountain picnic basket.", 11.0f));
    h4->getServiceContainer().addService(Service(426, "Wine Basket", "Selection of local wines.", 16.0f));
    hoteis.push_back(*h4);

    // Hotel 5: Aveiro
    std::shared_ptr<Hotel> h5 = std::make_shared<Hotel>(5, "Lagoa Serena", "Aveiro", 3);
    h5->adicionarQuarto(Room(501, 501, 75.0, RoomType::STANDARD, h5));
    h5->adicionarQuarto(Room(502, 502, 110.0, RoomType::SUITE, h5));
    h5->adicionarQuarto(Room(503, 503, 140.0, RoomType::DELUXE, h5));
    h5->getActivityContainer().addActivity(Activity(510, "Moliceiro Tour", "Boat trip in canals.", 16.0f));
    h5->getActivityContainer().addActivity(Activity(511, "Salt Pans Visit", "Discover salt production.", 14.0f));
    h5->getActivityContainer().addActivity(Activity(512, "Pool", "Outdoor pool access.", 10.0f));
    h5->getActivityContainer().addActivity(Activity(513, "Art Nouveau Walk", "Architecture tour.", 10.0f));
    h5->getActivityContainer().addActivity(Activity(514, "Lagoon Cycling", "Bike by the lagoon.", 8.0f));
    h5->getServiceContainer().addService(Service(520, "Breakfast", "Buffet breakfast.", 7.5f));
    h5->getServiceContainer().addService(Service(521, "Lunch/Dinner", "3-course meal.", 18.0f));
    h5->getServiceContainer().addService(Service(522, "Room Cleaning", "Daily cleaning.", 5.0f));
    h5->getServiceContainer().addService(Service(523, "Laundry", "Laundry service.", 6.5f));
    h5->getServiceContainer().addService(Service(524, "Premium Wi-Fi", "Fast internet.", 3.0f));
    h5->getServiceContainer().addService(Service(525, "Moliceiro Ticket", "Canal boat ride ticket.", 7.0f));
    h5->getServiceContainer().addService(Service(526, "Ovos Moles Welcome", "Traditional sweets.", 5.0f));
    hoteis.push_back(*h5);

    // Hotel 6: Lisboa
    std::shared_ptr<Hotel> h6 = std::make_shared<Hotel>(6, "Castelo do Sol", "Lisboa", 5);
    h6->adicionarQuarto(Room(601, 601, 95.0, RoomType::STANDARD, h6));
    h6->adicionarQuarto(Room(602, 602, 145.0, RoomType::SUITE, h6));
    h6->adicionarQuarto(Room(603, 603, 190.0, RoomType::DELUXE, h6));
    h6->getActivityContainer().addActivity(Activity(610, "Tram Tour", "Historic tram trip.", 19.0f));
    h6->getActivityContainer().addActivity(Activity(611, "Fado Live", "Live Fado performance.", 17.0f));
    h6->getActivityContainer().addActivity(Activity(612, "Pool", "Outdoor pool access.", 10.0f));
    h6->getActivityContainer().addActivity(Activity(613, "Castle Visit", "Visit São Jorge Castle.", 13.0f));
    h6->getActivityContainer().addActivity(Activity(614, "Tuk Tuk Tour", "Explore city by tuk tuk.", 22.0f));
    h6->getServiceContainer().addService(Service(620, "Breakfast", "Buffet breakfast.", 7.5f));
    h6->getServiceContainer().addService(Service(621, "Lunch/Dinner", "3-course meal.", 18.0f));
    h6->getServiceContainer().addService(Service(622, "Room Cleaning", "Daily cleaning.", 5.0f));
    h6->getServiceContainer().addService(Service(623, "Laundry", "Laundry service.", 6.5f));
    h6->getServiceContainer().addService(Service(624, "Premium Wi-Fi", "Fast internet.", 3.0f));
    h6->getServiceContainer().addService(Service(625, "Castle View Upgrade", "Room with castle view.", 14.0f));
    h6->getServiceContainer().addService(Service(626, "Pastel de Nata Welcome", "Pastry on arrival.", 4.0f));
    hoteis.push_back(*h6);

    return hoteis;
}
