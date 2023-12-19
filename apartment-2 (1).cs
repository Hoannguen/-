using System;
using System.Collections.Generic;

// Define the structure for an apartment's record
struct Apartment
{
    public float Size;
    public int RoomNumber;
    public int Floor;
    public float Price;
}

class Program
{
    // Initialize a list of apartments
    static List<Apartment> apartmentList = new List<Apartment>();

    // A method for creating new apartments
    static void InputNewApartment()
    {
        float size;
        int roomNumber;
        int floor;
        float price;

        Console.WriteLine("Input the new apartment's info:");
        Console.Write("Size: ");
        size = float.Parse(Console.ReadLine());
        Console.Write("Room Number: ");
        roomNumber = int.Parse(Console.ReadLine());
        Console.Write("Floor: ");
        floor = int.Parse(Console.ReadLine());
        Console.Write("Price: ");
        price = float.Parse(Console.ReadLine());

        Apartment newApartment = new Apartment
        {
            Size = size,
            RoomNumber = roomNumber,
            Floor = floor,
            Price = price
        };

        apartmentList.Add(newApartment);
        Console.WriteLine("The new apartment has been successfully added.");
    }

    // A method for printing all the apartments in the list
    static void PrintApartmentList()
    {
        Console.WriteLine("LIST OF AVAILABLE APARTMENTS");
        Console.WriteLine("|Size           |Room Number    |Floor          |Price          |");
        Console.WriteLine("|---------------|---------------|---------------|---------------|");

        foreach (var apartment in apartmentList)
        {
            Console.WriteLine($"|{apartment.Size,15:F2}|{apartment.RoomNumber,15}|{apartment.Floor,15}|{apartment.Price,15:F2}|");
        }
    }

    // A method for comparing 2 apartments according to their prices
    static bool CompareTwoApartments(Apartment A, Apartment B)
    {
        return A.Price > B.Price;
    }

    // A method for swapping two apartments
    static void SwapTwoApartments(int i1, int i2)
    {
        Apartment temp = apartmentList[i1];
        apartmentList[i1] = apartmentList[i2];
        apartmentList[i2] = temp;
    }

    // A method for bubble sorting the apartment list
    static void BubbleSortApartmentList()
    {
        int len = apartmentList.Count;
        for (int i = 0; i < len - 1; i++)
        {
            for (int j = 0; j < len - i - 1; j++)
            {
                if (CompareTwoApartments(apartmentList[j + 1], apartmentList[j]))
                {
                    SwapTwoApartments(j, j + 1);
                }
            }
        }
    }

    // A method for selection sorting the apartment list
    static void SelectionSortApartmentList()
    {
        int len = apartmentList.Count;
        for (int i = 0; i < len - 1; i++)
        {
            int maxIndex = i;
            for (int j = i + 1; j < len; j++)
            {
                if (CompareTwoApartments(apartmentList[j], apartmentList[maxIndex]))
                {
                    maxIndex = j;
                }
            }
            SwapTwoApartments(maxIndex, i);
        }
    }

    // A method for shuffling the apartment list
    static void ShuffleTheApartmentList()
    {
        Random rng = new Random();
        int n = apartmentList.Count;
        while (n > 1)
        {
            n--;
            int k = rng.Next(n + 1);
            SwapTwoApartments(k, n);
        }

        Console.WriteLine("The list has been shuffled!");
    }

    // A method for sorting the apartment list by price
    static void SortPrice()
    {
        Console.WriteLine("Choose the sorting algorithm:");
        Console.WriteLine("1. Bubble sort");
        Console.WriteLine("2. Selection sort");

        int choice = int.Parse(Console.ReadLine());

        switch (choice)
        {
            case 1:
                BubbleSortApartmentList();
                Console.WriteLine("The list has been sorted!");
                break;
            case 2:
                SelectionSortApartmentList();
                Console.WriteLine("The list has been sorted!");
                break;
            default:
                Console.WriteLine("Unsupported algorithm!");
                break;
        }
    }

    // A method for filtering the apartment list by room number
    static void FilterRoom()
    {
        Console.Write("Enter the room number: ");
        int roomNumber = int.Parse(Console.ReadLine());

        Console.WriteLine("LIST OF SATISFIED APARTMENTS");
        Console.WriteLine("|Size           |Room Number    |Floor          |Price          |");
        Console.WriteLine("|---------------|---------------|---------------|---------------|");

        foreach (var apartment in apartmentList)
        {
            if (apartment.RoomNumber == roomNumber)
            {
                Console.WriteLine($"|{apartment.Size,15:F2}|{apartment.RoomNumber,15}|{apartment.Floor,15}|{apartment.Price,15:F2}|");
            }
        }
    }

    // A method for updating the Nth apartment's info
    static void UpdateApartmentInfo()
    {
        Console.Write("Enter the apartment's index: ");
        int index = int.Parse(Console.ReadLine());

        if (index < 0 || index >= apartmentList.Count)
        {
            Console.WriteLine("Index out of bound!");
            return;
        }

        Console.WriteLine("Input the apartment's new info:");
        Console.Write("Size: ");
        float size = float.Parse(Console.ReadLine());
        Console.Write("Room Number: ");
        int roomNumber = int.Parse(Console.ReadLine());
        Console.Write("Floor: ");
        int floor = int.Parse(Console.ReadLine());
        Console.Write("Price: ");
        float price = float.Parse(Console.ReadLine());

        apartmentList[index] = new Apartment
        {
            Size = size,
            RoomNumber = roomNumber,
            Floor = floor,
            Price = price
        };

        Console.WriteLine("The apartment's info has been successfully updated!");
    }

    // A method for deleting the Nth apartment
    static void DeleteApartment()
    {
        Console.Write("Enter the apartment's index: ");
        int index = int.Parse(Console.ReadLine());

        if (index < 0 || index >= apartmentList.Count)
        {
            Console.WriteLine("Index out of bound!");
            return;
        }

        apartmentList.RemoveAt(index);
    }

    // A method for clearing the terminal screen
    static void ClearScreen()
    {
        Console.Clear();
    }

    // A method for exiting the program
    static void ExitProgram()
    {
        Environment.Exit(0);
    }

    // A method for displaying the help menu
    static void Help()
    {
        Console.WriteLine("THE APARTMENT MANAGEMENT PROGRAM");
        Console.WriteLine("----------------------------------------------------------------");
        Console.WriteLine("Press 1: Add a new apartment");
        Console.WriteLine("Press 2: Update an apartment's info");
        Console.WriteLine("Press 3: Delete an apartment");
        Console.WriteLine("Press 4: View all available apartments");
        Console.WriteLine("Press 5: Sort the apartment list according to their prices");
        Console.WriteLine("Press 6: Filter the apartment list");
        Console.WriteLine("Press 7: Clear screen");
        Console.WriteLine("Press 8: Display the help menu");
        Console.WriteLine("Press 9: Exit");
        Console.WriteLine("Press 0: Shuffle the apartment list (for validation purposes)");
    }

    static void Main()
    {
        char c;

        Help();
        while (true)
        {
            c = Console.ReadKey().KeyChar;
            Console.WriteLine(); // Move to the next line after reading the key.

            switch (c)
            {
                case '1':
                    InputNewApartment();
                    break;
                case '2':
                    UpdateApartmentInfo();
                    break;
                case '3':
                    DeleteApartment();
                    break;
                case '4':
                    PrintApartmentList();
                    break;
                case '5':
                    SortPrice();
                    break;
                case '6':
                    FilterRoom();
                    break;
                case '7':
                    ClearScreen();
                    Help();
                    break;
                case '8':
                    Help();
                    break;
                case '9':
                    ExitProgram();
                    break;
                case '0':
                    ShuffleTheApartmentList();
                    break;
                default:
                    Console.WriteLine("Unsupported command!");
                    break;
            }
        }
    }
}
