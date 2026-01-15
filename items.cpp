#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

struct Item {
    int id;
    string name;
    int quantity;
    string date;
};

string toLower(const string &str) {
    string lower;
    for (char ch : str) lower += tolower(ch);
    return lower;
}

void addItem(int id, string name, int quantity, string date) {
    ofstream file("inventory.csv", ios::app);
    if (file.is_open()) {
        file << id << "," << name << "," << quantity << "," << date << endl;
        file.close();
        cout << "Item added successfully.\n";
    } else {
        cout << "Failed to open file.\n";
    }
}

void listItems() {
    ifstream file("inventory.csv");
    vector<Item> items;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string idStr, name, quantityStr, date;
        getline(ss, idStr, ',');
        getline(ss, name, ',');
        getline(ss, quantityStr, ',');
        getline(ss, date, ',');
        
        Item item;
        item.id = stoi(idStr);
        item.name = name;
        item.quantity = stoi(quantityStr);
        item.date = date;
        items.push_back(item);
    }
    file.close();

    sort(items.begin(), items.end(), [](Item a, Item b) {
        return toLower(a.name) < toLower(b.name);
    });

    for (const auto &item : items) {
        cout << "Item ID:" << item.id << "\tItem Name:" << item.name
             << "\tQuantity :" << item.quantity << "\tReg Date :" << item.date << endl;
    }
}

void help() {
    cout << "Commands syntaxes:\n";
    cout << "itemadd <item_id> <item_name> <quantity> <registration_date>\n";
    cout << "itemslist\n";
    cout << "help\n";
    cout << "exit\n";
}

int main() {
    string command;
    cout << "RCA Inventory System Started. Type 'help' for commands.\n";
    while (true) {
        cout << "\n> ";
        getline(cin, command);

        stringstream ss(command);
        string cmd;
        ss >> cmd;
        cmd = toLower(cmd);

        if (cmd == "itemadd") {
            int id, qty;
            string name, date;
            ss >> id >> name >> qty >> date;
            if (!ss.fail()) {
                addItem(id, name, qty, date);
            } else {
                cout << "Invalid input format. Use: itemadd <id> <name> <qty> <date>\n";
            }
        } else if (cmd == "itemslist") {
            listItems();
        } else if (cmd == "help") {
            help();
        } else if (cmd == "exit") {
            cout << "Exiting program.\n";
            break;
        } else {
            cout << "Unknown command. Type 'help' for available commands.\n";
        }
    }
    return 0;
}
