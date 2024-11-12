#include <iostream>
#include <fstream>
#include <sstream>
#include <string>   
#include <stdexcept>
#include <vector>
#include<cstring>
#include<iomanip>
#include <cstdlib> 
#include <algorithm>
#include <ctime>


using namespace std;

class HOTEL
{
	private:
	  int room_no;
	  char name[30];
	  char address[50];
	  char phone[15];
	  long days;
	  long cost;
	  char rtype[30];
	  long pay;
	  string date;
	  int age;

	public:
	  void main_menu();	 	 
	  void add();			  
	  void display(); 		  
	  void rooms();			  
	  void edit();		
	  int check(int);		 
	  void modify();		 
	  void delete_rec();             
	  void modify_personal_details(int);
	  void modify_days(int);   
	  string get_current_date();
}h;

void HOTEL::main_menu()
{
	int choice;
	while(choice!=6)
	{
		system("cls");
		cout<<"\n\t\t\t\t *************";
		cout<<"\n\t\t\t\t *THE HOTEL*";
		cout<<"\n\t\t\t\t *************";
		cout<<"\n\t\t\t\t * MAIN MENU *";
		cout<<"\n\t\t\t\t *************";
		cout<<"\n\n\n\t\t\t\t1. Book A Room";
		cout<<"\n\t\t\t\t2. Customer Information";
		cout<<"\n\t\t\t\t3. Rooms Allotted";
		cout<<"\n\t\t\t\t4. Edit Customer Details";
		cout<<"\n\t\t\t\t5. Exit";
		cout<<"\n\n\t\t\t\tEnter Your Choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:	add();
				break;
			case 2: display();
				break;
			case 3: rooms();
				break;
			case 4:	edit();
				break;
			case 5: return;
			default:
				{
					cout<<"\n\n\t\t\tWrong choice.";
					cout<<"\n\t\t\tPress any key to continue.";
					getchar();
				}
		}
	}
}

string HOTEL::get_current_date() {
    time_t now = time(0); // Get current time
    tm *ltm = localtime(&now); // Convert to local time

    // Extract year, month, and day and format as string
    char date[11];  // "YYYY-MM-DD" requires 11 characters
    strftime(date, sizeof(date), "%Y-%m-%d", ltm);
    return string(date);
}

void check_and_add_headings() {
    fstream file("record.csv", ios::in | ios::out | ios::app);
    file.seekg(0, ios::end);
    if (file.tellg() == 0) {
        file << "Room,Name,Address,Phone,age,Days,Cost,Date,Room Type\n";
    } else {
    }
    file.close();

}

void check_and_add_headings_to_old_record() {
    fstream oldFile("old_record.csv", ios::in | ios::out | ios::app);
    oldFile.seekg(0, ios::end);
    
    if (oldFile.tellg() == 0) {  
        oldFile << "Room,Name,Address,Phone,age,Days,Cost,Date,Room Type\n";
    } else {
    }

    oldFile.close();
}


void HOTEL::add() {
    system("cls");
    int r, flag = 0, tag = 0;
    char room_type_choice;
    bool room_found = false;

    check_and_add_headings();

    ofstream fout("record.csv", ios::app);

    cout << "\n\t\t\t Available Room Types and Prices";
    cout << "\n\t\t\t +--------------------+---------+";
    cout << "\n\t\t\t | Room Type           |  Price  |";
    cout << "\n\t\t\t +--------------------+---------+";
    cout << "\n\t\t\t | (D) Deluxe          |  2000   |";
    cout << "\n\t\t\t | (E) Executive       |  5000   |";
    cout << "\n\t\t\t | (P) Presidential    | 10000   |";
    cout << "\n\t\t\t +--------------------+---------+";

    cout << "\n\n Enter the Room Type (D/E/P): ";
    cin >> room_type_choice;

    if (room_type_choice == 'D' || room_type_choice == 'd') {
        system("cls");
        cout << "\n Available Deluxe Rooms (Floors 1-5):\n";
        for (int floor = 1; floor <= 5; floor++) {
            cout << " Floor " << floor << ": ";
            room_found = false;
            for (int room = 101 + (floor - 1) * 100; room <= 106 + (floor - 1) * 100; room++) {
                if (check(room) == 0) {
                    cout << room << " ";
                    room_found = true;
                }
            }
            if (!room_found) {
                cout << "No available rooms.";
            }
            cout << "\n";
        }
        tag = 1;
    } else if (room_type_choice == 'E' || room_type_choice == 'e') {
        system("cls");
        cout << "\n Available Executive Rooms (Floors 6-8):\n";
        for (int floor = 6; floor <= 8; floor++) {
            cout << " Floor " << floor << ": ";
            room_found = false;
            for (int room = 101 + (floor - 1) * 100; room <= 106 + (floor - 1) * 100; room++) {
                if (check(room) == 0) {
                    cout << room << " ";
                    room_found = true;
                }
            }
            if (!room_found) {
                cout << "No available rooms.";
            }
            cout << "\n";
        }
        tag = 2;
    } else if (room_type_choice == 'P' || room_type_choice == 'p') {
        system("cls");
        cout << "\n Available Presidential Rooms (Floors 9-10):\n";
        for (int floor = 9; floor <= 10; floor++) {
            cout << " Floor " << floor << ": ";
            room_found = false;
            for (int room = 101 + (floor - 1) * 100; room <= 106 + (floor - 1) * 100; room++) {
                if (check(room) == 0) {
                    cout << room << " ";
                    room_found = true;
                }
            }
            if (!room_found) {
                cout << "No available rooms.";
            }
            cout << "\n";
        }
        tag = 3;
    } else {
        cout << "\n Invalid Room Type selection.\n";
        return;
    }

    cout << "\n\n Select Room Number: ";
    cin >> r;

   if ((tag == 1 && !(r >= 101 && r <= 506 && r % 100 >= 1 && r % 100 <= 6)) || 
    (tag == 2 && !(r >= 601 && r <= 806 && r % 100 >= 1 && r % 100 <= 6)) ||  
    (tag == 3 && !(r >= 901 && r <= 1006 && r % 100 >= 1 && r % 100 <= 6))) { 
    cout << "\n Error: You have entered an invalid room number for the selected room type.";
    fout.close();
    cout << "\n Press any key to continue.";
    getchar();
    getchar();
    return;
}


    flag = check(r);
    if (flag == 1) {
        cout << "\n Sorry, Room is already booked.\n";
        fout.close();
        cout << "\n Press any key to continue.";
        getchar();
        getchar();
        return;
    }

    room_no = r;
    cout << " Name: ";
    cin.ignore();
    cin.getline(name, 30);
    cout << " Address: ";
    cin.getline(address, 50);


    do {
        cout << " Phone Number (10 digits): ";
        cin.getline(phone, 15);
        if (strlen(phone) != 10 || !isdigit(phone[0])) {
            cout << "\n Invalid Phone Number. It must be exactly 10 digits.\n";
        }
    } while (strlen(phone) != 10 || !isdigit(phone[0]));


    do {
        cout << " Age: ";
        cin >> age;
        if (age < 18 || age > 100) {
            cout << "\n Invalid age. Age must be between 18 and 100.\n";
        }
    } while (age < 18 || age > 100);

    cout << " Number of Days: ";
    cin >> days;
    date = get_current_date();


    if (room_no >= 101 && room_no <= 506) {
        strcpy(rtype, "Deluxe");
        cost = days * 2000;
    } else if (room_no >= 601 && room_no <= 806) {
        strcpy(rtype, "Executive");
        cost = days * 5000;
    } else if (room_no >= 901 && room_no <= 1006) {
        strcpy(rtype, "Presidential");
        cost = days * 10000;
    }

    cout << " Total price is: " << cost;

    fout << room_no << "," << name << "," << address << "," << phone << "," << age
         << "," << days << "," << cost << "," << date << "," << rtype << "\n";

    cout << "\n Room has been booked.\n";

    fout.close();
    cout << "\n Press any key to continue.";
    getchar();
    getchar();
}




void HOTEL::display() {
    system("cls");
    ifstream fin("record.csv");
    if (!fin) {
        cout << "\n Error opening file!";
        cout << "\n Press any key to continue.";
        getchar();
        return;
    }

    string line, word;
    vector<string> row;
    vector<int> booked_rooms;

    getline(fin, line); 

    while (getline(fin, line)) {
        row.clear();
        stringstream s(line);
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
        booked_rooms.push_back(stoi(row[0]));  
    }

    if (booked_rooms.empty()) {
        cout << "\n No rooms are currently booked.";
        cout << "\n\n Press any key to continue.";
        getchar();
        getchar();
        fin.close();
        return;
    }

    // Display the list of booked room numbers
    cout << "\n Booked Room Numbers: ";
    for (int room_no : booked_rooms) {
        cout << room_no << " ";
    }

    // Now, prompt for a specific room number to display its details
    int r, flag = 0;
    cout << "\n\n Enter Room Number: ";
    cin >> r;
    
    flag = check(r);
    if (flag == 2) {
        cout << "\n Invalid room number.";
    cout << "\n\n Press any key to continue.";
    getchar();
    getchar();
    fin.close();
    return;
	}
    // Reset file pointer to read the details of the selected room
    fin.clear();
    fin.seekg(0, ios::beg);  // Move back to the start of the file
    getline(fin, line);  // Skip the header again

    while (getline(fin, line)) {
        row.clear();
        stringstream s(line);
        while (getline(s, word, ',')) {
            row.push_back(word);
        }

        if (stoi(row[0]) == r) {  // Check if the room number matches
            system("cls");
            cout << "\n Customer Details";
            cout << "\n ----------------";
            cout << "\n\n Room Number: " << row[0];
            
            cout << "\n Name: " << row[1];
            cout << "\n Address: " << row[2];
            cout << "\n Phone Number: " << row[3];
            cout << "\n Age: " << row[4];
            cout << "\n Staying for " << row[5] << " days.";
            cout << "\n Room Type: " << row[8];
            cout << "\n Total cost of stay: " << row[6];
            cout << "\n Date of booking: " << row[7];
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        cout << "\n Room is Vacant.";
    }

    cout << "\n\n Press any key to continue.";
    getchar();
    getchar();
    fin.close();
}


void HOTEL::rooms() {
    system("cls");
    ifstream file("record.csv");
    string line;

    cout << "\n\t\t\t +-------------------+-----------------+\n";
    cout << "\t\t\t | Room Number       | Status          |\n";
    cout << "\t\t\t +-------------------+-----------------+\n";

    vector<int> bookedRooms;  // To store booked room numbers
    getline(file, line);  // Skip the header line

    while (getline(file, line)) {
        vector<string> row;
        stringstream s(line);
        string temp;

        while (getline(s, temp, ',')) {
            row.push_back(temp);
        }
        if (!row.empty() && !row[0].empty()) {
            try {
                bookedRooms.push_back(stoi(row[0]));  // Convert room number to int
            } catch (invalid_argument& e) {
                cout << "Invalid room number in record: " << row[0] << "\n";
            } catch (out_of_range& e) {
                cout << "Room number out of range in record: " << row[0] << "\n";
            }
        }
    }
    file.close();

    // Room numbers: 101 to 106 (1st floor), 201 to 206 (2nd floor), up to 1006 (10th floor)
    for (int floor = 1; floor <= 10; ++floor) {
        for (int room = 1; room <= 6; ++room) {
            int roomNumber = floor * 100 + room;  // Calculate room number based on floor and room
            cout << "\t\t\t | " << setw(17) << roomNumber << " | "
                 << (find(bookedRooms.begin(), bookedRooms.end(), roomNumber) != bookedRooms.end() ? "Booked" : "               ")
                 << " |\n";
        }
    }

    cout << "\t\t\t +-------------------+-----------------+\n";

    cout << "\n Press any key to continue.";
    getchar();
    getchar();
}


void HOTEL::edit()
{
	system("cls");
	int choice,r;
	cout<<"\n EDIT MENU";
	cout<<"\n ---------";
	cout<<"\n\n 1. Modify Customer Information.";
	cout<<"\n 2. Customer Check Out.";
	cout<<"\n Enter your choice: ";
	cin>>choice;
	system("cls");
	switch(choice)
	{
		case 1:	modify();
			break;
		case 2:	delete_rec();
			break;
		default: cout<<"\n Wrong Choice.";
			 break;
	}
	cout<<"\n Press any key to continue.";
	getchar();
	getchar();
}

int HOTEL::check(int r) {
    int flag = 0;  // 0: Room is available, 1: Room is booked, 2: Invalid room number
    ifstream fin("record.csv");  // Open the CSV file
    
    if (!fin) {
        cout << "\n Error opening file!";
        return -1;  // Return error code if the file can't be opened
    }

    // Check if the room number is valid (i.e., ends in 1–6)
    if (r % 100 < 1 || r % 100 > 6) {
        fin.close();  // Close the file if the room number is invalid
        return 2;  // Return 2 to indicate that the room number is invalid
    }

    string line, word;
    vector<string> row;
    
    // Skip the first line (headings)
    getline(fin, line);  
    
    // Read each line from the CSV file
    while (getline(fin, line)) {
        row.clear();
        stringstream s(line);

        // Split the line by commas and store in row
        while (getline(s, word, ',')) {
            row.push_back(word);
        }

        // Convert the first column (room number) to an integer and compare with `r`
        if (stoi(row[0]) == r) {
            flag = 1;  // Room is booked
            break;
        }
    }

    fin.close();  // Close the file after processing
    return flag;  // Return 0 if the room is available, 1 if it's booked
}



void HOTEL::modify()
{
    system("cls");
    int ch, r, flag = 0;
    string line, word;
    vector<string> row;

    cout << "\n MODIFY MENU";
    cout << "\n -----------";
    cout << "\n\n\n 1. Modify personal details";
    cout << "\n 2. Modify Number of Days of Stay";
    cout << "\n Enter Your Choice: ";
    cin >> ch;
    system("cls");

    // Display all booked room numbers before entering the room number
    fstream fin("record.csv", ios::in);
    if (!fin) {
        cout << "\n Error opening file!";
        return;
    }

    cout << "\n Currently Booked Rooms: ";
    while (getline(fin, line)) {
        row.clear();
        stringstream s(line);
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
        if (!row.empty() && row[0] != "Room Number") {  // Avoid header row
            cout << row[0] << " ";  // Display booked room numbers
        }
    }
    fin.close();  // Close the file after reading

    cout << "\n\n Enter Room Number: ";
    cin >> r;

    flag = check(r);
    if (flag == 1) {
        switch (ch) {
            case 1:
                modify_personal_details(r);
                break;
            case 2:
                modify_days(r);
                break;
            default:
                cout << "\n Wrong Choice";
                getchar();
                getchar();
                break;
        }
    } else {
        if (flag == 2)
            cout << "\n Sorry, Room does not exist.\n";
        else
            cout << "\n Sorry, Room is vacant.\n";
    }
}


void HOTEL::modify_personal_details(int r)
{
    fstream fin("record.csv", ios::in);  
    ofstream fout("temp.csv");  

    if (!fin || !fout) {
        cout << "\n Error opening file!";
        return;
    }

    string line, word;
    vector<string> row;
    bool flag = false;

//    cout << "\n Currently Booked Rooms: ";
//    while (getline(fin, line)) {
//        row.clear();
//        stringstream s(line);
//        while (getline(s, word, ',')) {
//            row.push_back(word);
//        }
//        if (!row.empty() && row[0] != "Room Number") {  // Assuming the first line is the header
//            cout << row[0] << " ";  // Display booked room number
//        }
//    }

    // Reset the file pointer to read again
    fin.clear();  
    fin.seekg(0, ios::beg);  

    getline(fin, line);  
    fout << line << "\n"; 


    while (getline(fin, line)) {
        row.clear();
        stringstream s(line);
        while (getline(s, word, ',')) {
            row.push_back(word);
        }

        if (stoi(row[0]) == r) {  
            cout << "\n Enter New Name: ";
            cin.ignore();
            getline(cin, row[1]);  

            cout << "\n Enter New Address: ";
            getline(cin, row[2]);  

           
            do {
                cout << "\n Enter New Phone Number (10 digits): ";
                getline(cin, row[3]);
                if (row[3].length() != 10 || !all_of(row[3].begin(), row[3].end(), ::isdigit)) {
                    cout << "\n Invalid phone number. Please enter exactly 10 digits.";
                }
            } while (row[3].length() != 10 || !all_of(row[3].begin(), row[3].end(), ::isdigit));

            do {
                cout << "\n Enter Age (18-100): ";
                getline(cin, row[4]);
                if (stoi(row[4]) < 18 || stoi(row[4]) > 100) {
                    cout << "\n Invalid age. Please enter a valid age between 18 and 100.";
                }
            } while (stoi(row[4]) < 18 || stoi(row[4]) > 100);

            flag = true;  // Room found and details modified
        }

        // Write the row (whether modified or not) to the temp file
        for (size_t i = 0; i < row.size(); ++i) {
            fout << row[i];
            if (i != row.size() - 1)
                fout << ",";  // Add commas between values
        }
        fout << "\n";  // Newline after each row
    }

    fin.close();
    fout.close();

    remove("record.csv");
    rename("temp.csv", "record.csv");

    if (flag) {
        cout << "\n Customer details have been modified.";
    } else {
        cout << "\n Sorry, Room is vacant.";
    }

    getchar();  
}



void HOTEL::modify_days(int r)
{
    fstream fin("record.csv", ios::in);  
    ofstream fout("temp.csv");      

    if (!fin || !fout) {
        cout << "\n Error opening file!";
        return;
    }

    string line, word;
    vector<string> row;
    bool flag = false;
    int new_days;
    double new_cost;
    string new_rtype;

    getline(fin, line);  
    fout << line << "\n";  

    while (getline(fin, line)) {
        row.clear();
        stringstream s(line);

        while (getline(s, word, ',')) {
            row.push_back(word);
        }

        if (stoi(row[0]) == r) { 
            cout << " Enter New Number of Days of Stay: ";
            cin >> new_days;
            row[4] = to_string(new_days);  

            if (r >= 1 && r <= 50) {
                new_rtype = "Deluxe";
                new_cost = new_days * 2000;
            } else if (r >= 51 && r <= 80) {
                new_rtype = "Executive";
                new_cost = new_days * 5000;
            } else if (r >= 81 && r <= 100) {
                new_rtype = "Presidential";
                new_cost = new_days * 10000;
            }

            row[8] = new_rtype;     
            row[6] = to_string(new_cost); 

            flag = true; 
        }

        for (size_t i = 0; i < row.size(); ++i) {
            fout << row[i];
            if (i != row.size() - 1)
                fout << ",";  
        }
        fout << "\n";
    }

    fin.close();
    fout.close();

    remove("record.csv");
    rename("temp.csv", "record.csv");

    if (flag) {
        cout << "\n Customer information is modified.";
    } else {
        cout << "\n Sorry, Room is vacant.";
    }

    getchar();  
}

void HOTEL::delete_rec() {
    int r, flag = 0;
    char ch;

    // Display all booked room numbers before entering the room number
    ifstream fin("record.csv", ios::in);
    if (!fin) {
        cout << "\n Error opening file!";
        return;
    }

    string line, word;
    vector<string> row;

    cout << "\n Currently Booked Rooms: ";
    while (getline(fin, line)) {
        row.clear();
        stringstream s(line);
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
        if (!row.empty() && row[0] != "Room Number") {  // Avoid header row
            cout << row[0] << " ";  // Display booked room numbers
        }
    }
    fin.clear();  
    fin.seekg(0, ios::beg);  // Move back to the start of the file

    cout << "\n\n Enter Room Number: ";
    cin >> r;

    ofstream fout("temp.csv", ios::out);
    ofstream old_fout("old_record.csv", ios::app);  

    if (!fout || !old_fout) {
        cout << "\n Error opening file!";
        fin.close();
        return;
    }

    check_and_add_headings_to_old_record();  

    getline(fin, line);  
    fout << line << "\n"; 

    while (getline(fin, line)) {
        row.clear();
        stringstream s(line);

        while (getline(s, word, ',')) {
            row.push_back(word);
        }

        if (stoi(row[0]) == r) {
            cout << "\n Room is found.";
            cout << "\n Name: " << row[1];
            cout << "\n Address: " << row[2];
            cout << "\n Phone: " << row[3];
            cout << "\n Age: " << row[4];
            cout << "\n Are you sure you want to delete this record (y/n)? ";
            cin >> ch;

            if (ch == 'n' || ch == 'N') {
                fout << line << "\n";  // Write the record back if user doesn't want to delete
            } else {
                flag = 1;  
                cout << "\n Record deleted successfully.";
                old_fout << line << "\n";  // Backup the record in old_record.csv
            }
        } else {
            fout << line << "\n";  // Write the record back if it's not the one being deleted
        }
    }

    fin.close();
    fout.close();
    old_fout.close();

    remove("record.csv");
    rename("temp.csv", "record.csv");

    if (flag == 0) {
        cout << "\n Room number not found.";
    }

    getchar();
}




int main()
{
	system("cls");
	check_and_add_headings();
	h.main_menu();
	return 0;
}
