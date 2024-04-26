#include <vector>
#include <iostream>

using namespace std;

class Tree{
private:

    Flight* root;

    Flight* addFlight(Flight* root, string departureAirport, string arrivalAirport, int departureHour, int departureMinute) {
        if (root == nullptr) {
            return new Flight(departureAirport, arrivalAirport, departureHour, departureMinute);
        }
        if (departureAirport < root->departureAirport) {
            root->left = addFlight(root->left, departureAirport, arrivalAirport, departureHour, departureMinute);
        }
        else if (departureAirport > root->departureAirport) {
            root->right = addFlight(root->right, departureAirport, arrivalAirport, departureHour, departureMinute);
        }
        else {
            cout << "Рейс уже существует" << endl;
        }
        return root;
    }


    Flight* removeFlight(Flight* root, string departureAirport, string arrivalAirport, int departureHour, int departureMinute) {
        if (root == nullptr) {
            return root;
        }
        if (departureAirport < root->departureAirport) {
            root->left = removeFlight(root->left, departureAirport, arrivalAirport, departureHour, departureMinute);
        }
        else if (departureAirport > root->departureAirport) {
            root->right = removeFlight(root->right, departureAirport, arrivalAirport, departureHour, departureMinute);
        }
        else {
            if (root->left == nullptr) {
                Flight* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                Flight* temp = root->left;
                delete root;
                return temp;
            }
            else {
                Flight* temp = getMinValueNode(root->right);
                root->departureAirport = temp->departureAirport;
                root->arrivalAirport = temp->arrivalAirport;
                root->right = removeFlight(root->right, temp->departureAirport, temp->arrivalAirport, temp->departureHour, temp->departureMinute);
            }
        }

        return root;
    }

    Flight* getMinValueNode(Flight* node) {
        Flight* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    Flight* findFlight(Flight* root, string departureAirport, string arrivalAirport, int departureHour, int departureMinute) {
        if (root == nullptr || (root->departureAirport == departureAirport && root->arrivalAirport == arrivalAirport)) {
            return root;
        }

        if (departureAirport < root->departureAirport && arrivalAirport < root->arrivalAirport) {
            return findFlight(root->left, departureAirport, arrivalAirport, departureHour, departureMinute);
        }

        return findFlight(root->right, departureAirport, arrivalAirport, departureHour, departureMinute);
    }

    void printFlights(Flight* node) {
        if (node == nullptr) {
            return;
        }

        printFlights(node->left);

        cout << "Departure Airport: " << node->departureAirport << ", Arrival Airport: " << node->arrivalAirport << endl;

        printFlights(node->right);
    }


public:
    Tree() {
        root = nullptr;
    }

    void addFlight(string departureAirport, string arrivalAirport, int departureHour, int departureMinute) {
        root = addFlight(root, departureAirport, arrivalAirport, departureHour, departureMinute);
    }

    void removeFlight(string departureAirport, string arrivalAirport, int departureHour, int departureMinute) {
        root = removeFlight(root, departureAirport, arrivalAirport, departureHour, departureMinute);
    }

    bool findFlight(string departureAirport, string arrivalAirport, int departureHour, int departureMinute) {
        return findFlight(root, departureAirport, arrivalAirport, departureHour, departureMinute) != nullptr;
    }

    void printAllFlights() {
        if (root == nullptr) {
            cout << "Дерево пусто." << endl;
        }
        else {
            printFlights(root);
        }
    }
};