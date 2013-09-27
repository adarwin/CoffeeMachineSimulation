/* Andrew Darwin
 * www.adarwin.com
 * Fall 2013
 * CSC 454: System Simulation
 */

#include <iostream>
#include "CVMState.h"
#include <string>
#include <sstream>

using std::string;
using std::endl;
using std::stringstream;
namespace com_adarwin_simulation {
    CVMState::CVMState() {
    }

    CVMState::CVMState(int nickels, int dimes, int quarters) :
                       totalNickels(nickels), totalDimes(dimes),
                       totalQuarters(quarters), currentNickels(0),
                       currentDimes(0), currentQuarters(0),
                       changeSelected(false) {}

    int CVMState::getCurrentNickels() {
        return currentNickels;
    }
    int CVMState::getCurrentDimes() {
        return currentDimes;
    }
    int CVMState::getCurrentQuarters() {
        return currentQuarters;
    }
    bool CVMState::isChangeSelected() {
        return changeSelected;
    }
    bool CVMState::isWaiting() {
        return waiting;
    }
    void CVMState::incrementCurrentNickels() {
        currentNickels++;
    }
    void CVMState::incrementCurrentDimes() {
        currentDimes++;
    }
    void CVMState::incrementCurrentQuarters() {
        currentQuarters++;
    }
    void CVMState::setChangeSelected(bool value) {
        changeSelected = value;
    }
    void CVMState::setWaiting(bool value) {
        waiting = value;
    }
    int CVMState::getTotalCents() {
        return 5*totalNickels + 10*totalDimes + 25*totalQuarters;
    }
    int CVMState::getCurrentCents() {
        return 5*currentNickels + 10*currentDimes + 25*currentQuarters;
    }
    bool CVMState::moveCentsToTotalStorage(int cents) {
        return moveCurrentCents(cents, true);
    }
    bool CVMState::removeCents(int cents) {
        return moveCurrentCents(cents, false);
    }

    bool CVMState::moveCurrentCents(int cents, bool toMainStorage) {
        while (cents >= 25 && currentQuarters > 0) {
            cents -= 25;
            currentQuarters--;
            if (toMainStorage) totalQuarters++;
        }
        while (cents >= 10 && currentDimes > 0) {
            cents -= 10;
            currentDimes--;
            if (toMainStorage) totalDimes++;
        }
        while (cents >= 5 && currentNickels > 0) {
            cents -= 5;
            currentNickels--;
            if (toMainStorage) totalNickels++;
        }
        if (cents > 0) {
            return false;
        } else {
            return true;
        }
    }
    int CVMState::numDigits(int number) {
        int numDigits = 0;
        if (number == 0) numDigits++;
        while (number > 0) {
            number /= 10;
            numDigits++;
        }
        return numDigits;
    }
    string CVMState::getRightPadding(string inputString, int totalSpace) {
        stringstream ss;
        int stringSize = inputString.size();
        for (int i = totalSpace-stringSize; i > 0; i--) {
            ss << " ";
        }
        return ss.str();
    }
    string CVMState::getStringLine(string coinType, int current, int total) {
        stringstream ss, currentSS, totalSS;
        currentSS << coinType << current;
        string currentString = currentSS.str();
        totalSS << coinType << total;
        string totalString = totalSS.str();

        ss << "| " << currentString << getRightPadding(currentString, 19);
        ss << " | " << totalString << getRightPadding(totalString, 19);
        ss << " |" << endl;
        /*
        int stringSize = coinType.size();
        ss << "| " << coinType << current;
        int digits = numDigits(current);
        for (int i = 19-stringSize; i > digits; i--) {
            ss << " ";
        }
        ss <<                      " | " << coinType << total;
        digits = numDigits(total);
        for (int i = 19-stringSize; i > digits; i--) {
            ss << " ";
        }
        ss <<                                          " |" << endl;
        */
        return ss.str();
    }
    string CVMState::getString() {
        stringstream ss;
        ss << " ------------------------------------------- " << endl;
        ss << "|------------ Simulation State -------------|" << endl;
        ss << "|-------------------------------------------|" << endl;
        if (isChangeSelected()) {
        ss << "|                                           |" << endl;
        ss << "|       -----------------------------       |" << endl;
        ss << "|     /-------------------------------\\     |" << endl;
        ss << "|    |-------- Change Selected --------|    |" << endl;
        ss << "|     \\-------------------------------/     |" << endl;
        ss << "|       -----------------------------       |" << endl;
        ss << "|                                           |" << endl;
        } else {
        ss << "|                                           |" << endl;
        ss << "|                                           |" << endl;
        ss << "|                                           |" << endl;
        ss << "|            Change Not Selected            |" << endl;
        ss << "|                                           |" << endl;
        ss << "|                                           |" << endl;
        ss << "|                                           |" << endl;
        }
        ss << "|-------------------------------------------|" << endl;
        ss << "| Transaction Storage |   Master Storage    |" << endl;
        ss << "|---------------------|---------------------|" << endl;
        ss << "|                     |                     |" << endl;
        int currentCents = getCurrentCents();
        int totalCents = getTotalCents();
        stringstream currentCentsStream, totalCentsStream;
        currentCentsStream << "$" << (double)currentCents/100;
        totalCentsStream <<   "$" << (double)totalCents/100;
        string currentCentsString = currentCentsStream.str();
        string totalCentsString = totalCentsStream.str();
        ss << "| " << currentCentsString
           << getRightPadding(currentCentsString, 19);
        ss << " | " << totalCentsString
           << getRightPadding(totalCentsString, 19);
        ss << " |" << endl;
        // Pad

        ss << getStringLine("Quarters: ", currentQuarters, totalQuarters);
        ss << getStringLine("Dimes:    ", currentDimes, totalDimes);
        ss << getStringLine("Nickels:  ", currentNickels, totalNickels);
        ss << "|                     |                     |" << endl;
        ss << " ------------------------------------------- " << endl;
        return ss.str();
    }
}
