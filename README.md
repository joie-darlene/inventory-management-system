📖 README.md Content
markdown
# Inventory Management System

A command-line C++ application for managing inventory items with CSV storage. The system allows users to add items with unique IDs, track quantities, store registration dates, and list all items sorted alphabetically.

## 🚀 Features

📦 **Item Management**
- Add new items with ID, name, quantity, and date
- Automatic CSV file persistence
- Case-insensitive alphabetical sorting

📋 **Inventory Listing**
- Display all items in alphabetical order
- Clean, formatted output with tab separation
- Reads from `inventory.csv` file

🎯 **User-Friendly Interface**
- Simple command-based interaction
- Built-in help system
- Case-insensitive command parsing
- Input validation and error handling

💾 **Data Persistence**
- CSV file storage (`inventory.csv`)
- Maintains data between sessions
- Easy to export/import data

## 🛠️ Technologies Used

- **Language:** C++
- **Concepts Used:**
  - File I/O (ifstream, ofstream)
  - Data structures (structs, vectors)
  - String manipulation and parsing
  - Algorithm sorting with custom comparators
  - Command-line interface design
- **Tools:** Git, GitHub, Standard C++ Library

## 📂 Project Structure
inventory-management-system/
├── items.cpp # Main program source code
├── inventory.csv # Inventory database (auto-generated)
├── README.md # This documentation
└── .gitignore # Git ignore file

text

### Data File Format (`inventory.csv`)
id,name,quantity,date
1,Laptop,5,2024-01-15
2,Mouse,20,2024-01-16
3,Keyboard,12,2024-01-14

text

## ▶️ How to Run

1. **Clone the repository**
   ```bash
   git clone https://github.com/your-username/inventory-management-system.git
   cd inventory-management-system
Compile the program

bash
g++ items.cpp -o inventory_manager
*(Requires C++11 or higher)*

Run the program

bash
./inventory_manager
💻 Available Commands
Command	Description	Example
itemadd <id> <name> <qty> <date>	Add new inventory item	itemadd 4 Monitor 8 2024-01-17
itemslist	List all items alphabetically	itemslist
help	Show available commands	help
exit	Exit the program	exit
Example Session
text
RCA Inventory System Started. Type 'help' for commands.

> itemadd 1 Laptop 5 2024-01-15
Item added successfully.

> itemadd 2 Mouse 20 2024-01-16
Item added successfully.

> itemslist
Item ID:1    Item Name:Laptop    Quantity :5    Reg Date :2024-01-15
Item ID:2    Item Name:Mouse     Quantity :20   Reg Date :2024-01-16
📚 What I Learned
File handling with CSV format in C++

Struct design for data organization

Custom sorting with lambda functions

Building interactive command-line interfaces

Input validation and error handling

Case-insensitive string comparison techniques

🔮 Future Improvements
Add item deletion functionality

Implement item search by name or ID

Add quantity update feature

Include low stock warnings

Add data export to different formats

Implement date validation

Add duplicate ID prevention

Create backup system for data

⚠️ Notes
The inventory.csv file is created automatically on first run

Item names are case-insensitive when sorting

IDs should be unique (current version doesn't enforce this)

Date format should be consistent (YYYY-MM-DD recommended)

👤 Author
Your Name
GitHub: @your-username

📄 License
This project is for educational and personal use. Feel free to modify and distribute.
