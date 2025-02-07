#include "Utils.h"

using namespace std;

char Utils::getCharacter(){
    string input = "";
    char sign = { 0 };

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            sign = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return sign;
};
string Utils::readLine(){
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
};
bool Utils::validateInput(string input){
    return 1;
}
double Utils::getValidatedAmount(){
    string amountStr;

    cout << "Podaj kwote: ";
    amountStr = Utils::readLine();
    replace(amountStr.begin(), amountStr.end(), ',', '.');

    try {
        return stod(amountStr);
    } catch (const invalid_argument& e) {
        cerr << "Blad: Niepoprawna kwota!" << endl;
        return 0.0;
    }
}
