#ifndef SEARCHVIEW_H
#define SEARCHVIEW_H

class SearchView {
public:
    int menuSearch() const;
    void searchAvailableRooms() const;
    void chooseRoom() const;
    void reserveRoom() const;
    void applyDiscountCoupon() const;
    void cancelReservation() const;
};

#endif // SEARCHVIEW_H
