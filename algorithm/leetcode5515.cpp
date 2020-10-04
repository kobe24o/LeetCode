class ParkingSystem {
    int a, b, c;
public:
    ParkingSystem(int big, int medium, int small) {
        a = big, b = medium, c = small;
    }
    
    bool addCar(int carType) {
        if(carType == 1 && a > 0)
        {
            a--;
            return true;
        }
        else if(carType == 2 && b > 0)
        {
            b--;
            return true;
        }
        else if(carType == 3 && c > 0)
        {
            c--;
            return true;
        }
        return false;
    }
};