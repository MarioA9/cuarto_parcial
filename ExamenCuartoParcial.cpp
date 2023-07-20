//Critter
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Punteros();
void determinar(std::vector<int>& numbers);
int countEvenDigits(int number);
int findLargestEvenDigitsIndex(const std::vector<int>& numbers);
void MiMascota();

class Critter
{
public:
    Critter(int hunger = 0, int boredom = 0, int thirst = 0);
    void Talk();
    void Eat(int food = 4);
    void Drink(int water = 4);
    void Play(int fun = 4);
private:
    int m_Hunger;
    int m_Thirst;
    int m_Boredom;
    void PassTime(int time = 1);
};

Critter::Critter(int hunger, int boredom, int thirst) :
    m_Hunger(hunger),
    m_Thirst(thirst),
    m_Boredom(boredom)
{}


void Critter::PassTime(int time)
{
    m_Hunger += time;
    m_Thirst += time;
    m_Boredom += time;
}

void Critter::Talk()
{
    /*Implementar código
    */
    if (m_Hunger < 5 || m_Thirst < 5 || m_Boredom < 5)
    {
        cout << "Estoy muy bien, humano" << endl;
    }
    else if (m_Hunger >= 5 && m_Hunger <= 10 || m_Thirst >= 5 && m_Thirst <= 10 || m_Boredom >= 5 && m_Boredom <= 10)
    {
        cout << "Estoy bien, humano" << endl;
    }
    else if (m_Hunger > 10 && m_Hunger <= 13 || m_Thirst > 10 && m_Thirst <= 13 || m_Boredom > 10 && m_Boredom <= 13)
    {
        cout << "me siento mal, humano" << endl;
        if (m_Hunger >= 10 && m_Hunger <= 13)
        {
            cout << "Dame de comer, me estoy muriendo de hambre" << endl;
        }
        if (m_Thirst >= 10 && m_Thirst <= 13)
        {
            cout << "Dame de beber, me estoy muriendo de sed" << endl;
        }
        if (m_Boredom > 10 && m_Boredom <= 13)
        {
            cout << "que la cancion!!! juega conmigo!!!" << endl;
        }
    }
    else if (m_Hunger == 14 || m_Thirst == 14 || m_Boredom == 14)
    {
        cout << "me voy a morir!!!" << endl;
        if (m_Hunger == 14)
        {
            cout << "Dame de comer, me estoy muriendo de hambre" << endl;
        }
        if (m_Thirst == 14)
        {
            cout << "Dame de beber, me estoy muriendo de sed" << endl;
        }
        if (m_Boredom == 14)
        {
            cout << "que la cancion!!! juega conmigo!!!" << endl;
        }
    }
    else if (m_Hunger == 15 || m_Thirst == 15 || m_Boredom == 15)
    {
        cout << "Ya me mori, bye humano menso" << endl;
        exit(-1);
    } 

    cout << "Hambre: " << m_Hunger << endl;
    cout << "Sed: " << m_Thirst << endl;
    cout << "Aburrimiento: " << m_Boredom << endl << endl;
    PassTime();
}

void Critter::Eat(int food)
{
    cout << "\nBrrupp. \n";
    m_Hunger -= food;
    if (m_Hunger < 0)
    {
        m_Hunger = 0;
    }
    PassTime();
}

void Critter::Drink(int water)
{
    cout << "\nGlu Glu Glu. \n";
    m_Thirst -= water;
    if (m_Thirst < 0)
    {
        m_Thirst = 0;
    }
    PassTime();
}

void Critter::Play(int fun)
{
    cout << "\nWheee!\n";
    m_Boredom -= fun;
    if (m_Boredom < 0)
    {
        m_Boredom = 0;
    }
    PassTime();
}

int main()
{
    int option;
    cout << "que parte del examen te gustaria ver: " << endl << "1.Punteros" << endl << "2.Mi mascota" << endl;
    cin >> option;
    switch (option)
    {
    case 1:
        Punteros();
        break;
    case 2:
        MiMascota();
        break;
    }
}

void MiMascota()
{
    Critter crit;
    crit.Talk();
    int choice;
    do
    {
        cout << "\n Mascotas Virtuales\n\n";
        cout << "0 - Salir.\n";
        cout << "1 - Escucha a tu mascota.\n";
        cout << "2 - Alimentar.\n";
        cout << "3 - Dar de beber agua.\n";
        cout << "4 - Jugar con tu mascota.\n";
        cout << "Elige una opción: ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << "Vuelve pronto!.\n";
            break;
        case 1:
            crit.Talk();
            break;
        case 2:
            crit.Eat();
            break;
        case 3:
            crit.Drink();
            break;
        case 4:
            crit.Play();
            break;
        default:
            cout << "\n Tu elección es inválida. \n";
        }
    } while (choice != 0);
    return;
}

void Punteros()
{
    std::vector<int> numbers(8);
    determinar(numbers);

    int* largestEvenDigitsNumberPtr = &numbers[findLargestEvenDigitsIndex(numbers)];

    std::cout << "The number with the largest number of even digits is: " << *largestEvenDigitsNumberPtr << std::endl;
    std::cout << "Memory address of the number: " << largestEvenDigitsNumberPtr << std::endl;
    std::cout << "Position of the number in the vector: " << largestEvenDigitsNumberPtr - &numbers[0] << std::endl;

    return;
    
}

void determinar(std::vector<int>& numbers)
{
    std::cout << "Enter 8 numbers:\n";
    for (int i = 0; i < 8; ++i) {
        std::cin >> numbers[i];
    }
}


int countEvenDigits(int number) {
    int count = 0;
    while (number != 0) {
        int digit = number % 10;
        if (digit % 2 == 0) {
            ++count;
        }
        number /= 10;
    }
    return count;
}


int findLargestEvenDigitsIndex(const std::vector<int>& numbers) {
    int maxEvenDigits = -1;
    int index = -1;

    for (size_t i = 0; i < numbers.size(); ++i) {
        int evenDigitsCount = countEvenDigits(numbers[i]);
        if (evenDigitsCount > maxEvenDigits) {
            maxEvenDigits = evenDigitsCount;
            index = i;
        }
    }

    return index;
}

