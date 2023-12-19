#include<iostream>
#include<algorithm>
#include<vector>
#include<random>

using namespace std;

/*
    Define the structure for an apartment's record
*/
struct apartment{
    float size;
    int roomNumber;
    int floor;
    float price;
};


/*
    Initialize a vector of apartment
*/
vector<apartment> apartment_list;

/*
    A method for creating new apartments
*/
void input_new_apartment(){
    float size;
    int roomNumber;
    int floor;
    float price;

    cout << "Input the new apartment's info: " << endl;
    cout << "Size: ";
    cin >> size;
    cout << "Room Number: ";
    cin >> roomNumber;
    cout <<"Floor: ";
    cin >> floor;
    cout <<"Price: ";
    cin >> price;

    apartment* new_apartment = new apartment();
    new_apartment->size = size;
    new_apartment->roomNumber = roomNumber;
    new_apartment->floor = floor;
    new_apartment->price = price;

    apartment_list.push_back(*new_apartment);
    cout << "The new apartment has been sucessfully added." << endl;
};

/*
    A method for printing all the apartment in the list
*/
void print_apartment_list(){
    int len_list;
    len_list = apartment_list.size();
    printf("LIST OF AVAILABLE APARTMENTS\n");
    printf("|Size           |Room Number    |Floor          |Price          |\n");
    printf("|---------------|---------------|---------------|---------------|\n");
    for(int i = 0; i < len_list; i++){
        printf("|%15.2f|%15d|%15d|%15.2f|\n", apartment_list[i].size, apartment_list[i].roomNumber, apartment_list[i].floor, apartment_list[i].price);
    }
}

/*
    A method for comparing 2 apartment according to their prices
*/
bool compare_two_apartments(apartment A, apartment B){
    return A.price > B.price;
}

void swap_two_apartments(int i1, int i2){
    apartment* temp = new apartment();
    // copy apartment i1's info
    temp->size = apartment_list[i1].size;
    temp->roomNumber = apartment_list[i1].roomNumber;
    temp->floor = apartment_list[i1].floor;
    temp->price = apartment_list[i1].price;

    // copy apartment i2's info to apartment i1
    apartment_list[i1].size = apartment_list[i2].size;
    apartment_list[i1].roomNumber = apartment_list[i2].roomNumber;
    apartment_list[i1].floor = apartment_list[i2].floor;
    apartment_list[i1].price = apartment_list[i2].price;

    // copy apartment i1's info to apartment i2
    apartment_list[i2].size = temp->size;
    apartment_list[i2].roomNumber = temp->roomNumber;
    apartment_list[i2].floor = temp->floor;
    apartment_list[i2].price = temp->price;
}

void bubble_sort_apartment_list(){
    int i, j;
    int len = apartment_list.size();
    for (i = 0; i < len - 1; i++){
        for (j = 0; j < len - i - 1; j++){
            if (compare_two_apartments(apartment_list[j+1], apartment_list[j])){
                swap_two_apartments(j, j + 1);
            }
        }
    }
}

void selection_sort_apartment_list(){
    int i, j, max_index;
    int len = apartment_list.size();
    for(i = 0; i < len - 1; i++){
        max_index = i;
        for(j = i+1; j < len; j++){
            if(compare_two_apartments(apartment_list[j], apartment_list[max_index])){
                max_index = j;
            }
        }
        swap_two_apartments(max_index, i);
    }
}

/*
    A shuffle method just to check the sorting algorithms
*/
void shuffle_the_apartment_list(){
    random_shuffle(apartment_list.begin(), apartment_list.end());
    cout << "The list has been shuffled!" << endl;
}

void sort_price(){
    int i;
    cout << "Choose the sorting algorithm:" << endl;
    cout << "1. Bubble sort" << endl;
    cout << "2. Selection sort" << endl;
    cin >> i;
    if(i == 1){
        bubble_sort_apartment_list();
        cout << "The list has been sorted!" << endl;
    }
    else if(i == 2){
        selection_sort_apartment_list();
        cout << "The list has been sorted!" << endl;
    }
    else{
        cout << "Unsupported algorithm!" << endl;
    }
}


/*
    Filter the apartment list
*/
void filter_room(){
    int roomNumber;
    int len_list;

    len_list = apartment_list.size();

    cout << "Enter the room number";
    cin >> roomNumber;

    printf("LIST OF SATISFIED APARTMENTS\n");
    printf("|Size           |Room Number    |Floor          |Price          |\n");
    printf("|---------------|---------------|---------------|---------------|\n");

    for(int i = 0; i < len_list; i++){
        if(apartment_list[i].roomNumber == roomNumber){
            printf("|%15.2f|%15d|%15d|%15.2f|\n", apartment_list[i].size, apartment_list[i].roomNumber, apartment_list[i].floor, apartment_list[i].price);
        }
    }
}

/*
    Update the Nth apartment's info
*/
void update_apartment_info(){
    int index;
    float size;
    int roomNumber;
    int floor;
    float price;
    
    cout << "Enter the apartment's index:";
    cin >> index;
    if(index < 0 || index >= apartment_list.size()){
        cout << "Index out of bound!" << endl;
        return;
    }

    cout << "Input the apartment's new info: " << endl;
    cout << "Size: ";
    cin >> size;
    cout << "Room Number: ";
    cin >> roomNumber;
    cout <<"Floor: ";
    cin >> floor;
    cout <<"Price: ";
    cin >> price;

    apartment_list[index].size = size;
    apartment_list[index].roomNumber = roomNumber;
    apartment_list[index].floor = floor;
    apartment_list[index].price = price;

    cout << "The apartment's info has been sucessfully updated!" << endl;
}


/*
    Detele the Nth apartment
*/
void delete_apartment(){
    int index;
    cout << "Enter the apartment's index:";
    cin >> index;
    if(index < 0 || index >= apartment_list.size()){
        cout << "Index out of bound!" << endl;
        return;
    }
    apartment_list.erase(apartment_list.begin() + index);
}


/*
    A method for clearing the terminal screen
*/
void clear_screen(){
    system("clear");
}

/*
    A method for exiting the program
*/
void exit_program(){
    exit(0);
}

/*
    A method for displaying the help menu
*/
void help(){
    cout << "THE APARTMENT MANAGEMENT PROGRAM" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "Press 1: Add a new apartment" << endl;
    cout << "Press 2: Update an apartment's info" << endl;
    cout << "Press 3: Delete an apartment" << endl;
    cout << "Press 4: View all available apartments" << endl;
    cout << "Press 5: Sort the apartment list according to their prices" << endl;
    cout << "Press 6: Filter the apartment list" << endl;
    cout << "Press 7: Clear screen" << endl; 
    cout << "Press 8: Display the help menu" << endl;
    cout << "Press 9: Exit" << endl;
    cout << "Press 0: Shuffle the apartment list (for validation purposes)" << endl;
}

int main(){
    char c;
    int N;
    int len_list;

    /*
        Initialize the apartment list
    */
    apartment apartment_list[1024];
    len_list = 0;

    help();
    while(1){
        cin >> c; 
        if(c == '1'){
            input_new_apartment();
        }
        else if(c == '2'){
            update_apartment_info();
        }
        else if(c == '3'){
            delete_apartment();
        }
        else if(c == '4'){
            print_apartment_list();
        }
        else if(c == '5'){
            sort_price();
        }
        else if(c == '6'){
            filter_room();
        }
        else if(c == '7'){
            clear_screen();
            help();
        }
        else if(c == '8'){
            help();
        }
        else if(c == '9'){
            exit_program();
        }
        else if(c == '0'){
            shuffle_the_apartment_list();
        }
        else{
            cout << "Unsupported command!" << endl;
        }
    }

    return 0;
}