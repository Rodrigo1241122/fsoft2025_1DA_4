
#include <iostream>
#include <vector>
#include "model/Hotel.h"
#include "data/seed.h"
#include "Controller.h"

using namespace std;

int main() {
    vector<Hotel> hoteis = criarHoteisFicticios();

    Controller controller(hoteis);
    controller.run();

    cout << "Application has exited" << endl;
    return 0;
}
