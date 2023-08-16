#include <iostream>
#include <vector>

using namespace std;

class GalacticSpacecraft 
{
    private:
        int x, y, z;
        string direction;

    public:
        GalacticSpacecraft(int startX, int startY, int startZ, string startDirection)
            : x(startX), y(startY), z(startZ), direction(startDirection) {}

        void moveForward() {
            if (direction == "N") y++;
            else if (direction == "S") y--;
            else if (direction == "E") x++;
            else if (direction == "W") x--;
        }

        void moveBackward() {
            if (direction == "N") y--;
            else if (direction == "S") y++;
            else if (direction == "E") x--;
            else if (direction == "W") x++;
        }

        void turnLeft() {
            if (direction == "N") direction = "W";
            else if (direction == "W") direction = "S";
            else if (direction == "S") direction = "E";
            else if (direction == "E") direction = "N";
        }

        void turnRight() {
            if (direction == "N") direction = "E";
            else if (direction == "E") direction = "S";
            else if (direction == "S") direction = "W";
            else if (direction == "W") direction = "N";
        }

        void turnUp() {
            if (direction == "N") direction = "Up";
            else if (direction == "S") direction = "Down";
        }

        void turnDown() {
            if (direction == "Up") direction = "N";
            else if (direction == "Down") direction = "S";
        }

        void printState() {
            cout << "Position: (" << x << ", " << y << ", " << z << "), Direction: " << direction << endl;
        }
};

void executeCommands(GalacticSpacecraft& spacecraft, const vector<char>& commands) {
    for (char command : commands) {
        switch (command) {
            case 'f':
                spacecraft.moveForward();
                break;
            case 'b':
                spacecraft.moveBackward();
                break;
            case 'l':
                spacecraft.turnLeft();
                break;
            case 'r':
                spacecraft.turnRight();
                break;
            case 'u':
                spacecraft.turnUp();
                break;
            case 'd':
                spacecraft.turnDown();
                break;
            default:
                // Ignore invalid commands
                break;
        }
    }
}

int main() {
    int startX = 0, startY = 0, startZ = 0;
    string startDirection = "N";
    vector<char> commands = {'f', 'r', 'u', 'b', 'l'};

    GalacticSpacecraft spacecraft(startX, startY, startZ, startDirection);
    cout << "Initial State: ";
    spacecraft.printState();

    executeCommands(spacecraft, commands);

    cout << "Final State: ";
    spacecraft.printState();

    return 0;
}
